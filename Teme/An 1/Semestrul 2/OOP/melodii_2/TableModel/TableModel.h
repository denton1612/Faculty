//
// Created by Știube Denis on 11.07.2024.
//

#ifndef MELODII_2_TABLEMODEL_H
#define MELODII_2_TABLEMODEL_H
#include <QAbstractTableModel>
#include "../Domain/Song.h"
#include "../Service/Service.h"
#include <vector>
using std::vector;

class TableModel: public QAbstractTableModel{
private:
    Service & s;

public:
    TableModel(Service & s): s{s} {

    }

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return s.getSize();
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        return 5;
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    void updateData();
};


#endif //MELODII_2_TABLEMODEL_H
