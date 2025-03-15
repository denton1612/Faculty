//
// Created by Știube Denis on 27.06.2024.
//

#include "parcaregui.h"

void parcaregui::initGUI() {
    setLayout(lymain);
    int linii = p.getLinii();
    int col = p.getCol();
    auto stare = p.getStare();
    for (int i = 0; i < linii; i++){
        lys.push_back(new QHBoxLayout);
        for (int j = 0; j < col; j++) {
            if (stare[i*col + j] == 'X') {
                QPushButton *bt = new QPushButton{"X"};
                bts.push_back(bt);
                lys[i]->addWidget(bt);
            }
            else {
                QPushButton *bt = new QPushButton{"-"};
                bts.push_back(bt);
                lys[i]->addWidget(bt);
            }
        }
    }
    for (auto & ly : lys)
        lymain->addLayout(ly);
}

void parcaregui::initConnect() {
    for (auto & bt : bts) {
        int i = 0;
        QObject::connect(bt, &QPushButton::clicked, [&]() {
            if (bt->text() == "X")
                bt->setText("-");
            else
                bt->setText("X");
        });
        i++;
    }
}

void parcaregui::update() {

}