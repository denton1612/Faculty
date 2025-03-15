//
// Created by Știube Denis on 27.06.2024.
//

#include "gui.h"

void gui::update() {
    reload();
}

void gui::initGUI() {
    setLayout(lymain);
    left->addWidget(table);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    left->addLayout(bts);
    bts->addWidget(btAdd);
    bts->addWidget(btUpd);
    bts->addWidget(col);
    bts->addWidget(stare);
    lymain->addLayout(left);
    fly->addRow("Adresa", adr);
    fly->addRow("Linii", linii);
    fly->addRow("Coloane", col);
    fly->addRow("Stare", stare);
    right->addLayout(fly);
    bts1->addWidget(btRan);
    bts1->addWidget(btParc);
    right->addLayout(bts1);
    lymain->addLayout(right);
}

void gui::ConnectAdd() {
    QObject::connect(btAdd, &QPushButton::clicked, [&]() {
        auto adr = this->adr->text().toStdString();
        auto lin = this->linii->text().toInt();
        auto col = this->col->text().toInt();
        auto stare = this->stare->text().toStdString();
        s.addService(adr, lin, col, stare);
        reload();
    });
}

void gui::ConnectGenerare() {
    QObject::connect(btRan, &QPushButton::clicked, [&]() {
        auto stare = QString::fromStdString(s.randomStare(linii->text().toInt(), col->text().toInt()));
        this->stare->setText(stare);
    });
}

void gui::ConnectParcare() {
    QObject::connect(btParc, &QPushButton::clicked, [&]() {
        QModelIndex index = table->selectionModel()->currentIndex();
        auto adresa = table->item(index.row(), 0)->text().toStdString();
        auto p = s.findService(adresa);
        parcaregui* p1 = new parcaregui{s, p};
        parcaregui* p2 = new parcaregui{s, p};
        p1->show();
        p2->show();
        s.addObserver(p1); s.addObserver(p2);
    });
}

void gui::ConnectUpdate() {
    QObject::connect(btUpd, &QPushButton::clicked, [&]() {
        auto adr = this->adr->text().toStdString();
        auto lin = this->linii->text().toInt();
        auto col = this->col->text().toInt();
        auto stare = this->stare->text().toStdString();
        try {
            s.updateService(adr, lin, col, stare);
            reload();
        }
        catch (std::exception &) {
            QMessageBox::warning(this, "warning", "Nu s-a putut efectua modificarea");
        }
    });
}

void gui::initConnect() {
    ConnectAdd();
    ConnectGenerare();
    ConnectUpdate();
    ConnectParcare();
}

void gui::reload() {
    QStringList* header = new QStringList;
    *header << "Adresa" << "Linii" << "Coloane" << "Stare";
    table->setHorizontalHeaderLabels(*header);
    table->setRowCount(s.getSize());
    int row = 0;
    for (auto& p : s.getAll()){
        QTableWidgetItem* adr = new QTableWidgetItem(QString::fromStdString(p.getAdresa()));
        QTableWidgetItem* lin = new QTableWidgetItem(QString::fromStdString(to_string(p.getLinii())));
        QTableWidgetItem* col = new QTableWidgetItem(QString::fromStdString(to_string(p.getCol())));
        QTableWidgetItem* stare = new QTableWidgetItem(QString::fromStdString(p.getStare()));
        table->setItem(row, 0, adr);
        table->setItem(row, 1, lin);
        table->setItem(row, 2, col);
        table->setItem(row, 3, stare);
        row++;
    }
}