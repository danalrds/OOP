#pragma once

#include <QWidget>
#include "ui_writerWindow.h"

class writerWindow : public QWidget
{
	Q_OBJECT

public:
	writerWindow(QWidget *parent = Q_NULLPTR);
	~writerWindow();

private:
	Ui::writerWindow ui;
};
