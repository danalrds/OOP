#pragma once

#include <QWidget>
#include "ui_Filter.h"
#include "Repo.h"
class Filter : public QWidget
{
	Q_OBJECT

public:
	Filter(Repo repo, QWidget *parent = Q_NULLPTR);
	~Filter();

private:
	Ui::Filter ui;
	Repo repo;
};
