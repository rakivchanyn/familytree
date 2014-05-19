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
