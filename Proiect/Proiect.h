#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Proiect.h"

class Proiect : public QMainWindow
{
	Q_OBJECT

public:
	Proiect(QWidget *parent = Q_NULLPTR);

private:
	Ui::ProiectClass ui;
};
