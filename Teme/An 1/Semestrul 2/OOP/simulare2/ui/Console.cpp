//
// Created by Știube Denis on 20.05.2024.
//

#include "Console.h"

void Console::initGUI() {
    setLayout(lymain);
    lymain->addWidget(list);
    fly->addRow("Suprafata minima", suprmin);
    fly->addRow("Suprafata maxima", suprmax);
    fly->addRow("Pret minim", pretmin);
    fly->addRow("Pret maxim", pretmax);
    fly->addRow(btSterge);
    fly->addRow(fltSupr, fltPret);
    lymain->addLayout(fly);
    lymain->addWidget(flt);
}

void Console::loadData() {
    for (auto ap : service.getAll()) {
        list->addItem(QString::fromStdString(ap.getStrada() + ' ' + to_string(ap.getSuprafata()) + ' ' + to_string(ap.getPret())));
    }
}

void Console::connectList() {
    QObject::connect(list, &QListWidget::itemClicked, [&]() {
       auto item = list->currentItem();
       auto text = item->text().toStdString();
       int pos = text.find(' ');
       string strada, supr, pret;
       strada = text.substr(0, pos);
       text.erase(0, pos+1);
       pos = text.find(' ');
       supr = text.substr(0, pos);
       text.erase(0, pos+1);
       pret = text.substr(0,pos);
       this->strada->setText(QString::fromStdString(strada));
       this->supr->setText(QString::fromStdString(supr));
       this->pret->setText(QString::fromStdString(pret));
    });
}

void Console::connectSterge() {
    QObject::connect(btSterge, &QPushButton::clicked, [&](){
        auto str = strada->text().toStdString();
        auto supra = stoi(supr->text().toStdString());
        auto pret = stoi(this->pret->text().toStdString());
        try{
            service.stergeService(str, supra, pret);
            list->clear();
            loadData();
        }
        catch(eroare & er) {
            QMessageBox::information(list, "", QString::fromStdString(er.getMesaj()));
        }
    });
}

void Console::connectFiltreazaSupr() {
    QObject::connect(fltSupr, &QPushButton::clicked, [&]() {
        int supr1 = suprmin->text().toInt();
        int supr2 = suprmax->text().toInt();
        flt->clear();
        vector<Apartament> filtrat = service.filtreazaSupr(supr1, supr2);
        for (auto ap : filtrat) {
            flt->addItem(QString::fromStdString(ap.getStrada() + ' ' + to_string(ap.getSuprafata()) + ' ' + to_string(ap.getPret())));
        }
    });
}

void Console::initConnect() {
    connectSterge();
    connectList();
//    connectFiltreazaPret();
    connectFiltreazaSupr();
}