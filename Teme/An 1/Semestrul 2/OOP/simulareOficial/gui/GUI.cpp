//
// Created by Știube Denis on 20.05.2024.
//

#include "GUI.h"

void GUI::loadData() {
    for (auto e : s.getAll()) {
        list->addItem(QString::fromStdString(e.getNume() + ", " + e.getScoala()));
    }
}

void GUI::initGUI() {
    setLayout(lymain);
    lymain->addWidget(list);
    fly->addRow("Ateliere", ateliere);
    fly->addRow(btsort);
    lymain->addLayout(fly);
    lymain->addWidget(elevi);
    dreapta->addWidget(d);
    dreapta->addWidget(f);
    dreapta->addWidget(m);
    dreapta->addWidget(i);
    dreapta->addWidget(j);
    lymain->addLayout(dreapta);
}

void GUI::connectSort() {
    QObject::connect(btsort, &QPushButton::clicked, [&]() {
       s.sortareNume();
       list->clear();
       loadData();
    });
}

void GUI::connectList() {
    QObject::connect(list, &QListWidget::itemClicked, [&]() {
       auto elev = list->currentItem()->text().toStdString();
       auto nume = elev.substr(0, elev.find(", "));
       Elev e = s.find(nume);
       vector<string> ateliere = s.getAteliere(e);
       string ateliereLista = "";
       for (auto at : ateliere) {
           ateliereLista += at;
           ateliereLista += ", ";
       }
       ateliereLista.erase(ateliereLista.size()-2, 2);
       this->ateliere->setText(QString::fromStdString(ateliereLista));
    });
}

//void GUI::connectAteliere() {
//    vector<QPushButton*> butoane;
//    butoane.push_back(d);
//    butoane.push_back(f);
//    butoane.push_back(m);
//    butoane.push_back(i);
//    butoane.push_back(j);
//    for (auto b : butoane) {
//        QObject::connect(b, &QPushButton::clicked, [&]() {
//            elevi->clear();
//            auto c = b->text().toStdString();
//            int i = 0;
//            for (auto el : s.getAll()) {
//                if (el.getAteliere().find(c) != string::npos)
//                    QString text = QString::fromStdString(el.getNume() + ", " + el.getScoala());
////                    QTableWidgetItem* item = new QTableWidgetItem(text);
////                    elevi->setItem(i++, 0, elev);
//            }
//        });
//    }
//}

void GUI::initConnect() {
    connectSort();
    connectList();
}

