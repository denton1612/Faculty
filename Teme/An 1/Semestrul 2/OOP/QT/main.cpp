#include <QApplication>
#include "qlabel.h"
#include "qpushbutton.h"
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QList>
#include <iostream>
#include <list>

int main(int argc, char *argv[]) {
    QApplication a{argc, argv};
    QWidget w;
    QVBoxLayout* vl = new QVBoxLayout;
    QLineEdit* l1 = new QLineEdit;
    QLineEdit* l2 = new QLineEdit;
    vl->addWidget(l1);
    vl->addWidget(l2);
    w.setLayout(hl);
    QHBoxLayout* hl = new QHBoxLayout;
    w.setLayout(hl);
    QListWidget* lw = new QListWidget;
    hl->addWidget(lw);
    hl->addLayout(vl);
    w.show();
    return a.exec();
}
