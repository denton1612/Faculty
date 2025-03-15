//
// Created by Știube Denis on 31.03.2024.
//

#ifndef LAB_6_PB_7_FARMACIEGUI_H
#define LAB_6_PB_7_FARMACIEGUI_H
#include "../service/service.h"
#include <utility>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QTableWidget>
#include <QBoxLayout>
#include <QSpinBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDialog>
#include <QMessageBox>
#include "qdebug.h"
using std::pair;


class FarmacieGUI : public QWidget{

private:
    Service& service;
    QListWidget* lista = new QListWidget; // lista unde se stocheaza medicamentele
    QHBoxLayout* lymain = new QHBoxLayout; // layout ul principal al ferestrei
    QFormLayout* fly = new QFormLayout;
    QVBoxLayout* left = new QVBoxLayout; // layout ul stang
    QVBoxLayout* right = new QVBoxLayout; // layout ul din dreapta
    QHBoxLayout* btly1 = new QHBoxLayout;
    QHBoxLayout* btly2 = new QHBoxLayout;
    QLineEdit* denText = new QLineEdit; // casuta pt denumire
    QLineEdit* pretText = new QLineEdit; // casuta pt pret
    QLineEdit* prodText = new QLineEdit; // casuta pt producator
    QLineEdit* substText = new QLineEdit; // casuta pt substanta
    QLineEdit* filtruSubstText = new QLineEdit; // casuta pt filtrarea medicamentelor dupa substanta

    // butoanele ferestrei
    QPushButton* btAdauga = new QPushButton{"Adauga"};
    QPushButton* btSterge = new QPushButton{"Sterge"};
    QPushButton* btModifica = new QPushButton{"Modifica"};
    QPushButton* btSortDen = new QPushButton{"Sortare dupa denumire"};
    QPushButton* btSortProd= new QPushButton{"Sortare dupa producator"};
    QPushButton* btSortSubstPret = new QPushButton{"Sortare dupa subst si pret"};
    QPushButton* btFiltruPret = new QPushButton{"Filtrare dupa pret"};
    QPushButton* btFiltruSubst = new QPushButton{"Filtrare dupa subst"};
    QPushButton* btUndo = new QPushButton{"Undo"};
    QPushButton* btExit = new QPushButton{"Exit"};

    // spinbox pt filtrarea dupa pret
    QSpinBox* filtruPret = new QSpinBox;

    QLabel* value = new QLabel;
    void initGUI(); // initializarea aspectului ferestrei
    void loadFarmacie(); // incarcarea in lista a medicamentelor
    void loadData(); //
    void initConnect(); // initializarea conexiunilor intre actiunile user ului si metode
    void ConnectAdauga();
    void ConnectSterge();
    void ConnectModifica();
    void ConnectSortDen();
    void ConnectSortProd();
    void ConnectSortSubstPret();
    void ConnectFiltruPret();
    void ConnectFiltruSubst();
    void ConnectUndo();
    void ConnectExit();
    void ConnectList();
    void reload();

public:
    FarmacieGUI(Service& s): service{s}, QWidget(){
        loadData();
        initGUI();
        initConnect();
    };

    void run(){
        show();
    }
};
#endif //LAB_6_PB_7_FARMACIEGUI_H
