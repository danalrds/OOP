#pragma once

#include <QWidget>
#include "ui_ParticipantWidget.h"
#include "Controller.h"
#include <string>


class ParticipantWidget : public QWidget, public Observer
{
	Q_OBJECT

public:
	ParticipantWidget(Controller& control, Participant& p, QWidget *parent = Q_NULLPTR);
	~ParticipantWidget();
	void update()override { this->populateList(); }
	void populateList();
	void answer();
	std::vector < int> answered;
	void enableButtons();	
	int getSelectedIndex();
	int score;

private:
	Ui::ParticipantWidget ui;
	Controller&  control;
	Participant& participant;
};

