//
// Created by Știube Denis on 31.03.2024.
//

#include "FarmacieGUI.h"
#include <iostream>
using std::cin;
using std::cout;

void FarmacieGUI::initGUI() {
    setLayout(lymain); // setarea layout ului principal
    left->addWidget(lista);
    QHBoxLayout* btF = new QHBoxLayout;
    btF->addWidget(btAdauga);
    btF->addWidget(btSterge);
    btF->addWidget(btModifica);
    left->addLayout(btF);
    btly1->addWidget(btSortDen);
    btly2->addWidget(btSortProd);
    btly2->addWidget(btSortSubstPret);
    btly1->addWidget(btUndo);
    btly2->addWidget(btExit);
    fly->addRow("Denumire", denText);
    fly->addRow("Pret", pretText);
    fly->addRow("Producator", prodText);
    fly->addRow("Substanta", substText);
    fly->addRow(btFiltruPret, filtruPret);
    fly->addRow(btFiltruSubst, filtruSubstText);
    filtruPret->setMaximum(999);
    filtruPret->setWrapping(true);
    right->addLayout(fly);
    right->addLayout(btly1);
    right->addLayout(btly2);
    lymain->addLayout(left);
    lymain->addLayout(right);
}

void FarmacieGUI::loadFarmacie() {
    for (Medicament& m : service.getAll()){
        lista->addItem(QString::fromStdString(m.getDenumire() + ", " + std::to_string(int(m.getPret())) + ", " + m.getProducator() + ", " + m.getSubst()));
    }
}


void FarmacieGUI::loadData() {
    loadFarmacie();
}

void FarmacieGUI::reload() {
    lista->clear();
    loadData();
}

void FarmacieGUI::ConnectList() {
    QObject::connect(lista, &QListWidget::itemClicked, [&](){
        auto item = lista->currentItem();
        auto text = item->text().toStdString();
        auto denumire = text.substr(0, text.find(',')); // tot pana la prima virgula
        denText->setText(QString::fromStdString(denumire));
        int poz = -1;
        // gasesc poztita celui de al 2 lea spatiu in text
        for (int i = 0; i < 2; i++){
            poz = text.find_first_of(' ', poz+1);
        }
        poz++;
        // producatorul este tot pana la prima virgula intalnita
        auto producator = text.substr(poz, text.find(',', poz)-poz);
        prodText->setText(QString::fromStdString(producator));
        pretText->setText("");
        substText->setText("");
    });
}

void FarmacieGUI::ConnectAdauga() {
    QObject::connect(btAdauga, &QPushButton::clicked, [&](){
        auto denumire = denText->text().toStdString();
        auto pret = pretText->text().toDouble();
        auto prod = prodText->text().toStdString();
        auto subst = substText->text().toStdString();
        try{
            service.addMedicamentFarmacie(denumire, pret, prod, subst);
            reload();
//            reloadFrec();
        }
        catch (Error& err){
            QMessageBox::warning(this, "INFO!", QString::fromStdString(err.getMesaj()));
        }
    });
}

void FarmacieGUI::ConnectSterge() {
    QObject::connect(btSterge, &QPushButton::clicked, [&](){
        auto denumire = denText->text().toStdString();
        auto prod = prodText->text().toStdString();
        try{
            service.deleteMedicamentFarmacie(denumire, prod);
            reload();
        }
        catch (Error& err){
            QMessageBox::warning(this, "INFO!", QString::fromStdString(err.getMesaj()));
        }
    });
}

void FarmacieGUI::ConnectModifica() {
    QObject::connect(btModifica, &QPushButton::clicked, [&]() {
        double newPret;
        if (!pretText->text().toStdString().empty())
            newPret = std::stod(pretText->text().toStdString());
        else
            newPret = 0;
        auto newSubst = substText->text().toStdString();
        auto denumire = denText->text().toStdString();
        auto prod = prodText->text().toStdString();
        try{
            service.updateGUI(denumire, prod, newPret, newSubst);
            reload();
        }
        catch (Error& err){
            QMessageBox::warning(this, "INFO!", QString::fromStdString(err.getMesaj()));
        }
    });
}

void FarmacieGUI::ConnectSortDen() {
    QObject::connect(btSortDen, &QPushButton::clicked, [&](){
        vector<Medicament> sortatDen = service.sortareMedicamenteDenumire(true);
        QWidget* w = new QWidget;
        QVBoxLayout* ly = new QVBoxLayout;
        w->setLayout(ly);
        QListWidget* sortate = new QListWidget;
        ly->addWidget(sortate);
        QPushButton* bt = new QPushButton{"Iesire"};
        ly->addWidget(bt);
        for (Medicament& m : sortatDen){
            sortate->addItem(QString::fromStdString(m.getDenumire() + ", " + std::to_string(int(m.getPret())) + ", " + m.getProducator() + ", " + m.getSubst()));
        }
        w->show();
        QObject::connect(bt, &QPushButton::clicked, [w](){
            w->close();
        });
    });
}

void FarmacieGUI::ConnectSortProd() {
    QObject::connect(btSortProd, &QPushButton::clicked, [&](){
        vector<Medicament> sortatSubst = service.sortareMedicamenteProducator(true);
        QWidget* w = new QWidget;
        QVBoxLayout* ly = new QVBoxLayout;
        w->setLayout(ly);
        QListWidget* sortate = new QListWidget;
        ly->addWidget(sortate);
        QPushButton* bt = new QPushButton{"Iesire"};
        ly->addWidget(bt);
        for (Medicament& m : sortatSubst){
            sortate->addItem(QString::fromStdString(m.getDenumire() + ", " + std::to_string(int(m.getPret())) + ", " + m.getProducator() + ", " + m.getSubst()));
        }
        w->show();
        QObject::connect(bt, &QPushButton::clicked, [w](){
            w->close();
        });
    });
}

void FarmacieGUI::ConnectSortSubstPret() {
    QObject::connect(btSortSubstPret, &QPushButton::clicked, [&](){
        vector<Medicament> sortat = service.sortareMedicamenteSubstPret(true);
        QWidget* w = new QWidget;
        QVBoxLayout* ly = new QVBoxLayout;
        w->setLayout(ly);
        QListWidget* sortate = new QListWidget;
        ly->addWidget(sortate);
        QPushButton* bt = new QPushButton{"Iesire"};
        ly->addWidget(bt);
        for (Medicament& m : sortat){
            sortate->addItem(QString::fromStdString(m.getDenumire() + ", " + std::to_string(int(m.getPret())) + ", " + m.getProducator() + ", " + m.getSubst()));
        }
        w->show();
        QObject::connect(bt, &QPushButton::clicked, [w](){
            w->close();
        });
    });
}

void FarmacieGUI::ConnectFiltruPret() {
    QObject::connect(btFiltruPret, &QPushButton::clicked, [&](){
        int pret = filtruPret->value();
        vector<Medicament> filtru = service.filtruPret(pret);
        QWidget* w = new QWidget;
        QVBoxLayout* ly = new QVBoxLayout;
        w->setLayout(ly);
        QListWidget* lista = new QListWidget;
        ly->addWidget(lista);
        QPushButton* bt = new QPushButton{"Iesire"};
        ly->addWidget(bt);
        for (auto& m : filtru){
            lista->addItem(QString::fromStdString(m.getDenumire() + ", " + std::to_string(int(m.getPret())) + ", " + m.getProducator() + ", " + m.getSubst()));
        }
        w->show();
        QObject::connect(bt, &QPushButton::clicked, [w](){
            w->close();
        });
    });
}

void FarmacieGUI::ConnectFiltruSubst() {
    QObject::connect(btFiltruSubst, &QPushButton::clicked, [&](){
        string subst = filtruSubstText->text().toStdString();
        vector<Medicament> filtru = service.filtruSubst(subst);
        QWidget* w = new QWidget;
        QVBoxLayout* ly = new QVBoxLayout;
        w->setLayout(ly);
        QListWidget* lista = new QListWidget;
        for (auto& m : filtru){
            lista->addItem(QString::fromStdString(m.getDenumire() + ", " + std::to_string(int(m.getPret())) + ", " + m.getProducator() + ", " + m.getSubst()));
        }
        ly->addWidget(lista);
        QPushButton* bt = new QPushButton{"Iesire"};
        ly->addWidget(bt);
        w->show();
        QObject::connect(bt, &QPushButton::clicked, [w](){
           w->close();
        });
    });
}


void FarmacieGUI::ConnectUndo() {
    QObject::connect(btUndo, &QPushButton::clicked, [&](){
        try{
            service.undo();
            reload();
        }
        catch (Error& err){ 
            QMessageBox::warning(this, "INFO!", QString::fromStdString(err.getMesaj()));
        }
    });
}

void FarmacieGUI::ConnectExit() {
    QObject::connect(btExit, &QPushButton::clicked, [&](){
        close();
    });
}

void FarmacieGUI::initConnect() {
    ConnectAdauga();;
    ConnectSterge();
    ConnectModifica();
    ConnectSortDen();
    ConnectSortProd();
    ConnectSortSubstPret();
    ConnectFiltruPret();
    ConnectFiltruSubst();
    ConnectUndo();
    ConnectList();
    ConnectExit();
}


