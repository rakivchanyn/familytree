#include "familytree.h"
#include "ui_familytree.h"

FamilyTree::FamilyTree(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FamilyTree)
{
    ui->setupUi(this);
    mWiget = new NewPersone();
}

FamilyTree::~FamilyTree()
{
    delete ui;
}

void FamilyTree::on_btShowFamilyTree_clicked()
{
    mWiget->show();
}
