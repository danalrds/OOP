#include "StudentModel.h"
int StudentModel::rowCount(const QModelIndex & parent) const
{
	return repo.getSize();
}
int StudentModel::columnCount(const QModelIndex & parent) const
{
	return 4;
}
QVariant StudentModel::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int column = index.column();
	Student s = repo.getStudents()[row];

	if (role == Qt::DisplayRole)
	{
		switch (column)
		{
		case 0:
			return QString::fromStdString(s.getName());		

		case 1:
			return QString::fromStdString(s.getGroup());
		case 2:
			return QString::number(s.getLabGrade());
		case 3:
			return QString::number(s.getSeminarGrade());
		default:
			break;
		}
	}
	return QVariant();
}
QVariant StudentModel:: headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
		switch (section)
		{
		case 0:
			return QString::fromStdString("Name");

		case 1:
			return QString::fromStdString("Group");
		case 2:
			return QString::fromStdString("Labgrage");
		case 3:
			return QString::fromStdString("Semgrade");
		default:
			break;
		}
	return QVariant();
}