#ifndef FAMILYTREE_H
#define FAMILYTREE_H

#include <QWidget>

#include "newpersone.h"


namespace Ui {
class FamilyTreeW;
}

class FamilyTreeW : public QWidget
{
    Q_OBJECT

public:
    explicit FamilyTreeW(QWidget *parent = 0);
    ~FamilyTreeW();
    void showTree();

private slots:void on_btShowFamilyTree_clicked();

    void on_btAddNewPersone_clicked();

private:
    Ui::FamilyTreeW *ui;
    NewPersone* mWidget;
};

#endif // FAMILYTREE_H
