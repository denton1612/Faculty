//
// Created by Știube Denis on 20.05.2024.
//

#ifndef SIMULARE2_CONSOLE_H
#define SIMULARE2_CONSOLE_H
#include "../service/service.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QMessageBox>
#include <QWidget>


class Console : public QWidget{
private:
    service& service;
    QHBoxLayout* lymain = new QHBoxLayout;
    QFormLayout* fly = new QFormLayout;
    QPushButton* btSterge = new QPushButton{"Sterge"};
    QPushButton* fltSupr = new QPushButton{"Filtreaza suprafata"};
    QPushButton* fltPret = new QPushButton{"Filtreaza pret"};
    QListWidget* list = new QListWidget;
    QListWidget* flt = new QListWidget;
    QLineEdit* pretmin = new QLineEdit;
    QLineEdit* pretmax = new QLineEdit;
    QLineEdit* suprmin = new QLineEdit;
    QLineEdit* suprmax = new QLineEdit;
    QLineEdit* strada = new QLineEdit;
    QLineEdit* supr = new QLineEdit;
    QLineEdit* pret = new QLineEdit;
    void loadData();
    void initGUI();
    void initConnect();
    void connectSterge();
    void connectList();
    void connectFiltreazaSupr();
    void connectFiltreazaPret();

public:
    Console(class service & s): service{s}, QWidget() {
        loadData();
        initGUI();
        initConnect();
    }
};


#endif //SIMULARE2_CONSOLE_H
