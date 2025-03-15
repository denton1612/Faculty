//
// Created by Știube Denis on 27.06.2024.
//

#ifndef EXAMENOFICIAL_PARCAREGUI_H
#define EXAMENOFICIAL_PARCAREGUI_H
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "../Service/service.h"

class parcaregui: public QWidget, public Observer{

private:
    service & s;
    Parcare & p;
    QVBoxLayout* lymain = new QVBoxLayout;
    vector<QPushButton*> bts;
    vector<QHBoxLayout*> lys;
    void initGUI();
    void initConnect();
    void update() override;

public:
    parcaregui(service & s, Parcare & p): s{s}, p{p} {
        initGUI();
        initConnect();
    }
};


#endif //EXAMENOFICIAL_PARCAREGUI_H
