#ifndef FAMILYTREE_H
#define FAMILYTREE_H

#include <QWidget>

#include "persone.h"
#include "newpersone.h"


namespace Ui {
class FamilyTree;
}

class FamilyTree : public QWidget
{
    Q_OBJECT

public:
    explicit FamilyTree(QWidget *parent = 0);
    ~FamilyTree();
    void showTree();
    void addNewPersone();

private slots:
    void on_btShowFamilyTree_clicked();

private:
    Ui::FamilyTree *ui;
    std::vector<Persone*> mAllFamily;
    NewPersone* mWiget;
};

#endif // FAMILYTREE_H
