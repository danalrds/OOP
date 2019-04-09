#pragma once

#include <QWidget>
#include "ui_Gui.h"
#include <vector>
class Gui : public QWidget
{
	Q_OBJECT

public:
	Gui(QWidget *parent = Q_NULLPTR);
	~Gui();
	std::vector<std::string> getCuvinte() const { return cuvinte; }
	int points1;
	int points2;
	std::string cuvant;
	std::string cuv;
	int turn;
	void reload();
	void try1();
	void try2();
	void change1();
	void change2();
	int Won();
private:
	Ui::Gui ui;
	std::vector<std::string> cuvinte;
};
