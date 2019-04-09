#include "PresenterWidget.h"
#include <QListWidgetItem>
#include <sstream>
using namespace std;
PresenterWidget::PresenterWidget(Controller& control, QWidget *parent)
	:control{control}, QWidget(parent)
{
	ui.setupUi(this);
	this->control.registerObserver(this);
	this->populateList();
}

PresenterWidget::~PresenterWidget()
{
}
void PresenterWidget::populateList()
{
	this->ui->PListWidget.clear;
	std::vector<Question> quest = this->control.getQ();
	for (auto q : quest)
	{
		stringstream buffer;
		buffer << q.getId() << " " << q.getText() << " " << q.getCorrect() << " " << q.getScore();
		QListWidgetItem* item = new QListWidgetItem;
		item->setText(QString::fromStdString(buffer.str()));
		ui.PListWidget->addItem(item);
	}
}
