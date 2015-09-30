#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwidget.h"
#include "familytree.h"

#include <QMenuBar>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	mFamilyTreeWidget(new FamilyTreeW())
{
	ui->setupUi(this);
	setCentralWidget(mFamilyTreeWidget);
	createActions();
	createMenus();
	setWindowTitle(tr("Family Tree"));
	setMinimumSize(150, 150);
	resize(480, 320);
}

MainWindow::~MainWindow()
{
	delete ui;
	delete mFamilyTreeWidget;
}

void MainWindow::createActions()
{
	mOpenAct = new QAction(tr("&Open"), this);
	mOpenAct->setShortcut(QKeySequence::Open);
	mOpenAct->setStatusTip(tr("Open file with family tree"));
	connect(mOpenAct, SIGNAL(triggered()), this, SLOT(open()));
}

void MainWindow::createMenus()
{
	mFileMenu = menuBar()->addMenu(tr("&File"));
	mFileMenu->addAction(mOpenAct);
}

void MainWindow::open()
{
	std::string fileName = (QFileDialog::getOpenFileName(this, tr("Open file"), "./", "Text File (*.xml)")).toStdString();
	FamilyTree::getInstance()->openTree(fileName);
}
