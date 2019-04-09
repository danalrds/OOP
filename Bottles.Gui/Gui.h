#pragma once

#include <QWidget>
#include "ui_Gui.h"
#include "Repo.h"
class Gui : public QWidget
{
	Q_OBJECT

private:
	Repo repo;
	Ui::Gui ui;
public:
	Gui(Repo repo, QWidget *parent = Q_NULLPTR);
	~Gui();
	void addB();
	void removeB();
	void reloadList();
	void clearBoxes();
};
