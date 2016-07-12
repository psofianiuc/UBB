#include "dogstablemodel.h"
#include <QMessageBox>
#include <QBrush>

dogstablemodel::dogstablemodel(repository &r, QObject *parent)
    : QAbstractTableModel(parent), repo(r)
{
}

QVariant dogstablemodel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole)
        {
            if(orientation == Qt::Horizontal)
            {
                switch(section)
                {
                case 0:
                    return QString("Name");
                case 1:
                    return QString("Breed");
                case 2:
                    return QString("Age");
                case 3:
                    return QString("Link");
                default:
                    break;
                }
            }
        }
        else if(role == Qt::BackgroundColorRole)
        {
            return QBrush{ QColor{ Qt::red}};
        }
    return QVariant();
}

int dogstablemodel::rowCount(const QModelIndex &parent) const
{
    dogVector aux = repo.getDogs();
    if (!parent.isValid())
        return (int)aux.size();
    return (int)aux.size();
}

int dogstablemodel::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 4;
    return 4;
}

QVariant dogstablemodel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    dog currentDog = repo.getDogs()[index.row()];

    if(role == Qt::DisplayRole || role == Qt::EditRole) {
        switch(index.column()){
         case 0: //name
            return QString::fromStdString(currentDog.getName());
         case 1: //breed
            return QString::fromStdString(currentDog.getBreed());
         case 2: //age
            return QString::fromStdString(std::to_string(currentDog.getAge()));
         case 3:
            return QString::fromStdString(currentDog.getLink());
         default:
            break;
        }
    }
    return QVariant();
}

/*
bool dogstablemodel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endInsertRows();
}
*/

bool dogstablemodel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);

    dogVector dogs = repo.getDogs();
    if(row<0 || row >= dogs.size()) {
        QMessageBox::critical(NULL,"Error","No dog at that position.");
        return false;
    }
    dog d = dogs[row];

    beginRemoveRows(QModelIndex(), row, row);
    repo.removeDog(d);
    endRemoveRows();

    return true;
}
