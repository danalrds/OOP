#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ProjectT.h"

class ProjectT : public QMainWindow
{
	Q_OBJECT

public:
	ProjectT(QWidget *parent = Q_NULLPTR);

private:
	Ui::ProjectTClass ui;
};
