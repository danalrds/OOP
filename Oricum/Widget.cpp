#include "Widget.h"
#include <sstream>
#include <QMessageBox>
using namespace std;
Widget::Widget(Controller& control, User user, QWidget *parent)
	:control{ control }, user{user}, QWidget(parent)
{
	ui.setupUi(this);
	this->control.registerObserver(this);
	stringstream buffer;
	buffer << user.getName() << " " << user.getType();
	this->setWindowTitle(QString::fromStdString(buffer.str()));
	if (user.getType() == "programmer")
	{
		this->ui.AddButton->setVisible(false);
	}
	this->populateList();
	QObject::connect(this->ui.AddButton, &QPushButton::clicked, this, &Widget::AddIssue);
	QObject::connect(this->ui.RemoveButton, &QPushButton::clicked, this, &Widget::RemoveIssue);
	QObject::connect(this->ui.ResolveButton, &QPushButton::clicked, this, &Widget::resolve);

}


vector<string> tokenize2(const string& str, char delimiter)
{
	vector <string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}


Widget::~Widget()
{
}

void Widget::populateList()
{
	ui.ListWidget->clear();
	std::vector<Issue> issues = control.getI();
	sort(issues.begin(), issues.end(), [](Issue a, Issue b) {if (a.getStatus() < b.getStatus()) return true; 
	else if (a.getStatus() == b.getStatus()) if (a.getDesc() < b.getDesc()) return true; return false;});
	for (auto i : issues)
	{
		QListWidgetItem*item = new QListWidgetItem;
		stringstream buffer;
		buffer << i.getDesc() << " " << i.getStatus() << " " << i.getReporter() << " " << i.getSolver();
		QString str = QString::fromStdString(buffer.str());
		item->setText(str);
		ui.ListWidget->addItem(item);
	}
	
}
void Widget::AddIssue()
{
	try {
		std::string desc, status, solver, reporter;
		desc = ui.IssueEdit->text().toStdString();
		status = "opened";
		reporter = this->user.getName();
		solver = "noone";
		if (desc == "") 
			throw std::exception("empty!");
		if (this->control.find(desc) != -1)
			throw std::exception("already in repo!");
		this->control.addIssue(desc, status, reporter, solver);
		this->populateList();
	}
	catch (std::exception& e)
	{
		QMessageBox m;
		m.critical(this, "error", e.what());
	}
	
}
void Widget::RemoveIssue()
{
	std::string row, desc;
	row = ui.ListWidget->currentItem()->text().toStdString();
	std::vector<string> tokens = tokenize2(row, ' ');
	desc = tokens[0];
	this->control.removeIssue(desc);
	this->populateList();
}
void Widget::resolve()
{
	std::string row, desc, name;
	name = user.getName();
	row = ui.ListWidget->currentItem()->text().toStdString();
	std::vector<string> tokens = tokenize2(row, ' ');
	desc = tokens[0];
	this->control.updateStatus(desc,name);
	this->populateList();
}