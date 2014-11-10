#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mWidget(new FamilyTreeW())
{
    ui->setupUi(this);
    setCentralWidget(mWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mWidget;
}
