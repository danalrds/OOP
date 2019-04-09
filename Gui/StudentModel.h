#pragma once
#include "Repository.h"
#include <QAbstractTableModel>
class StudentModel:public QAbstractTableModel
{
private:
	Repository & repo;
public:
	StudentModel(Repository& r) :repo{ r } {}	
	int rowCount(const QModelIndex & parent = QModelIndex()) const;
	int columnCount(const QModelIndex & parent = QModelIndex()) const;
	QVariant data(const QModelIndex& index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
};