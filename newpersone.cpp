#include "familytree.h"
#include "newpersone.h"
#include "ui_newpersone.h"

#include <QMessageBox>

typedef std::shared_ptr<Person> PersonPtr;

NewPersone::NewPersone(std::vector<PersonPtr> iAllFamily, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::NewPersone)
{
	ui->setupUi(this);
	ui->comboBox_3->addItem("чоловік", QVariant(true));
	ui->comboBox_3->addItem("жінка", QVariant(false));
	for(auto it : iAllFamily)
	{
		QString name = it->getName().mMiddleName + " " + it->getName().mFirstName + " " + it->getName().mLastName;
		if (it->getIsMale())
			ui->comboBox->addItem(name, QVariant(it->getID()));
		else
			ui->comboBox_2->addItem(name, QVariant(it->getID()));
	}
}

NewPersone::~NewPersone()
{
	delete ui;
}
void NewPersone::on_pbSubmit_clicked()
{
	PersonPtr p(new Person());
	p->setName(ui->leFirstName->text(),
			   ui->leMiddleName->text(),
			   ui->leLastName->text());
	p->setDateOfBirth(ui->dateEdit->date().day(), ui->dateEdit->date().month(), ui->dateEdit->date().year());
	p->setJob(ui->teJob->toPlainText());
	p->setBiography(ui->teBiography->toPlainText());
	FamilyTree::getInstance()->addNewPersone(p);
	int id = ui->comboBox->currentData().toInt();
	PersonPtr person = FamilyTree::getInstance()->findPersonById(id);
	p->setFather(person);
	id = ui->comboBox_2->currentData().toInt();
	person = FamilyTree::getInstance()->findPersonById(id);
	p->setMother(person);
	p->setIsMale(ui->comboBox_3->currentData().toBool());
	this->close();
//	QMessageBox::information(this, "any", p->toString());
}

void NewPersone::on_pbCancel_clicked()
{
	this->close();
}
