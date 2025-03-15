//
// Created by Știube Denis on 26.06.2024.
//

#include "TableModel.h"

QVariant TableModel::data(const QModelIndex &index, int role) const {
    Car c = cars[index.row()];
    if (role == Qt::BackgroundRole) {
        if (c.getTip() == "sedan")
            return QBrush{QColor{200, 30, 70}};
        if (c.getTip() == "hatch")
            return QBrush {Qt::red};
        if (c.getTip() == "van")
            return QBrush {Qt::green};
        if (c.getTip() == "suv")
            return QBrush {Qt::darkCyan};
    }

    if (role == Qt::DisplayRole) {
        if (index.column() == 0) {
            return QString::fromStdString(c.getNri());
        }
        else if (index.column() == 1)
            return QString::fromStdString(c.getDenumire());
        else if (index.column() == 2)
            return QString::number(c.getAn());
        else
            return QString::fromStdString(c.getTip());
    }

    return QVariant{};
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal) {
        if (role == Qt::DisplayRole) {
            if (section == 0)
                return "Nr inmatriculare";
            else if (section == 1)
                return "Denumire";
            else if (section == 2)
                return "An fabricatie";
            else
                return "Tip";
        }
    }

    return QVariant{};
}

void TableModel::setData(const vector<Car> &n) {
    this->cars = n;
    QModelIndex topleft = createIndex(0, 0);
    QModelIndex bottomright = createIndex(rowCount(), columnCount());
    emit dataChanged(topleft, bottomright);
    emit layoutChanged();
}