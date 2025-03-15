//
// Created by Știube Denis on 26.06.2024.
//

#ifndef MASINI_GUI_H
#define MASINI_GUI_H
#include <QWidget>
#include <QTableView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include "../TableModel/TableModel.h"
#include "../Service/service.h"

class gui: public QWidget {
private:
    service & s;
    void initGUI();
    void initConnect();
    void reload();
    QVBoxLayout* lymain = new QVBoxLayout;
    QHBoxLayout* lybts = new QHBoxLayout;
    TableModel* tm = new TableModel(s.sortNri());
    QTableView* tv = new QTableView;
    QPushButton* btPlus = new QPushButton{"+"};
    QPushButton* btMinus = new QPushButton{"-"};
    QPushButton* btUndo = new QPushButton{"undo"};
    QPushButton* btRedo = new QPushButton{"redo"};
    QPushButton* btDel = new QPushButton{"delete"};

public:
    gui(service & s): s{s}, QWidget() {
        initGUI();
        initConnect();
    }
};


#endif //MASINI_GUI_H
