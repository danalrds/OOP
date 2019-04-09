#include "Quiz.h"
#include <QtWidgets/QApplication>
#include "Repo.h"
#include <Classes.h>
#include <assert.h>
#include "Controller.h"
#include "PresenterWidget.h"
#include "ParticipantWidget.h"
void testQ()
{
	Question q{ 1,"question1", "correct", 8 };
	assert(q.getId() == 1);
	assert(q.getText() == "question1");
	assert(q.getCorrect() == "correct");
	assert(q.getScore() == 8);
}
void testRepo()
{
	Repo repo;
	assert(repo.getQ().size() == 4);
	assert(repo.getP().size()== 3);
	assert(repo.getQ()[0].getText()=="question1");
	assert(repo.getQ()[1].getText() == "question2");
	assert(repo.getQ()[2].getText() == "question3");
	assert(repo.getQ()[3].getText() == "question4");
	Question q{ 8,"question8", "correct", 8 };
	repo.add(q);
	assert(repo.getQ().size() == 5);
	Question q2{ 9,"question8", "correct", 8 };
	Question q3{ 10,"question8", "correct", 8 };
	repo.add(q2);
	repo.add(q3);
	assert(repo.getQ().size() == 7);
	////////////////////////////////////////////update
	repo.update("Ionica", 11);
	int pos = repo.findPar("Ionica");
	assert(repo.getP()[pos].getScore() == 11);
	repo.update("Ionica", 12);
	assert(repo.getP()[pos].getScore() == 23);
	repo.update("Gergely", 11);
	pos = repo.findPar("Gergely");
	assert(repo.getP()[pos].getScore() == 11);
	repo.update("Gergely", 12);
	assert(repo.getP()[pos].getScore() == 23);

}
void testController()
{
	Repo repo;
	Controller control(repo);
	assert(control.getP().size() == 3);
	//assert(control.getQ().size() == 4);
	Question q{ 8,"question8", "correct", 8 };
	Question q2{ 9,"question8", "correct", 8 };
	Question q3{ 10,"question8", "correct", 8 };
	control.addQuest(8, "question8", "correct", 8);
	assert(control.getQ().size() == 5);
	control.addQuest(9, "question8", "correct", 8);
	assert(control.getQ().size() == 6);
	control.addQuest(10, "question8", "correct", 8);
	assert(control.getQ().size() == 7);
	///////updateScore functionallity
	control.updateScore("Ionica", 7);
	int pos = control.findPart("Ionica");
	assert(control.getP()[pos].getScore() == 7);
	control.updateScore("Ionica", 9);
	assert(control.getP()[pos].getScore() == 16);
	control.updateScore("Gergely", 11);
	pos = control.findPart("Gergely");
	assert(control.getP()[pos].getScore() == 11);
	repo.update("Gergely", 12);
	assert(control.getP()[pos].getScore() == 23);

}
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	testQ();
	testRepo();
	testController();
	Repo repo;
	Controller control(repo);
	PresenterWidget* pres = new PresenterWidget(control);
	pres->show();
	for (auto p : repo.getP()) {
		ParticipantWidget*participant = new ParticipantWidget(control, p);
		participant->show();
	}
	a.exec();
	repo.printToFile();
	return 0;
}


