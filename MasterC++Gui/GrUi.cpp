#include "GrUi.h"
#include "RepoExceptions.h"
#include "Tutorial.h"
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMessageBox>
#include <string>
#include <algorithm>

void TutorialGUI::initGUIComponents() {

	QHBoxLayout* ly = new QHBoxLayout;
	setLayout(ly);

	QWidget* right = new QWidget;
	QVBoxLayout* vertL = new QVBoxLayout;
	right->setLayout(vertL);
	list = new QListWidget;

	list->setFont(QFont("Courier", 15, 10, true));

	QWidget* btnWidRight = new QWidget;
	QHBoxLayout* btnLay = new QHBoxLayout;
	btnWidRight->setLayout(btnLay);
	btnRemove = new QPushButton("Remove");	
	btnRemove->setIconSize(QSize(20, 20));
	

	QWidget* widDreaptaJos = new QWidget;
	QHBoxLayout* widLay = new QHBoxLayout;
	widDreaptaJos->setLayout(widLay);

	exitbtn = new QPushButton("Exit");	
	exitbtn->setIconSize(QSize(20, 20));	

	btnUndo = new QPushButton("Undo");
	btnUndo->setIconSize(QSize(20, 20));

	btnRedo = new QPushButton("Redo");
	btnRedo->setIconSize(QSize(20, 20));

	QWidget* first = new QWidget;
	QHBoxLayout* firstL = new QHBoxLayout;
	first->setLayout(firstL);	
	vertL->addWidget(list);
	vertL->addWidget(first);
	vertL->addWidget(exitbtn);
	vertL->addWidget(btnUndo);
	vertL->addWidget(btnRedo);

	QVBoxLayout* left = new QVBoxLayout;
	QWidget* leftBtns = new QWidget;
	leftBtns->setLayout(left);

	QWidget* details = new QWidget;
	QFormLayout* formDetails = new QFormLayout;
	details->setLayout(formDetails);
	txtTitle = new QLineEdit;
	formDetails->addRow(new QLabel("Title:"), txtTitle);
	txtPresenter = new QLineEdit;
	formDetails->addRow(new QLabel("Presenter:"), txtPresenter);
	txtMinutes = new QLineEdit;
	formDetails->addRow(new QLabel("Minutes:"), txtMinutes);
	txtSeconds = new QLineEdit;
	formDetails->addRow(new QLabel("Seconds:"), txtSeconds);
	txtNrlikes = new QLineEdit;
	formDetails->addRow(new QLabel("Likes:"), txtNrlikes);
	txtLink = new QLineEdit;
	formDetails->addRow(new QLabel("Link:"), txtLink);

	QHBoxLayout* oriz = new QHBoxLayout;
	QWidget* woriz = new QWidget;
	woriz->setLayout(oriz);

	btnAdd = new QPushButton("Add");		
	btnAdd->setIconSize(QSize(20, 20));

	oriz->addWidget(btnAdd);
	oriz->addWidget(btnRemove);
	btnUpdate = new QPushButton("Update");	
	btnUpdate->setIconSize(QSize(20, 20));

	oriz->addWidget(btnUpdate);

	QHBoxLayout* filtersLay = new QHBoxLayout;
	QWidget* filtersWid = new QWidget;
	filtersWid->setLayout(filtersLay);
	left->addWidget(details);
	left->addWidget(woriz);
	left->addWidget(filtersWid);
	left->addStretch();

	ly->addWidget(leftBtns);
	ly->addWidget(right);
}

void TutorialGUI::connectSignalsSlots() {

	QObject::connect(list, &QListWidget::itemSelectionChanged, [&]() {
		if (list->selectedItems().isEmpty()) {
			txtTitle->setText("");
			txtPresenter->setText("");
			txtMinutes->setText("");
			txtSeconds->setText("");
			txtNrlikes->setText("");
			txtLink->setText("");
			return;
		}
		QListWidgetItem* selected = list->selectedItems().at(0);
		QString title = selected->text();				
		txtTitle->setText(title);			
		try {			
			Tutorial t =ctrl.getRepo().find_Obj_ByTitle_Presenter(title.toStdString());	
			txtPresenter->setText(QString::fromStdString(t.getPresenter()));
			txtMinutes->setText(QString::number(t.getDuration().getMinutes()));
			txtSeconds->setText(QString::number(t.getDuration().getSeconds()));
			txtNrlikes->setText(QString::number(t.getNrLikes()));
			txtLink->setText(QString::fromStdString(t.getLink()));
		}
		catch (RepositoryException& ex) {
			QMessageBox::warning(nullptr, "Warning", QString::fromStdString("Error!"));
		}
	});

	QObject::connect(btnAdd, &QPushButton::clicked, this, &TutorialGUI::addT);
	
	QObject::connect(btnRemove, &QPushButton::clicked, this, &TutorialGUI::removeT);
	
	QObject::connect(btnUpdate, &QPushButton::clicked, this, &TutorialGUI::updateT);

	QObject::connect(btnUndo, &QPushButton::clicked, this, &TutorialGUI::undoT);
	
	QObject::connect(btnRedo, &QPushButton::clicked, this, &TutorialGUI::redoT);

	QObject::connect(exitbtn, &QPushButton::clicked, [&]() {
		
		this->close();
		playlist->close();
	});	
	
}

void TutorialGUI::addT() {
	try {
		ctrl.addTutorialToRepository(txtTitle->text().toStdString(), txtPresenter->text().toStdString(), 
			txtMinutes->text().toDouble(), txtSeconds->text().toDouble(), txtNrlikes->text().toInt(), txtLink->text().toStdString());
		reloadList(ctrl.getRepo().getTutorials());
	}
	catch (RepositoryException& ex) {
		QMessageBox::warning(this, "Warning", QString::fromStdString("Already in repo!"));
	}
	catch (Exception& ex) {
		for (auto e : ex.getErrors()) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(e));
		}

	}
}

void TutorialGUI::removeT() {
	if (list->selectedItems().isEmpty())
		return;
	QListWidgetItem* selected = list->selectedItems().at(0);	
	ctrl.deleteTutorialRepository(txtTitle->text().toStdString(), txtPresenter->text().toStdString());
	reloadList(ctrl.getRepo().getTutorials());

}

void TutorialGUI::updateT() {
	if (list->selectedItems().isEmpty())
		return;
	modify = new QDialog;
	modify->setWindowTitle("Update");	
	QVBoxLayout* layModify = new QVBoxLayout;
	modify->setLayout(layModify);


	QWidget* detail = new QWidget;
	QFormLayout* formDetail = new QFormLayout;
	detail->setLayout(formDetail);
	txtTitle = new QLineEdit;
	txtTitle->setText(txtTitle->text());
	formDetail->addRow(new QLabel("Title:"), txtTitle);

	txtPresenter = new QLineEdit;
	formDetail->addRow(new QLabel("Presenter:"), txtPresenter);

	txtMinutes = new QLineEdit;
	formDetail->addRow(new QLabel("Minutes:"), txtMinutes);
	
	txtSeconds = new QLineEdit;
	formDetail->addRow(new QLabel("Seconds:"), txtSeconds);

	txtNrlikes = new QLineEdit;
	formDetail->addRow(new QLabel("Likes:"), txtNrlikes);

	txtLink = new QLineEdit;
	formDetail->addRow(new QLabel("Link:"), txtLink);

	layModify->addWidget(detail);
	QPushButton* confirmBtn = new QPushButton("Update");
	layModify->addWidget(confirmBtn);
	modify->show();

	QObject::connect(confirmBtn, &QPushButton::clicked, [&]() {
		try {
			ctrl.updateTutorialRepository(txtTitle->text().toStdString(), txtPresenter->text().toStdString(), 
				txtMinutes->text().toDouble(), txtSeconds->text().toDouble(), txtNrlikes->text().toInt(), txtLink->text().toStdString());
			
			modify->close();			
			reloadList(ctrl.getRepo().getTutorials());
		}
		catch (RepositoryException& ex) {
			QMessageBox::warning(this, "Warning", QString::fromStdString("Not in repo!"));
		}
		catch (Exception& ex) {
			for (const auto& e : ex.getErrors()) {
				QMessageBox::warning(this, "Warning", QString::fromStdString(e));
			}
		}
	});

}

void TutorialGUI::undoT()
{
	ctrl.undo();
	reloadList(ctrl.getRepo().getTutorials());
}

void TutorialGUI::redoT()
{
	ctrl.redo();
	reloadList(ctrl.getRepo().getTutorials());
}

void TutorialGUI::reloadList(const std::vector<Tutorial>& tutorials) {
	list->clear();
	for (const auto& m : tutorials) {
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(m.getTitle()), list);
	}
}
void TutorialGUI::reloadPlayList(const std::vector<Tutorial>& tutorials) {
	tList->clear();
	for (const auto& m : tutorials) {
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(m.getTitle()), tList);
	}
}

void TutorialGUI::initPlaylistComponents() {
	playlist = new QDialog;
	playlist->setWindowTitle("Playlist");
	QVBoxLayout* playLay = new QVBoxLayout;
	playlist->setLayout(playLay);
	tList = new QListWidget;
	tList->setFont(QFont("Courier", 15, 10, true));
	playLay->addWidget(tList);	

	QHBoxLayout* orizLay0 = new QHBoxLayout;
	QWidget* btnFirst = new QWidget;
	btnFirst->setLayout(orizLay0);

	btnAddP = new QPushButton("Add");	
	btnAddP->setIconSize(QSize(20, 20));
	orizLay0->addWidget(btnAddP);

	btnNext = new QPushButton("Next");
	btnNext->setIconSize(QSize(20, 20));
	orizLay0->addWidget(btnNext);

	btnDeleteP = new QPushButton("Delete");
	btnDeleteP->setIconSize(QSize(20, 20));
	orizLay0->addWidget(btnDeleteP);

	btnPlay = new QPushButton("Play");	
	btnPlay->setIconSize(QSize(20, 20));
	orizLay0->addWidget(btnPlay);

	btnShow = new QPushButton("Show");
	btnShow->setIconSize(QSize(20, 20));
	orizLay0->addWidget(btnShow);

	btnSaveP = new QPushButton("Save");
	btnSaveP->setIconSize(QSize(20, 20));
	orizLay0->addWidget(btnSaveP);

	btnSeeByP = new QPushButton("Add by presenter");
	btnSeeByP->setIconSize(QSize(20, 20));
	orizLay0->addWidget(btnSeeByP);

	playLay->addWidget(btnFirst);
	QWidget* detail = new QWidget;
	QFormLayout* formDetail = new QFormLayout;
	detail->setLayout(formDetail);	

	textTitle = new QLineEdit;
	textTitle->setText(textTitle->text());
	formDetail->addRow(new QLabel("Title:"), textTitle);

	textPresenter = new QLineEdit;	
	formDetail->addRow(new QLabel("Presenter:"), textPresenter);

	textMinutes = new QLineEdit;
	formDetail->addRow(new QLabel("Minutes:"), textMinutes);

	textSeconds = new QLineEdit;
	formDetail->addRow(new QLabel("Seconds:"), textSeconds);

	textNrlikes = new QLineEdit;
	formDetail->addRow(new QLabel("Likes:"), textNrlikes);

	textLink = new QLineEdit;
	formDetail->addRow(new QLabel("Link:"), textLink);

	playLay->addWidget(detail);

	playlist->show();
}

void TutorialGUI::connectSignalsSlots2() {

	QObject::connect(tList, &QListWidget::itemSelectionChanged, [&]() {
		if (tList->selectedItems().isEmpty()) {
			textTitle->setText("");
			textPresenter->setText("");
			textMinutes->setText("");
			textSeconds->setText("");
			textNrlikes->setText("");
			textLink->setText("");
			return;
		}
		QListWidgetItem* selected = tList->selectedItems().at(0);
		QString title = selected->text();
		textTitle->setText(title);
		
			Tutorial t = ctrl.getPlaylist()->find_Obj_ByTitle_Presenter(title.toStdString());
			int pos= ctrl.getPlaylist()->findByTitle_Presenter(title.toStdString());
			if (pos!=-1)
			{
				textPresenter->setText(QString::fromStdString(t.getPresenter()));
				textMinutes->setText(QString::number(t.getDuration().getMinutes()));
				textSeconds->setText(QString::number(t.getDuration().getSeconds()));
				textNrlikes->setText(QString::number(t.getNrLikes()));
				textLink->setText(QString::fromStdString(t.getLink()));
			}
		
	});

	QObject::connect(btnAddP, &QPushButton::clicked, this, &TutorialGUI::addP);
	QObject::connect(btnDeleteP, &QPushButton::clicked, this, &TutorialGUI::removeP);
	QObject::connect(btnNext, &QPushButton::clicked, this, &TutorialGUI::nextP);
	QObject::connect(btnShow, &QPushButton::clicked, this, &TutorialGUI::showP);
	QObject::connect(btnSaveP, &QPushButton::clicked, this, &TutorialGUI::saveP);
	QObject::connect(btnPlay, &QPushButton::clicked, this, &TutorialGUI::playP);
	QObject::connect(btnSeeByP, &QPushButton::clicked, this, &TutorialGUI::seebyP);

	QObject::connect(exitbtn, &QPushButton::clicked, [&]() {

		this->close();
		
	});

}

void TutorialGUI::addP() {
	try {
		Duration d{ textMinutes->text().toDouble(),textSeconds->text().toDouble() };
		Tutorial t{textTitle->text().toStdString(),textPresenter->text().toStdString(),
			d,textNrlikes->text().toInt(), textLink->text().toStdString() };
		ctrl.addTutorialToPlay(t);
		reloadPlayList(ctrl.getPlaylist()->getTutorials());
	}
	catch (RepositoryException& ex) {
		QMessageBox::warning(this, "Warning", QString::fromStdString("Already in playlist!"));
	}
	catch (Exception& ex) {
		for (auto e : ex.getErrors()) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(e));
		}

	}
}

void TutorialGUI::removeP() {
	if (tList->selectedItems().isEmpty())
		return;
	QListWidgetItem* selected = tList->selectedItems().at(0);
	ctrl.deleteTutorialPlaylist(textTitle->text().toStdString(), textPresenter->text().toStdString());
	reloadPlayList(ctrl.getPlaylist()->getTutorials());

}
void TutorialGUI::showP() {	
	ctrl.openPlaylist();
}
void TutorialGUI::saveP() {	
	ctrl.savePlaylist();
}
void TutorialGUI::nextP() {	
	ctrl.nextPlaylist();
}
void TutorialGUI::playP() {	
	ctrl.startPlaylist();
}
void TutorialGUI::seebyP() {
	std::string presenter = textPresenter->text().toStdString();
	ctrl.toPlayByPresenter(presenter);
	reloadPlayList(ctrl.getPlaylist()->getTutorials());
}

