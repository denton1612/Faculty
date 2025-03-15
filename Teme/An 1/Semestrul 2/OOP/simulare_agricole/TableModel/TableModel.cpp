//
// Created by Știube Denis on 25.06.2024.
//

#include "TableModel.h"

int TableModel::rowCount(const QModelIndex &parent) const {
    return utilaje.size();
}

int TableModel::columnCount(const QModelIndex &parent) const {
    return 5;
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        auto utilaj = utilaje[index.row()];
        if (index.column() == 0)
            return QString::number(utilaj.getId());
        if (index.column() == 1)
            return QString::fromStdString(utilaj.getTip());
        if (index.column() == 2)
            return QString::fromStdString(utilaj.getDenumire());
        if (index.column() == 3)
            return QString::number(utilaj.getCilindri());
        return QString::fromStdString()
    }
    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {

        }
    }
}