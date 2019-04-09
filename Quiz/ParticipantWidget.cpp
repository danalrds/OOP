#include "ParticipantWidget.h"
#include <sstream>
using namespace std;
ParticipantWidget::ParticipantWidget(Controller& control, Participant& p, QWidget *parent)
	: control(control), participant(p),  QWidget(parent)
{	
	this->score = 0;	
	ui.setupUi(this);
	this->control.registerObserver(this);	
	this->populateList();
	this->ui.ScoreEdit->setText(QString::number(p.getScore()));
	QObject::connect(this->ui.AnswerButton, &QPushButton::clicked, this, &ParticipantWidget::answer);
	QObject::connect(this->ui.PquestListWidget, &QListWidget::itemSelectionChanged, this, &ParticipantWidget::enableButtons);
	this->setWindowTitle(QString::fromStdString(p.getName()));
}

ParticipantWidget::~ParticipantWidget()
{
}


vector<string> tokenize2(const string& str, char delimiter)
{
	vector <string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}


void ParticipantWidget::populateList()
{
	
	std::string name = participant.getName();
	ui.PquestListWidget->clear();
	std::vector < Question > quest= this->control.getQ();
	sort(quest.begin(), quest.end(), [](Question a, Question b) {return a.getScore() > b.getScore(); });
	for (auto q : quest)
	{
		QListWidgetItem*item = new QListWidgetItem;
		stringstream buffer;
		buffer << q.getId() << " " << q.getText() << " " << q.getScore();
	    std:string text = buffer.str();
		item->setText(QString::fromStdString(text));
		ui.PquestListWidget->addItem(item);
		int pos = -1;
		for (int i = 0; i < this->answered.size(); i++)
			if (this->answered[i] == q.getId())
				pos = i;
		if (pos != -1)
			item->setBackgroundColor(Qt::green);
	}
}


void ParticipantWidget::answer()
{
	std::string answer;
	std::vector<Question> q = this->control.getQ();	
	answer = ui.answerEdit->text().toStdString();	
	QListWidgetItem* selected = ui.PquestListWidget->selectedItems().at(0);
	std::vector<std::string> tokens = tokenize2(selected->text().toStdString(), ' ');
	int id = stoi(tokens[0]);	
	this->answered.push_back(id);
	selected->setBackgroundColor(Qt::green);
	for (auto t : q)
		if (t.getId()==id)
			if (t.getCorrect() == answer)
			{
				this->score = this->score + t.getScore();
				this->ui.ScoreEdit->setText(QString::number(this->score));
				break;
			}		
}

int ParticipantWidget::getSelectedIndex()
{
	if (this->control.getQ().size() == 0)return -1;
	QModelIndexList index = this->ui.PquestListWidget->selectionModel()->selectedIndexes();
	if (index.size() == 0)return -1;
	int idx = index.at(0).row();
	return idx;
}



void ParticipantWidget::enableButtons()
{
	
		std::string name = participant.getName();
		std::string row = this->ui.PquestListWidget->currentItem()->text().toStdString();		
		std::vector<std::string> tokens = tokenize2(row, ' ');
		int id = stoi(tokens[0]);
		int pos = -1;
		for (int i = 0; i < this->answered.size(); i++)
			if (this->answered[i] == id)
				pos = i;

		if (pos == -1)
			ui.AnswerButton->setEnabled(true);
		else
		{
			
			ui.AnswerButton->setEnabled(false);
		}
	
}