#pragma once

#include <QWidget>
#include "ui_QtGuiClass.h"
#include "StudentModel.h"
class QtGuiClass : public QWidget
{
	Q_OBJECT

public:
	QtGuiClass(StudentModel* model,QWidget *parent = Q_NULLPTR);
	~QtGuiClass();

private:
	StudentModel * model;
	Ui::QtGuiClass ui;
};
