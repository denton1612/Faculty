//
// Created by Știube Denis on 11.07.2024.
//

#include "TableModel.h"

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal) {
        if (role == Qt::DisplayRole) {
            if (section == 0)
                return "ID";
            else if (section == 1)
                return "Title";
            else if (section == 2)
                return "Artist";
            else if (section == 3)
                return "Rank";
            else
                return "Songs with same rank";
        }
    }

    return QVariant{};
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    vector<Song> sorted = s.sortSongs();
    Song song = sorted[index.row()];
    if (role == Qt::DisplayRole) {
        if (index.column() == 0)
            return QString::number(song.getId());
        if (index.column() == 1)
            return QString::fromStdString(song.getTitle());
        if (index.column() == 2)
            return QString::fromStdString(song.getArtist());
        if (index.column() == 3)
            return QString::number(song.getRank());
        else
            return QString::number(s.getRanks()[song.getRank()]);
    }
    return QVariant{};
}

void TableModel::updateData() {
    emit dataChanged(createIndex(0, 0), createIndex(rowCount(), columnCount()));
    emit layoutChanged(); // pentru a se modifica tabelul imediat dupa stergere
}