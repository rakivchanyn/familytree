#ifndef NEWPERSONE_H
#define NEWPERSONE_H

#include <QWidget>
#include "familytree.h"

namespace Ui {
class NewPersone;
}

class NewPersone : public QWidget
{
    Q_OBJECT

public:
    explicit NewPersone(QWidget *parent = 0);
    ~NewPersone();

private slots:
    void on_pbSubmit_clicked();

private:
    Ui::NewPersone *ui;
};

#endif // NEWPERSONE_H
