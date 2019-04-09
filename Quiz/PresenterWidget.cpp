#include "PresenterWidget.h"
#include <sstream>
#include <QMessageBox>
using namespace std;
PresenterWidget::PresenterWidget(Controller& control, QWidget *parent)
	: control(control), QWidget(parent)
{
	ui.setupUi(this);	
	this->control.registerObserver(this);
	this->setWindowTitle(QString::fromStdString("Presenter"));
	this->populateList();
	QObject::connect(this->ui.AddButton, &QPushButton::clicked, this, &PresenterWidget::addQ);

}

PresenterWidget::~PresenterWidget()
{
}
void PresenterWidget::populateList()
{
	ui.questListWidget->clear();
	std::vector<Question> quest = this->control.getQ();
	sort(quest.begin(), quest.end(), [](Question a, Question b) {return a.getId() < b.getId(); });
	for (auto q : quest) 
	{
		QListWidgetItem*item = new QListWidgetItem;
		stringstream buffer;
		buffer << q.getId() << " " << q.getText() << " " << q.getCorrect() << " " << q.getScore();
		std:string text = buffer.str();
		item->setText(QString::fromStdString(text));
		ui.questListWidget->addItem(item);
		
	}
}
void PresenterWidget::addQ()
{
	try {
		std::string answer, quest;
		int score, id;
		id = ui.IdEdit->text().toInt();
		score = ui.ScoreEdit->text().toInt();
		quest = ui.QuestionEdit->text().toStdString();
		answer = ui.AnswerEdit->text().toStdString();
		if (quest == "")
			throw std::exception("empty quest");
		this->control.addQuest(id, quest, answer, score);
	}
	catch (std::exception &e) {
		QMessageBox m;
		m.critical(this, "error", e.what());
	}
}
