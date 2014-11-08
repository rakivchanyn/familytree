#include <QMessageBox>

#include "familytree.h"
#include "newpersone.h"
#include "ui_newpersone.h"

NewPersone::NewPersone(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewPersone)
{
    ui->setupUi(this);
}

NewPersone::~NewPersone()
{
    delete ui;
}
void NewPersone::on_pbSubmit_clicked()
{
    Persone* p = new Persone();
    p->setName(ui->leFirstName->text(),
               ui->leMiddleName->text(),
               ui->leLastName->text());
    p->setDateOfBirth(ui->dateEdit->date().day(), ui->dateEdit->date().month(), ui->dateEdit->date().year());
    p->setJob(ui->teJob->toPlainText());
    p->setBiography(ui->teBiography->toPlainText());
    FamilyTree::getInstance()->addNewPersone(p);
    this->close();
//    QMessageBox::information(this, "any", p->toString());
}

void NewPersone::on_pbCancel_clicked()
{
    this->close();
}
