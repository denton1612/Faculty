//
// Created by Știube Denis on 26.06.2024.
//

#include "gui.h"

void gui::initGUI() {
    setLayout(lymain);
    tv->setModel(tm);
    lymain->addWidget(tv);
    lybts->addWidget(btPlus);
    lybts->addWidget(btMinus);
    lybts->addWidget(btUndo);
    lybts->addWidget(btRedo);
    lybts->addWidget(btDel);
    lymain->addLayout(lybts);
    tv->setSelectionMode(QAbstractItemView::MultiSelection);
    tv->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void gui::reload() {
    tm->setData(s.sortNri());
}

void gui::initConnect() {
    QObject::connect(btPlus, &QPushButton::clicked, this, [&](){
        s.plus();
        reload();
    });
    QObject::connect(btMinus, &QPushButton::clicked, this, [&]() {
        s.minus();
        reload();
    });
    QObject::connect(btUndo, &QPushButton::clicked, this, [&]() {
        try {
            s.undo();
            reload();
            QMessageBox::information(this, "Info", QString{"S-a facut cu SUCCES undo"});
        }
        catch(exceptions & err) {
            QMessageBox::information(this, "Warning", QString::fromStdString(err.getMesaj()));
        }
    });
    QObject::connect(btRedo, &QPushButton::clicked, this, [&]() {
        try {
            s.redo();
            reload();
            QMessageBox::information(this, "Info", QString{"S-a facut cu succes REDO!"});
        }
        catch (exceptions & err) {
            QMessageBox::warning(this, "Warning", QString::fromStdString(err.getMesaj()));
        }
    });
    QObject::connect(btDel, &QPushButton::clicked, this, [&]() {
        if (tv->selectionModel()->selectedIndexes().isEmpty())
            QMessageBox::information(this, "Warning", QString{"Nu s-a selectat nicio masina"});
        auto selected = tv->selectionModel()->selectedIndexes();
        for (auto & index : selected) {
            if (index.isValid() and index.column() == 0) {
                auto nri = index.data().toString().toStdString();
                s.deleteCarService(nri);
            }
            reload();
        }
    });
}