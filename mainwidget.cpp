#include "familytree.h"
#include "mainwidget.h"
#include "ui_familytree.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

FamilyTreeW::FamilyTreeW(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::FamilyTreeW),
	mTreeWidget(new TreeWidget())
{
	ui->setupUi(this);
	mWidget = new NewPersone();
	mGridLayOut = new QGridLayout();
	QVBoxLayout* vlayout = new QVBoxLayout;
	QHBoxLayout* hlayout = new QHBoxLayout;
	vlayout->addWidget(mTreeWidget);
	hlayout->addWidget(ui->btAddNewPersone);
	hlayout->addWidget(ui->btShowFamilyTree);
	hlayout->addWidget(ui->pbSaveTree);
	vlayout->addLayout(hlayout);
//	mGridLayOut->addWidget(mWidget);
//	mGridLayOut->addWidget(mTreeWidget);
//	this->setLayout(mGridLayOut);
	this->setLayout(vlayout);
}

FamilyTreeW::~FamilyTreeW()
{
	delete ui;
	delete mTreeWidget;
}

void FamilyTreeW::updateView()
{
	QPushButton* button = new QPushButton("this");
	mGridLayOut->addWidget(button, 0, 1);
	this->show();
}

void FamilyTreeW::on_btAddNewPersone_clicked()
{
	mWidget->show();
}

void FamilyTreeW::on_btShowFamilyTree_clicked()
{
	updateView();
}

void FamilyTreeW::on_pbSaveTree_clicked()
{
	FamilyTree::getInstance()->saveTree();
}
