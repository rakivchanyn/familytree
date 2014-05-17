#include "familytree.h"
#include "ui_familytree.h"

FamilyTree::FamilyTree(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FamilyTree)
{
    ui->setupUi(this);
}

FamilyTree::~FamilyTree()
{
    delete ui;
}
