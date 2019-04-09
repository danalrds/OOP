#include <QtWidgets/QApplication>
#include "Repository.h"
#include "QtGuiClass.h"
#include "StudentModel.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Repository repo{"Students.txt"};
	StudentModel* model = new StudentModel{ repo };
	QtGuiClass uiqt{model};
	uiqt.show();
	return a.exec();
}
