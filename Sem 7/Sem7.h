#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Sem7.h"

class Sem7 : public QMainWindow
{
	Q_OBJECT

public:
	Sem7(QWidget *parent = Q_NULLPTR);

private:
	Ui::Sem7Class ui;
};
