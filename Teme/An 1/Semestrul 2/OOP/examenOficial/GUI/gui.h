//
// Created by Știube Denis on 27.06.2024.
//

#ifndef EXAMENOFICIAL_GUI_H
#define EXAMENOFICIAL_GUI_H
#include "../Service/service.h"
#include "parcaregui.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <QPushButton>
#include <QLineEdit>
#include <QTableWidget>


class gui: public QWidget, public Observer{
private:
    service & s;
    QHBoxLayout* lymain = new QHBoxLayout;
    QVBoxLayout* left = new QVBoxLayout;
    QVBoxLayout* right = new QVBoxLayout;
    QTableWidget* table = new QTableWidget{s.getSize(), 4};
    QHBoxLayout* bts = new QHBoxLayout;
    QHBoxLayout* bts1 = new QHBoxLayout;
    QPushButton* btAdd = new QPushButton{"add"};
    QPushButton* btUpd = new QPushButton{"update"};
    QPushButton* btRan = new QPushButton{"genereaza"};
    QPushButton* btParc = new QPushButton{"parcare"};
    QLineEdit* adr = new QLineEdit;
    QLineEdit* linii = new QLineEdit;
    QLineEdit* col = new QLineEdit;
    QLineEdit* stare = new QLineEdit;
    QFormLayout* fly = new QFormLayout;
    void initGUI();
    void reload();
    void initConnect();
    void ConnectAdd();
    void ConnectUpdate();
    void ConnectGenerare();
    void ConnectParcare();
    void update() override;

public:
    gui(service & s): s{s} {
        s.addObserver(this);
        reload();
        initGUI();
        initConnect();
    }
};


#endif //EXAMENOFICIAL_GUI_H
