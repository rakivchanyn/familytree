#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>

class TreeWidget : public QWidget
{
	Q_OBJECT

public:
	explicit TreeWidget(QWidget *parent = 0);
	~TreeWidget();

};

#endif // TREEWIDGET_H
