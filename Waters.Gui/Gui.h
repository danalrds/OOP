#pragma once

#include <QWidget>
#include "ui_Gui.h"
#include "Repo.h"
#include <QtWidgets/QMessageBox>
#include "Undo.h"
#include <memory>
class Gui : public QWidget
{
	Q_OBJECT

public:
	Gui(Repo repo, QWidget *parent = Q_NULLPTR);
	~Gui();
	void reloadList();	
	void addW();
	void removeW();	
	void updateW();
	void computeS();
	void clear();
	void Csv();
	void undo();
	
private:
	Ui::Gui ui;
	Repo repo;
	std::vector<std::unique_ptr<Action>> undoActions;
};
