#ifndef FAMILYTREE_H
#define FAMILYTREE_H

#include <QWidget>
#include <persone.h>

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

private:
    Ui::FamilyTree *ui;
    std::vector<Persone*> mAllFamily;
};

#endif // FAMILYTREE_H
