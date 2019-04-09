#include "Gui.h"
#include "Filter.h"
Gui::Gui(Repo repo, QWidget *parent) : repo{repo}, QWidget(parent)
{
	ui.setupUi(this);
	reloadList();
	QObject::connect(ui.AddButton,&QPushButton::clicked,this,&Gui::addV);
	QObject::connect(ui.UpdateButton,&QPushButton::clicked,this,&Gui::updateV);
	QObject::connect(ui.ClearButton,&QPushButton::clicked,this,&Gui::clear);
	QObject::connect(ui.FilterButton,&QPushButton::clicked,this,&Gui::filterV);
	QObject::connect(ui.ListWidget, &QListWidget::itemSelectionChanged, [&]()
	{
		if (ui.ListWidget->selectedItems().isEmpty())
		{
			ui.NameEdit->setText("");
			ui.HeightEdit->setText("");
			ui.CityEdit->setText("");
			return;
		}
		QListWidgetItem* selected = ui.ListWidget->selectedItems().at(0);
		QString name = selected->text();
		ui.NameEdit->setText(name);
		Volcano v = this->repo.findV(name.toStdString());
		ui.HeightEdit->setText(QString::number(v.getHeight()));
		ui.CityEdit->setText(QString::fromStdString(v.getCity()));
	});
}

Gui::~Gui()
{
}
void Gui::addV()
{
	std::string name, city;
	double height;
	name = ui.NameEdit->text().toStdString();
	height = ui.HeightEdit->text().toDouble();
	city = ui.CityEdit->text().toStdString();
	Volcano v{ name,height,city };
	this->repo.add(v);
	reloadList();
}
void Gui::updateV()
{
	std::string name, city;
	double height;
	name = ui.NameEdit->text().toStdString();
	height = ui.HeightEdit->text().toDouble();
	city = ui.CityEdit->text().toStdString();
	this->repo.update(name, height, city);
	reloadList();
}
void Gui::filterV()
{
	Filter* newWindow = new Filter{this->repo};
	newWindow->show();
}
void Gui::reloadList()
{
	std::vector<Volcano> volcanoes = this->repo.getVolcanoes();
	ui.ListWidget->clear();
	for (auto v : volcanoes)
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(v.getName()),ui.ListWidget);
}
void Gui::clear()
{
	ui.NameEdit->setText("");
	ui.HeightEdit->setText("");
	ui.CityEdit->setText("");
}