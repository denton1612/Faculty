//
// Created by Știube Denis on 11.07.2024.
//

#ifndef MELODII_2_GUI_H
#define MELODII_2_GUI_H
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>
#include <QSlider>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <QTableView>
#include "../TableModel/TableModel.h"

class gui: public QWidget{
private:
    Service & s;
    TableModel* tm = new TableModel{s};
    QTableView* tv = new QTableView;
    QVBoxLayout* lymain = new QVBoxLayout;
    QFormLayout* rightUp = new QFormLayout;
    QHBoxLayout* rightBot = new QHBoxLayout;
    QHBoxLayout* right = new QHBoxLayout;
    QVBoxLayout* last = new QVBoxLayout;
    QHBoxLayout* up = new QHBoxLayout;
    QHBoxLayout* bot = new QHBoxLayout;
    QSlider* sl = new QSlider;
    QLabel* value = new QLabel;
    QLineEdit* id = new QLineEdit;
    QLineEdit* title = new QLineEdit;
    QLineEdit* artist = new QLineEdit;
    QLineEdit* rank = new QLineEdit;
    QPushButton* btAdd = new QPushButton{"Add"};
    QPushButton* btRemove = new QPushButton{"Remove"};
    QPushButton* btUpdate = new QPushButton{"Update"};
    void initGUI();
    void initConnect();
    void initAdd();
    void initRemove();
    void completeOnClick();
    void ConnectSlider();
    void initUpdate();

public:
    gui(Service & s): s{s} {
        initGUI();
        initConnect();
    }

    ~gui() = default;
};


#endif //MELODII_2_GUI_H
