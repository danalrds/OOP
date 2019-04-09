#pragma once
/*
friend std::ostream& operator<<(std::ostream&os, User&w);
friend std::istream& operator>>(std::istream&is, User&w);


class Widget : public QWidget, public Observer
{
Q_OBJECT

public:
Widget(Controller& control, User user, QWidget *parent = Q_NULLPTR);
~Widget();
void populateList();
//User user;
void update()  override
{
this->populateList();
}
void AddIssue();
void RemoveIssue();
void resolve();

private:
Ui::Widget ui;
Controller& control;
User user;
};

//constructor widget/////

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
catch (std::exception& e)
{
QMessageBox m;
m.critical(this, "error", e.what());
}

row = ui.ListWidget->currentItem()->text().toStdString();
selected->setBackgroundColor(Qt::green);
ui.AnswerButton->setEnabled(true);

IN MAIN
for (auto u : control.getU())
{
Widget* w = new Widget(control, u);
w->show();
}




soooort
sort(issues.begin(), issues.end(), [](Issue a, Issue b) {if (a.getStatus() < b.getStatus()) return true;
else if (a.getStatus() == b.getStatus()) if (a.getDesc() < b.getDesc()) return true; return false;});

TABLEWIDGET

ui.TableWidget->setColumnCount(2);

reload...
ui.TableWidget->setRowCount(fr.size());
ui.TableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
ui.TableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Price"));
for (auto f : fr)
{
QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdString(f.getName()));
QTableWidgetItem* price = new QTableWidgetItem(QString::number(f.getPrice()));
ui.TableWidget->setItem(pos,0,item);
ui.TableWidget->setItem(pos, 1, price);
pos = pos + 1;
}

*/