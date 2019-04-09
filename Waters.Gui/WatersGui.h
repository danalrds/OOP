#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_WatersGui.h"

class WatersGui : public QMainWindow
{
	Q_OBJECT

public:
	WatersGui(QWidget *parent = Q_NULLPTR);

private:
	Ui::WatersGuiClass ui;
};
