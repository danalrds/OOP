#pragma once

#include <QWidget>
#include "ui_developerEditWidget.h"
#include"WritingSession.h"
class developerEditWidget : public QWidget
{
	Q_OBJECT

public:
	developerEditWidget(QWidget *parent = Q_NULLPTR);
	~developerEditWidget();

private:
	Ui::developerEditWidget ui;
};





class developerWidget : public QWidget {
	Q_OBJECT
private:
	std::string idea;
	Ui::developWindow ui;
	WritingSession&session;
public:
	developerWidget(WritingSession&s, std::string i, QWidget * parent = Q_NULLPTR);
	~developerWidget();
	void updateIdea();

private:

};
