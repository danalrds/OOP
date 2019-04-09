#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Oricum.h"

class Oricum : public QMainWindow
{
	Q_OBJECT

public:
	Oricum(QWidget *parent = Q_NULLPTR);

private:
	Ui::OricumClass ui;
};
