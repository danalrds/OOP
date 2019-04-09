#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_BottlesGui.h"

class BottlesGui : public QMainWindow
{
	Q_OBJECT

public:
	BottlesGui(QWidget *parent = Q_NULLPTR);

private:
	Ui::BottlesGuiClass ui;
};
