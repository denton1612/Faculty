//
// Created by Știube Denis on 26.06.2024.
//

#ifndef MASINI_TABLEMODEL_H
#define MASINI_TABLEMODEL_H
#include <QAbstractTableModel>
#include "../Service/service.h"
#include <vector>
#include <QBrush>

class TableModel: public QAbstractTableModel{
private:
    vector<Car> cars;

public:
    TableModel(vector<Car> c): cars{c} {

    }
    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return cars.size();
    }
    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        return 4;
    }
    QVariant data (const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    void setData(const vector<Car> & n);
};


#endif //MASINI_TABLEMODEL_H
