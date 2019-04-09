#pragma once

#include <QWidget>
#include "ui_Gui.h"
#include "Repo.h"
class Gui : public QWidget
{
	Q_OBJECT

public:
	Gui(Repo repo, QWidget *parent = Q_NULLPTR);
	~Gui();
	void addV();
	void updateV();
	void reloadList();
	void clear();
	void filterV();

private:
	Repo repo;
	Ui::Gui ui;
};
