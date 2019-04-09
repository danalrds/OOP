#pragma once

#include <QWidget>
#include "ui_PresenterWidget.h"
#include "Observer.h"
#include "Controller.h"
class PresenterWidget : public QWidget, public Observer
{
	Q_OBJECT

public:
	PresenterWidget(Controller& control, QWidget *parent = Q_NULLPTR);
	~PresenterWidget();
	void populateList();	
	void update()  override
	{
		this->populateList();
	}
	

private:
	Ui::PresenterWidget ui;
	Controller& control;
};
