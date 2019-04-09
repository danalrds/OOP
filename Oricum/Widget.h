#pragma once

#include <QWidget>
#include "ui_Widget.h"
#include "Observer.h"
#include "Controller.h"

class Widget : public QWidget, public Observer
{
	Q_OBJECT

public:
	Widget(Controller& control, User user, QWidget *parent = Q_NULLPTR);
	~Widget();
	void populateList();
	//User user;
	void update()  override
	{
		this->populateList();
	}
	void AddIssue();
	void RemoveIssue();
	void resolve();

private:
	Ui::Widget ui;
	Controller& control;
	User user;
};
