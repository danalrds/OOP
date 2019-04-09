#include "Table.h"
#include <qfont.h>
Table::Table(CSVPlaylist& playlist, QObject *parent): playlist{playlist}, QAbstractTableModel(parent)
{
	
}

Table::~Table()
{
}


int Table::rowCount(const QModelIndex & parent) const
{

	int nr = this->playlist.getTutorials().size();
	return nr;
}
int Table::columnCount(const QModelIndex& parent)const
{
	return 6;
}

QVariant Table::data(const QModelIndex & index, int role) const
{
	int row = index.row();
	int col = index.column();
	std::vector<Tutorial> dogs = this->playlist.getTutorials();
	Tutorial d = dogs[row];
	if (role == Qt::DisplayRole)
	{
		switch (col)
		{
		case 0:
			return QString::fromStdString(d.getTitle());
		case 1:
			return QString::fromStdString(d.getPresenter());
		case 2:
			return QString::fromStdString(std::to_string(d.getDuration().getMinutes()));
		case 3:
			return QString::fromStdString(std::to_string(d.getDuration().getSeconds()));
		case 4:
			return QString::fromStdString(std::to_string(d.getNrLikes()));
		case 5:
			return QString::fromStdString(d.getLink());
		default:
			break;
		}
	}
	return QVariant();
}

QVariant Table::headerData(int section, Qt::Orientation orientation, int role) const
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
				return QString{ "Minutes" };
			case 3:
				return QString{ "Seconds" };
			case 4:
				return QString{ "Likes" };
			case 5:
				return QString{ "Link" };
			default:
				break;
			}
		}
	}
	if (role == Qt::FontRole)
	{
		QFont font("Times", 10, 10, true);
		font.setBold(true);
		font.setItalic(false);
		return font;
	}
	return QVariant{};

}