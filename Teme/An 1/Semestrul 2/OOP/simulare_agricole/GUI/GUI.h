//
// Created by Știube Denis on 25.06.2024.
//

#ifndef SIMULARE_AGRICOLE_GUI_H
#define SIMULARE_AGRICOLE_GUI_H
#include "../Controller/Controller.h"
#include "../TableModel/TableModel.h"
#include <QWidget>
#include <QTableView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QRadioButton>
#include <QPushButton>

class GUI: public QWidget {
private:
    Controller & cont;
    TableModel* tm = new TableModel{cont.getAll()};
    QTableView* tv = new QTableView;
    QHBoxLayout* lymain = new QHBoxLayout;

    void initGUI();

public:
    GUI(Controller & c): cont{c}, QWidget() {
        initGUI();
    }
};


#endif //SIMULARE_AGRICOLE_GUI_H
