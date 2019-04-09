#pragma once

#include <QWidget>
#include "ui_PresenterWidget.h"
#include "Controller.h"
class PresenterWidget : public QWidget,public Observer
{
	Q_OBJECT

public:
	PresenterWidget(Controller& control, QWidget *parent = Q_NULLPTR);
	~PresenterWidget();
	void update()override { this->populateList(); }
	void populateList();
	void addQ();

private:
	Controller & control;
	Ui::PresenterWidget ui;
};

