#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Fragrances.h"

class Fragrances : public QMainWindow
{
	Q_OBJECT

public:
	Fragrances(QWidget *parent = Q_NULLPTR);

private:
	Ui::FragrancesClass ui;
};
