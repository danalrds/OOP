#include "Sem7.h"
#include <QtWidgets/QApplication>
#include "ChatWindow.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ChatWindow w;
	w.show();
	return a.exec();
}
