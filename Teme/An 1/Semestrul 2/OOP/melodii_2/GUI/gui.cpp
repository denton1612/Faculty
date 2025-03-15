//
// Created by Știube Denis on 11.07.2024.
//

#include "gui.h"

void gui::initGUI() {
    setLayout(lymain);
    rightUp->addRow("ID", id);
    rightUp->addRow("Title", title);
    rightUp->addRow("Artist", artist);
    rightUp->addRow("Rank", rank);
    rightBot->addWidget(btAdd);
    rightBot->addWidget(btRemove);
    rightBot->addWidget(btUpdate);
    rightUp->addItem(rightBot);
    tv->setModel(tm);
    right->addLayout(rightUp);
    last->addWidget(sl);
    sl->setMaximum(10);
    sl->setMinimum(0);
    value->setText("0");
    last->addWidget(value);
    up->addWidget(tv);
    up->addLayout(right);
    up->addLayout(last);
    lymain->addLayout(up);
    lymain->addLayout(bot);
    tv->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void gui::initAdd() {
    QObject::connect(btAdd, &QPushButton::clicked, [&]() {
       auto id = stoi(this->id->text().toStdString());
       auto title = this->title->text().toStdString();
       auto artist = this->artist->text().toStdString();
       auto rank = stoi(this->rank->text().toStdString());
       try {
           s.addSongService(id, title, artist, rank);
           tm->updateData();
       }
       catch (Error & err) {
           QMessageBox::warning(this, "Warning", QString::fromStdString(err.getMessage()));
       }
    });
}

void gui::initRemove() {
    QObject::connect(btRemove, &QPushButton::clicked, [&]() {
        if (tv->selectionModel()->selectedIndexes().empty())
            QMessageBox::warning(this, "Warning", "Nu a fost selectata nicio melodie");
        auto selected = tv->selectionModel()->selectedIndexes();
        for (auto & index : selected) {
            if (index.isValid() and index.column() == 0) {
                int id = index.data().toInt();
                try {
                    s.removeSongService(id);
                    tm->updateData();
                }
                catch (Error & err) {
                    QMessageBox::warning(this, "Warning", QString::fromStdString(err.getMessage()));
                }
            }
        }
    });
}

void gui::completeOnClick() {
    QObject::connect(tv, &QTableView::clicked, [&]() {
        if (!tv->selectionModel()->selectedIndexes().empty()) {
            auto selected = tv->selectionModel()->selectedIndexes();
            for (auto & index : selected) {
                if (index.column() == 1) {
                    this->title->setText(index.data().toString());
                }
                if (index.column() == 0) {
                    this->id->setText(index.data().toString());
                }
                if (index.column() == 2) {
                    this->artist->setText(index.data().toString());
                }
                else if (index.column() == 3)
                    this->sl->setValue(index.data().toInt());
            }
        }
    });
}

void gui::initUpdate() {
    QObject::connect(btUpdate, &QPushButton::clicked, [&]() {
        auto selected = tv->selectionModel()->selectedIndexes();
        for (auto & index : selected) {
            if (index.column() == 0) {
                int id = index.data().toInt();
                s.updateRankService(id, value->text().toInt());
                s.updateTitleService(id, this->title->text().toStdString());
                tm->updateData();
            }
        }
    });
}

void gui::ConnectSlider() {
    QObject::connect(sl, &QSlider::valueChanged, [&]() {
       value->setText(QString::fromStdString(to_string(sl->value())));
    });
}

void gui::initConnect() {
    initAdd();
    initRemove();
    initUpdate();
    ConnectSlider();
    completeOnClick();
}