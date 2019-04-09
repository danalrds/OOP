#include "Gui.h"

Gui::Gui(Repo repo,QWidget *parent) : repo{repo},QWidget(parent)
{
	ui.setupUi(this);
	reloadList();
	QObject::connect(ui.AddButton, &QPushButton::clicked, this, &Gui::addB);
	QObject::connect(ui.RemoveButton, &QPushButton::clicked, this, &Gui::removeB);
	QObject::connect(ui.ListWidget, &QListWidget::itemSelectionChanged, [&]()
	{
		if (ui.ListWidget->selectedItems().isEmpty()) {
			ui.NameEdit->setText("");
			ui.PriceEdit->setText("");
			ui.CountryEdit->setText("");
			return;
		}
		QListWidgetItem* selected = ui.ListWidget->selectedItems().at(0);
		QString name = selected->text();
		ui.NameEdit->setText(name);
		int pos = this->repo.find(name.toStdString());
		if (pos != -1)
		{
			Bottle b = this->repo.findBottle(name.toStdString());
			ui.PriceEdit->setText(QString::number(b.getPrice()));
			ui.CountryEdit->setText(QString::fromStdString(b.getCountry()));			
		}
	});
	QObject::connect(ui.ClearButton, &QPushButton::clicked, this, &Gui::clearBoxes);
}
void Gui::clearBoxes()
{
	ui.NameEdit->setText("");
	ui.PriceEdit->setText("");
	ui.CountryEdit->setText("");
	return;
}

Gui::~Gui()
{
}
void Gui::addB()
{
	std::string name, country;
	double price;
    name = ui.NameEdit->text().toStdString();
	price = ui.PriceEdit->text().toDouble();
	country = ui.CountryEdit->text().toStdString();
	Bottle b{ name,price,country };
	this->repo.add(b);
	reloadList();
}
void Gui::removeB()
{
	std::string name;
	name = ui.NameEdit->text().toStdString();
	Bottle b = this->repo.findBottle(name);
	std::vector<Bottle> bottles = this->repo.getBottles();
	for (int i =0;i< bottles.size();i++)
	{
		if (bottles[i].getName() == name)
		{
			ui.ListWidget->item(i)->setBackground(Qt::green);
		}
		else
		{
			QFont font{};
			font.setBold(true);
			ui.ListWidget->item(i)->setFont(font);
		}
	}
//	this->repo.remove(b);
//	reloadList();
}
void Gui::reloadList()
{
	std::vector<Bottle> bottles = this->repo.getBottles();
	ui.ListWidget->clear();
	for (const auto& b : bottles) {
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(b.getName()), ui.ListWidget);
	}
}