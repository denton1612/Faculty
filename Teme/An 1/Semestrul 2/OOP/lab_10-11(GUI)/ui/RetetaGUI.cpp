//
// Created by Știube Denis on 21.05.2024.
//

#include "RetetaGUI.h"

void RetetaGUI::initGUI() {
    QHBoxLayout* lymain = new QHBoxLayout;
    setLayout(lymain);
    QVBoxLayout* st = new QVBoxLayout;
    QHBoxLayout* bts = new QHBoxLayout;
    QFormLayout* fly = new QFormLayout;
    QVBoxLayout* dr = new QVBoxLayout;
    st->addWidget(reteta);
    st->addLayout(fly);
    fly->addRow("Denumire", denText);
    fly->addRow("Producator", prodText);
    st->addLayout(bts);
    bts->addWidget(btAdaugaReteta);
    bts->addWidget(btAdaugaRandom);
    bts->addWidget(btStergeTot);
    bts->addWidget(btExport);
    lymain->addLayout(st);
    dr->addWidget(sl);
    val->setText("0");
    dr->addWidget(val);
    lymain->addLayout(dr);
}

void RetetaGUI::loadReteta() {
    QStringList* header = new QStringList;
    *header << "Denumire" << "Pret" << "Producator" << "Substanta";
    reteta->setHorizontalHeaderLabels(*header);
    reteta->setRowCount(service.getSizeReteta());
    int row = 0;
    for (Medicament& m : service.getAllReteta()){
        QTableWidgetItem* den = new QTableWidgetItem(QString::fromStdString(m.getDenumire()));
        QTableWidgetItem* pret = new QTableWidgetItem(QString::fromStdString(std::to_string(int(m.getPret()))));
        QTableWidgetItem* prod = new QTableWidgetItem(QString::fromStdString(m.getProducator()));
        QTableWidgetItem* subst = new QTableWidgetItem(QString::fromStdString(m.getSubst()));
        reteta->setItem(row, 0, den);
        reteta->setItem(row, 1, pret);
        reteta->setItem(row, 2, prod);
        reteta->setItem(row, 3, subst);
        row++;
    }
}

void RetetaGUI::ConnectAdaugaReteta() {
    QObject::connect(btAdaugaReteta, &QPushButton::clicked, [&](){
        auto den = denText->text().toStdString();
        auto prod = prodText->text().toStdString();
        try{
            service.addMedicamentReteta(den, prod);
        }
        catch (Error& err){
            QMessageBox::warning(this, "INFO!", QString::fromStdString(err.getMesaj()));
        }
    });
}

void RetetaGUI::ConnectAdaugaRandom() {
    QObject::connect(btAdaugaRandom, &QPushButton::clicked, [&](){
        int numar = sl->value();
        try {
            service.addMedicamenteRandom(numar);
        }
        catch (Error& err){
            QMessageBox::warning(this, "INFO!", QString::fromStdString(err.getMesaj()));
        }
    });
}

void RetetaGUI::ConnectGolesteReteta() {
    QObject::connect(btStergeTot, &QPushButton::clicked, [&](){
        service.deleteAllReteta();
    });
}

void RetetaGUI::ConnectExport() {
    QObject::connect(btExport, &QPushButton::clicked, [&](){
        auto file = fisier->text().toStdString();
        try {
            service.exportToFile(file);
        }
        catch (Error& err){
            QMessageBox::warning(this, "INFO!", QString::fromStdString(err.getMesaj()));
        }
    });
}

void RetetaGUI::ConnectSlLabel() {
    QObject::connect(sl, &QSlider::valueChanged, [&](){
        int nou = sl->value();
        val->setText(QString::fromStdString(std::to_string(nou)));
    });
}

void RetetaGUI::initConnect() {
    ConnectAdaugaRandom();
    ConnectAdaugaReteta();
    ConnectGolesteReteta();
    ConnectExport();
    ConnectSlLabel();
}

