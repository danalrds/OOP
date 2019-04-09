#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_VolcanoGui.h"

class VolcanoGui : public QMainWindow
{
	Q_OBJECT

public:
	VolcanoGui(QWidget *parent = Q_NULLPTR);

private:
	Ui::VolcanoGuiClass ui;
};
