#ifndef DOGSTABLEMODEL_H
#define DOGSTABLEMODEL_H

#include <QAbstractTableModel>
#include "repository.h"

class dogstablemodel : public QAbstractTableModel
{
    Q_OBJECT
private:
    repository repo;

public:
    explicit dogstablemodel(repository& r, QObject *parent = 0);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Add data:
    //bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;


    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

private:
};

#endif // DOGSTABLEMODEL_H
