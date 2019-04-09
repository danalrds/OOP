#pragma once

#include <QWidget>
#include "ui_ChatWindow.h"
#include "Classes.h"

class ChatWindow : public QWidget, public Observer
{
	Q_OBJECT

public:
	ChatWindow(QWidget *parent = Q_NULLPTR);
	~ChatWindow();
	void update() override;
	void SendMessage();

private:
	Ui::ChatWindow ui;
	ChatSession chat;
};


