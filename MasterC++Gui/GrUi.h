#pragma once
#include <qwidget.h>
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qboxlayout.h>
#include "Controller.h"
#include "Tutorial.h"
#include <vector>
#include <qlabel.h>


class TutorialGUI : public QWidget {
private:
	Controller & ctrl;
	QListWidget* list;
	QPushButton* btnAdd;
	QPushButton* btnUpdate;
	QPushButton* btnRemove;	
	QPushButton* btnUndo;
	QPushButton* btnRedo;
	QPushButton* exitbtn;	
	QDialog* playlist;
	QListWidget* tList;
	QLineEdit* txtTitle;
	QLineEdit* txtPresenter;
	QLineEdit* txtMinutes;
	QLineEdit* txtSeconds;
	QLineEdit* txtNrlikes;
	QLineEdit* txtLink;

	QPushButton* btnAddP;
	QPushButton* btnDeleteP;
	QPushButton* btnNext;
	QPushButton* btnPlay;
	QPushButton* btnShow;
	QPushButton* btnSaveP;
	QPushButton* btnSeeByP;
	QLineEdit* nr;
	QLineEdit* textTitle;
	QLineEdit* textPresenter;
	QLineEdit* textMinutes;
	QLineEdit* textSeconds;
	QLineEdit* textNrlikes;
	QLineEdit* textLink;

	QDialog* modify;

	void initGUIComponents();
	void initPlaylistComponents();
	void connectSignalsSlots();
	void addT();
	void updateT();
	void removeT();
	void reloadList(const std::vector<Tutorial>& tutorials);
	void reloadPlayList(const std::vector<Tutorial>& tutorials);
	void connectSignalsSlots2();
	void addP();
	void removeP();
	void showP();
	void saveP();
	void nextP();
	void playP();
	void seebyP();
	void undoT();
	void redoT();
	
public:
	TutorialGUI(Controller& ctrl) : ctrl{ ctrl } {
		initGUIComponents();		
		connectSignalsSlots();
		reloadList(ctrl.getRepo().getTutorials());
		initPlaylistComponents();	
	    connectSignalsSlots2();
	}
};

