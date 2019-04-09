#include "developerWidget.h"
#include"WritingSession.h"
developerWidget::developerWidget(WritingSession&s, std::string i, QWidget * parent) : QWidget(parent), idea(i), session(s) {
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(idea));
	this->ui.textEdit->setText(QString::fromStdString(idea));
	QObject::connect(this->ui.saveButton, &QPushButton::clicked, this, &developerWidget::updateIdea);
}

developerWidget::~developerWidget() {

}

void developerWidget::updateIdea()
{
	QString newtext = this->ui.textEdit->text();
	std::string text = newtext.toStdString();
	if (text != "") {
		std::string fname = idea + ".txt";
		std::ofstream f("developed.txt");
		if (!f.is_open())return;
		f << text;



	}
}
