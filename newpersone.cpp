#include <QMessageBox>
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
    p->setName(ui->leFirstName->text().toStdString(),
               ui->leMiddleName->text().toStdString(),
               ui->leLastName->text().toStdString());
    p->setDateOfBirst(ui->dateEdit->date().day(), ui->dateEdit->date().month(), ui->dateEdit->date().year());
    p->setJob(ui->teJob->toPlainText().toStdString());
    p->setBiography(ui->teBiography->toPlainText().toStdString());
    FamilyTree::getInstance()->addNewPersone(p);
//    QMessageBox::information(this, "any", p->toString());
}
