#pragma once
#include"Observer.h"
#include <QWidget>
#include"WritingSession.h"
#include"ui_writerWindow.h"
#include<QMessageBox>
#include<QTextEdit>
#include"developerWidget.h"

class writerWidget : public QWidget, public Observer {
	Q_OBJECT
private:
	WritingSession & session;
	Writer writer;
	Ui::writerWindow ui;
public:
	writerWidget(WritingSession&s, Writer w, QWidget * parent = Q_NULLPTR);
	~writerWidget();
	void populateList();
	void update()override { this->populateList(); }
	void addNewIdea();
	int getSelectedIndex();
	void acceptIdea();
	void enableButtons();
	void enableDevelop();
	void showDeveloperTools();
	void savePlot();
};