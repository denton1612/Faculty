//
// Created by Știube Denis on 25.06.2024.
//

#include "GUI.h"

void GUI::initGUI() {
    setLayout(lymain);
    lymain->addWidget(tv);
    tv->setModel(tm);
}