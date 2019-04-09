#include "QtGuiClass.h"
#include "StudentModel.h"
QtGuiClass::QtGuiClass(StudentModel* model,QWidget *parent): QWidget(parent)
{
	
	ui.setupUi(this);
	ui.StudentView->setModel(model);

}

QtGuiClass::~QtGuiClass()
{
}
