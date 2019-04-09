#include "ChatWindow.h"
#include <QListWidgetItem>
ChatWindow::ChatWindow(QWidget *parent)
	: QWidget(parent), Observer()
{
	ui.setupUi(this);
}

ChatWindow::~ChatWindow()
{
}


void ChatWindow::update()
{
	std::vector < pair < string, string >> list = this->chat.getMessages();
}

void ChatWindow::SendMessage()
{

	for ( auto& b : this->chat.getMessages())
	{
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(b.first+" "+b.second), ui.ListWidget);
	}
}