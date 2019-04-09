#pragma once

#include <QWidget>
#include "ui_TutorialWidget.h"

class TutorialWidget : public QWidget
{
	Q_OBJECT

public:
	TutorialWidget(QWidget *parent = Q_NULLPTR);
	~TutorialWidget();

private:
	Ui::TutorialWidget ui;
};
