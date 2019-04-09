#include "Gui.h"
#include <fstream>
Gui::Gui(Repo repo, QWidget *parent) : repo{repo}, QWidget(parent)
{
	ui.setupUi(this);
	reloadList();
	QObject::connect(ui.AddButton, &QPushButton::clicked, this, &Gui::addW);
	QObject::connect(ui.RemoveButton,&QPushButton::clicked, this, &Gui::removeW);
	QObject::connect(ui.UpdateButton, &QPushButton::clicked, this, &Gui::updateW);
	QObject::connect(ui.ClearButton, &QPushButton::clicked, this, &Gui::clear);
	QObject::connect(ui.SurfaceButton, &QPushButton::clicked, this, &Gui::computeS);
	QObject::connect(ui.CSVButton, &QPushButton::clicked, this, &Gui::Csv);
	QObject::connect(ui.UndoButton, &QPushButton::clicked, this, &Gui::undo);
	QObject::connect(ui.ListWidget, &QListWidget::itemSelectionChanged, [&]()
	{
		if (ui.ListWidget->selectedItems().isEmpty())
		{
			ui.NameEdit->setText("");
			ui.SurfaceEdit->setText("");
			ui.OldEdit->setText("");
			return;
		}
		QListWidgetItem* selected = ui.ListWidget->selectedItems().at(0);
		QString name = selected->text();
		ui.NameEdit->setText(name);
		Water* w = this->repo.findW(name.toStdString());
		ui.SurfaceEdit->setText(QString::number(w->getSurf()));
		ui.OldEdit->setText(QString::fromStdString(w->getOld()));
	});
}

Gui::~Gui()
{
}

void Gui::reloadList()
{
	ui.ListWidget->clear();
	std::vector<Water*> waters = this->repo.getWaters();
	for (auto w : waters)
	{
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(w->getName()),ui.ListWidget);
	}
}

void Gui::addW()
{
	std::string name, old,type;
	double surface;
	int ok;
	type = ui.TypeEdit->text().toStdString();
	name = ui.NameEdit->text().toStdString();
	old = ui.OldEdit->text().toStdString();
	surface = ui.SurfaceEdit->text().toDouble();
	if (type == "see")
	{
		Water* w = new See{ name, surface,old };
		ok=this->repo.add(w);
		if (ok==1)
			undoActions.push_back(std::make_unique<UndoAdd>(repo, w));
	}
	if (type == "ocean")
	{
		Water* w = new Ocean{ name, surface,old };
		ok=this->repo.add(w);
		if (ok == 1)
			undoActions.push_back(std::make_unique<UndoAdd>(repo, w));
	}
	if (ok==-1)
		QMessageBox::warning(this, "Warning", QString::fromStdString("already in repo!"));
	reloadList();
}

void Gui::removeW()
{
	std::string name;
	name = ui.NameEdit->text().toStdString();
	Water* w = this->repo.findW(name);
	this->repo.remove(w);	
	undoActions.push_back(std::make_unique<UndoRemove>(repo, w));
	reloadList();
}

void Gui::updateW()
{
	std::string name, type, old;
	double surface;
	type = ui.TypeEdit->text().toStdString();
	name = ui.NameEdit->text().toStdString();
	old = ui.OldEdit->text().toStdString();
	surface = ui.SurfaceEdit->text().toDouble();
	if (type == "see")
	{
		Water* w = new See{ name, surface,old };		
		Water* w2 = this->repo.findW(name);
		undoActions.push_back(std::make_unique<UndoUpdate>(repo, w2));
		this->repo.update(w);
	}
	if (type == "ocean")
	{
		Water* w = new Ocean{ name, surface,old };	
		//Water* w2 = this->repo.findW(name);
		//undoActions.push_back(std::make_unique<UndoUpdate>(repo, w2));
		this->repo.update(w);
	}	
	reloadList();
}
void Gui::clear()
{
	ui.TypeEdit->setText("");
	ui.NameEdit->setText("");
	ui.SurfaceEdit->setText("");
	ui.OldEdit->setText("");
}
void Gui::computeS()
{
	double s = this->repo.compute();
	ui.ComputeEdit->setText(QString::number(s));
}
void Gui::Csv()
{
	this->repo.writeToFile();
}
void Gui::undo()
{
	if (undoActions.empty()==false)	
	{
		undoActions.back()->doundo();
		undoActions.pop_back();
	}
	reloadList();
}