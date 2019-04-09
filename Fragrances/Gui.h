#pragma once

#include <QWidget>
#include "ui_Gui.h"
#include "Fragrance.h"
#include "Repo.h"
class Gui : public QWidget
{
	Q_OBJECT

public:
	Gui(Repo repo, QWidget *parent = Q_NULLPTR);
	~Gui();
	void reloadTable();
	void addF();
	void removeF();
	void clearBoxes();
private:
	Ui::Gui ui;
	Repo repo;
};
