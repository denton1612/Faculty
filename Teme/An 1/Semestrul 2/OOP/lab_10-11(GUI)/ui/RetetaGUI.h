//
// Created by Știube Denis on 21.05.2024.
//

#ifndef LAB_6_PB_7_RETETAGUI_H
#define LAB_6_PB_7_RETETAGUI_H
#include "../service/service.h"
#include "../Observer/Observable.h"
#include "../Observer/Observer.h"
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

class RetetaGUI : public QWidget, public Observer{
private:
    Service & service;
    QTableWidget* reteta = new QTableWidget{10, 4};
    QPushButton* btAdaugaRandom = new QPushButton{"Adauga reteta random"};
    QPushButton* btAdaugaReteta = new QPushButton{"Adauga reteta"};
    QPushButton* btStergeTot = new QPushButton{"Goleste reteta"};
    QPushButton* btExport = new QPushButton{"Exporta"};
    QLineEdit* denText = new QLineEdit;
    QLineEdit* prodText = new QLineEdit;
    QLineEdit* fisier = new QLineEdit; // casuta pt fisier
    QSlider* sl = new QSlider(Qt::Vertical);
    QLabel* val = new QLabel;
    void loadReteta();
    void initGUI();
    void ConnectExport();
    void ConnectAdaugaReteta();
    void ConnectAdaugaRandom();
    void ConnectGolesteReteta();
    void ConnectSlLabel();
    void initConnect();
    void update() override{
        loadReteta();
    }
public:
    explicit RetetaGUI(Service& s): service{s}, QWidget(), Observer() {
        initGUI();
        initConnect();
        loadReteta();
//        service.addObserver(this);
    }
    ~RetetaGUI() override {
//        service.removeObserver(this);
    }
};


#endif //LAB_6_PB_7_RETETAGUI_H
