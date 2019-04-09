#include "Gui.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <QtWidgets/QMessageBox>
using namespace std;

Gui::Gui(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.TryButton, &QPushButton::clicked, this, &Gui::try1);
	QObject::connect(ui.TryButton2, &QPushButton::clicked, this, &Gui::try2);
	QObject::connect(ui.ChangeButton, &QPushButton::clicked, this, &Gui::change1);
	QObject::connect(ui.ChangeButton2, &QPushButton::clicked, this, &Gui::change2);
	ifstream file("words.txt");	
	std::string line;
	this->turn = 1;
	getline(file, line);
	this->cuvinte.push_back("prelegume"); this->cuvinte.push_back("legume");
	this->cuvinte.push_back("premere");    this->cuvinte.push_back("mere");
	this->cuvinte.push_back("preactivitate");	this->cuvinte.push_back("activitate");
	
	int n = rand() % this->cuvinte.size();
	this->cuvant = this->cuvinte[5];
	stringstream buffer;
	for (int i = 0; i < this->cuvant.size(); i++)
		buffer << "_";
	this->cuv = buffer.str();	
	file.close();
	this->points1 = 0;
	this->points2 = 0;
	ui.PointsEdit->setText(QString::number(0));
	ui.PointsEdit2->setText(QString::number(0));
	reload();
	
}
int Gui::Won()
{
	std::string lit = "_";
	int gasit = 0;
	for (int i = 0; i < this->cuv.size(); i++)
		if (this->cuv[i] == lit[0])
			gasit = 1;
	if (gasit == 0)
		return 1;
	else
		return 0;
}

Gui::~Gui()
{
}
void Gui::try1()
{
	int ok = 0;
	//type = ui.TypeEdit->text().toStdString();	
	//surface = ui.SurfaceEdit->text().toDouble();
	if (this->turn == 1)
	{
		stringstream buffer;
		int pos = ui.PosEdit->text().toInt();
		std::string letter = ui.LetterEdit->text().toStdString();
		std::string lit = "_";
		for (int i = 0; i < this->cuvant.size(); i++)
			if (this->cuvant[i] == letter[0])
			{
				ok = 1;
				this->cuv[i] = this->cuvant[i];
				this->points1 = this->points1 + 1;
				break;
			}
		this->turn = 2;
		reload();
		if (this->Won()==1)
			QMessageBox::warning(this, "Game won!", QString::fromStdString("Player 1 has won!"));
		if (ok==0)			
				QMessageBox::warning(this, "Incorrect!", QString::fromStdString("the letter is not ok!"));
	}

}
void Gui::try2()
{
	if (this->turn == 2)
	{
		int ok = 0;
		stringstream buffer;
		int pos = ui.PosEdit2->text().toInt();
		std::string letter = ui.LetterEdit2->text().toStdString();
		std::string lit = "_";
		for (int i = 0; i < this->cuvant.size(); i++)
			if (this->cuvant[i] == letter[0])
			{
				ok = 1;
				this->cuv[i] = this->cuvant[i];
				this->points2 = this->points2 + 1;
				break;
			}
		this->turn = 1;
		reload();
		if (this->Won() == 1)
			QMessageBox::warning(this, "Game won!", QString::fromStdString("Player 2 has won!"));
		if (ok == 0)
			QMessageBox::warning(this, "Incorrect!", QString::fromStdString("the letter is not ok!"));
	}
}
void Gui::change1()
{
	if (this->turn == 1)
	{
		std::string prefix, cuvnou;
		prefix = ui.PrefEdit->text().toStdString();
		int ok = 0;
		stringstream buff;
		buff << prefix << this->cuvant;
		cuvnou = buff.str();
		for (int i = 0; i < this->cuvinte.size(); i++)
			if (cuvnou == this->cuvinte[i])
				ok = 1;
		if (ok == 1)
		{
			this->cuvant = cuvnou;
			stringstream buffer;
			for (int i = 0; i < prefix.size(); i++)
				buffer << "_";
			for (int i = 0; i < this->cuv.size(); i++)
				buffer << this->cuv[i];
			this->cuv = buffer.str();
			reload();
		}
		this->turn = 2;
	}
}
void Gui::change2()
{
	if (this->turn == 2)
	{
		std::string prefix, cuvnou;
		prefix = ui.PrefEdit2->text().toStdString();
		int ok = 0;
		stringstream buff;
		buff << prefix << this->cuvant;
		cuvnou = buff.str();
		for (int i = 0; i < this->cuvinte.size(); i++)
			if (cuvnou == this->cuvinte[i])
				ok = 1;
		if (ok == 1)
		{
			this->cuvant = cuvnou;
			stringstream buffer;
			for (int i = 0; i < prefix.size(); i++)
				buffer << "_";
			for (int i = 0; i < this->cuv.size(); i++)
				buffer << this->cuv[i];
			this->cuv = buffer.str();
			reload();
		}
		this->turn = 1;
	}
}
void Gui::reload()
{
	stringstream buffer;
	for (int i = 0; i < this->cuv.size(); i++)
		buffer << this->cuv[i] << " ";
	std::string asta = buffer.str();
	ui.WordEdit->setText(QString::fromStdString(asta));
	ui.WordEdit2->setText(QString::fromStdString(asta));
	ui.PointsEdit->setText(QString::number(this->points1));
	ui.PointsEdit2->setText(QString::number(this->points2));
}
