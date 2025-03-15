//
// Created by Știube Denis on 25.06.2024.
//

#ifndef SIMULARE_AGRICOLE_TABLEMODEL_H
#define SIMULARE_AGRICOLE_TABLEMODEL_H
#include <QAbstractTableModel>
#include <vector>
#include "../Domain/Utilaj.h"
using std::vector;

class TableModel: public QAbstractTableModel{
    Q_OBJECT

public:
    TableModel(vector<Utilaj> u): utilaje{u} {

    }
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
};


#endif //SIMULARE_AGRICOLE_TABLEMODEL_H
