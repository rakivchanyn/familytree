#include "TreeWidget.h"

#include <QPushButton>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QVBoxLayout>

TreeWidget::TreeWidget(QWidget *parent) :
	QWidget(parent)
{
	QHBoxLayout* layout = new QHBoxLayout;
	QVBoxLayout* vlayout = new QVBoxLayout;
	for (int i = 0; i < 3; ++i)
	{
		QPushButton* button = new QPushButton("button");
		QPushButton* button2 = new QPushButton("button2");
		QPushButton* button3 = new QPushButton("button3");
		QGridLayout* glayout = new QGridLayout;
		glayout->addWidget(button, 0, 1);
		glayout->addWidget(button2, 1, 0);
		glayout->addWidget(button3, 1, 2);
		if (i == 1)
			vlayout->addLayout(glayout);
		else
			layout->addLayout(glayout);
	}

	vlayout->addLayout(layout);
	this->setLayout(vlayout);
}

TreeWidget::~TreeWidget()
{
}
