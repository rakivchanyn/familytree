#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QMainWindow>

#include "newpersone.h"

namespace Ui {
class FamilyTreeW;
}

class FamilyTreeW : public QWidget
{
	Q_OBJECT

public:
	explicit FamilyTreeW(QWidget *parent = 0);
	~FamilyTreeW();
	void showTree();

private slots:void on_btShowFamilyTree_clicked();

	void on_btAddNewPersone_clicked();

	void on_pbSaveTree_clicked();

private:
	Ui::FamilyTreeW *ui;
	NewPersone* mWidget;
	QMenuBar* mMenuBar;
};

#endif // FAMILYTREE_H
