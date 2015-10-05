#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "newpersone.h"
#include "TreeWidget.h"
#include "person.h"

#include <QMainWindow>
#include <QGridLayout>

typedef std::shared_ptr<Person> PersonPtr;

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
private:
	void updateView();

private slots:

	void on_btShowFamilyTree_clicked();
	void on_btAddNewPersone_clicked();
	void on_pbSaveTree_clicked();

private:
	Ui::FamilyTreeW *ui;
	QMenuBar* mMenuBar;
	QGridLayout* mGridLayOut;
	TreeWidget* mTreeWidget;

};

#endif // FAMILYTREE_H
