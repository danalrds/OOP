#include "TableModel.h"
#include <qbrush.h>
#include <qcolor.h>

TableModel::~TableModel()
{
}

int TableModel::rowCount(const QModelIndex & parent) const
{
	return this->repo.getTutorials().size();
}

int TableModel::columnCount(const QModelIndex & parent) const
{
	return 6 ;
}

QVariant TableModel::data(const QModelIndex & index, int role) const
{
	Tutorial currentT = this->repo.getTutorials()[index.row()];

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (index.column())
		{
		case 0:		// first column - name
			return QString::fromStdString(currentT.getTitle());
		case 1:		// second column - group
			return QString::fromStdString(currentT.getPresenter());
		case 2:		// third column - lab grade
			return QString::number(currentT.getDuration().getMinutes());
		case 3:		// third column - lab grade
			return QString::number(currentT.getDuration().getSeconds());
		case 4:		// fourth column - seminar grade
			return QString::number(currentT.getNrLikes());
		case 5:		// second column - group
			return QString::fromStdString(currentT.getLink());
		default:
			break;
		}
	}

	return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString{ "Title" };
			case 1:
				return QString{ "Presenter" };
			case 2:
				return QString{ " Minutes" };
			case 3:
				return QString{ " Seconds" };
			case 4:
				return QString{ " Likes" };
			case 5:
				return QString{ " Link" };
			default:
				break;
			}
		}
	}

	return QVariant();
}



Qt::ItemFlags TableModel::flags(const QModelIndex & index) const
{
	int col = index.column();
	if (col == 0 || col == 1)
		return Qt::ItemFlags{};
	return Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsSelectable;
}
