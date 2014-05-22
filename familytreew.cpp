#include "familytreew.h"
#include "ui_familytree.h"

FamilyTreeW::FamilyTreeW(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FamilyTreeW)
{
    ui->setupUi(this);
    mWidget = new NewPersone();
}

FamilyTreeW::~FamilyTreeW()
{
    delete ui;
}

void FamilyTreeW::on_btAddNewPersone_clicked()
{
    mWidget->show();
}

void FamilyTreeW::on_btShowFamilyTree_clicked()
{

}
