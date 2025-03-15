//
// Created by Știube Denis on 20.05.2024.
//

#ifndef SIMULAREOFICIAL_GUI_H
#define SIMULAREOFICIAL_GUI_H
#include <QApplication>
#include <QListWidget>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QTableWidget>
#include <QPushButton>
#include "../service/Service.h"

class GUI : public QWidget{
private:
    Service & s;
    QHBoxLayout* lymain = new QHBoxLayout;
    QFormLayout* fly = new QFormLayout;
    QListWidget* list = new QListWidget;
    QPushButton* btsort = new QPushButton{"Sortare Nume"};
    QPushButton* d = new QPushButton{"desen"};
    QPushButton* f = new QPushButton{"fotografie"};
    QPushButton* m = new QPushButton{"muzica"};
    QPushButton* i = new QPushButton{"informatica"};
    QPushButton* j = new QPushButton{"jurnalism"};
    QVBoxLayout* dreapta = new QVBoxLayout;
    QLineEdit* ateliere = new QLineEdit;
    QTableWidget* elevi = new QTableWidget{10, 10};
    void loadData();
    void initGUI();
    void connectSort();
    void connectList();
    void connectAteliere();
    void initConnect();

public:
    GUI(Service & s): s{s}, QWidget() {
        loadData();
        initGUI();
        initConnect();
    }
};


#endif //SIMULAREOFICIAL_GUI_H
