#pragma once

#include <QWidget>
#include <QAbstractTableModel>
#include "CSV.h"
class Table : public QAbstractTableModel
{
	
public:
	Table(CSVPlaylist& playlist, QObject* parent = NULL);
	~Table();
	// number of rows
	int rowCount(const QModelIndex &parent = QModelIndex{}) const override;

	// number of columns
	int columnCount(const QModelIndex &parent = QModelIndex{}) const override;

	// Value at a given position
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

	// add header data
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;



private:
	CSVPlaylist playlist;

};



