#ifndef NEWPERSONE_H
#define NEWPERSONE_H

#include "person.h"

#include <QWidget>

typedef std::shared_ptr<Person> PersonPtr;

namespace Ui {
class NewPersone;
}

class NewPersone : public QWidget
{
	Q_OBJECT

public:
	explicit NewPersone(std::vector<PersonPtr> iAllFamily, QWidget *parent = 0);
	~NewPersone();

private slots:
	void on_pbSubmit_clicked();

	void on_pbCancel_clicked();

private:
	Ui::NewPersone *ui;
};

#endif // NEWPERSONE_H
