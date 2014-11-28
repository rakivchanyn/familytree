#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mainwidget.h"

#include <QMainWindow>
#include <QMenu>
#include <QAction>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void open();

private:
	void createActions();
	void createMenus();

private:
	QMenu* mFileMenu;
	QAction* mOpenAct;

private:
	Ui::MainWindow *ui;
	FamilyTreeW* mWidget;
};

#endif // MAINWINDOW_H
