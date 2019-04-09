#include "Gui.h"

Gui::Gui(Repo repo, QWidget *parent)
	:repo{repo},  QWidget(parent)
{
	ui.setupUi(this);
	QTableWidgetItem* nr = new QTableWidgetItem(QString::fromStdString("Nr"));		
	ui.TableWidget->setColumnCount(2);
	reloadTable();
	QObject::connect(ui.AddButton, &QPushButton::clicked, this, &Gui::addF);
	QObject::connect(ui.RemoveButton, &QPushButton::clicked, this, &Gui::removeF);	
	
}

Gui::~Gui()
{
}
void Gui::reloadTable()
{
	std::vector<Fragrance> fr = this->repo.getFrag();
	ui.TableWidget->clear();
	int pos = 0;
	ui.TableWidget->setRowCount(fr.size());
	ui.TableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
	ui.TableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Price"));
	for (auto f : fr)
	{
		QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdString(f.getName()));
		QTableWidgetItem* price = new QTableWidgetItem(QString::number(f.getPrice()));
		ui.TableWidget->setItem(pos,0,item);
		ui.TableWidget->setItem(pos, 1, price);
		pos = pos + 1;
	}

}
void Gui::addF()
{
	std::string name;
	double price;
	name = ui.NameEdit->text().toStdString();
	price = ui.PriceEdit->text().toDouble();
	Fragrance f{ name,price };
	this->repo.add(f);
	reloadTable();
	clearBoxes();
}
void Gui::clearBoxes()
{
	ui.NameEdit->setText("");
	ui.PriceEdit->setText("");
}
void Gui::removeF()
{
	std::string name;
	QTableWidgetItem* selected = ui.TableWidget->selectedItems().at(0);
	name = selected->text().toStdString();
	this->repo.remove(name);
	reloadTable();
}
