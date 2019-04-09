#include "writerWidget.h"

writerWidget::writerWidget(WritingSession&s, Writer w, QWidget * parent) : QWidget(parent), session(s), writer(w) {
	this->ui.setupUi(this);
	this->session.refisterObserver(this);
	this->setWindowTitle(QString::fromStdString(this->writer.getName() + "-" + this->writer.getExpertise()));
	this->populateList();

	QObject::connect(this->ui.addButton, &QPushButton::clicked, this, &writerWidget::addNewIdea);
	QObject::connect(this->ui.acceptButton, &QPushButton::clicked, this, &writerWidget::acceptIdea);
	QObject::connect(this->ui.ideasListWidget, &QListWidget::itemSelectionChanged, this, &writerWidget::enableButtons);
	QObject::connect(this->ui.ideasListWidget, &QListWidget::itemSelectionChanged, this, &writerWidget::enableDevelop);
    QObject:connect(this->ui.developButton, &QPushButton::clicked, this, &writerWidget::showDeveloperTools);
	QObject::connect(this->ui.saveButton, &QPushButton::clicked, this, &writerWidget::savePlot);
	if (this->writer.getExpertise() == "junior" || this->writer.getExpertise() == "assistant")this->ui.acceptButton->setEnabled(false);

}

writerWidget::~writerWidget() 
{

}

void writerWidget::populateList()
{
	this->ui.ideasListWidget->clear();
	for (auto d : this->session.getIdeas()) {
		QListWidgetItem*item = new QListWidgetItem;
		std::string text = d.getDescription() + "\t" + d.getStatus() + "\t" + d.getCreator() + "\t" + std::to_string(d.getAct());
		item->setText(QString::fromStdString(text));
		if (d.getCreator() == this->writer.getName() && d.getStatus() == "accepted")item->setBackgroundColor(Qt::green);
		this->ui.ideasListWidget->addItem(item);
	}

}

void writerWidget::addNewIdea()
{
	try {
		QString Qdesc = this->ui.descpriptionEdit->text();
		QString Qact = this->ui.actEdit->text();
		std::string desc = Qdesc.toStdString();
		int act = Qact.toInt();
		this->session.addIdea(desc, "proposed", this->writer.getName(), act);
	}
	catch (std::exception &e) {
		QMessageBox m;
		m.critical(this, "error", e.what());
	}
}

int writerWidget::getSelectedIndex()
{
	if (this->session.getIdeas().size() == 0)return -1;
	QModelIndexList index = this->ui.ideasListWidget->selectionModel()->selectedIndexes();
	if (index.size() == 0)return -1;
	int idx = index.at(0).row();
	return idx;
}

void writerWidget::acceptIdea()
{
	int idx = this->getSelectedIndex();
	if (idx != -1) {
		Idea d = this->session.getIdeas()[idx];
		this->session.acceptIdea(d.getDescription(), d.getAct());

	}
}

void writerWidget::enableButtons()
{
	if (this->writer.getExpertise() != "senior")return;
	int idx = this->getSelectedIndex();
	if (idx != -1) {
		Idea d = this->session.getIdeas()[idx];
		if (d.getStatus() == "proposed")this->ui.acceptButton->setEnabled(true);
		else this->ui.acceptButton->setEnabled(false);

	}
}

void writerWidget::enableDevelop()
{
	int idx = this->getSelectedIndex();
	if (idx != -1) {
		Idea d = this->session.getIdeas()[idx];
		if (this->session.hasAccepted(this->writer.getName()))this->ui.developButton->setEnabled(true);
		else this->ui.developButton->setEnabled(false);
	}
}

void writerWidget::showDeveloperTools()
{
	std::vector<Idea>acceptedIdeas;
	for (auto d : this->session.getIdeas()) {
		if (d.getCreator() == this->writer.getName()) {
			if (d.getStatus() == "accepted")acceptedIdeas.push_back(d);
		}
	}
	for (auto d : acceptedIdeas) {
		developerWidget*dev = new developerWidget(this->session, d.getDescription());
		dev->show();

	}
}

void writerWidget::savePlot()
{
	std::ofstream f("plot.txt");
	if (!f.is_open())return;
	for (int i = 1; i < 4; i++) {
		f << "act" << std::to_string(i) << std::endl;
		for (auto d : this->session.getIdeas()) {
			if (d.getAct() == i && d.getStatus() == "accepted") {
				f << d.getDescription() << "[" << d.getCreator() << "]\n";

			}
		}
	}
}


