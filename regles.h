#ifndef REGLES_H
#define REGLES_H

#include <QDialog>

namespace Ui {
class Regles;
}

class Regles : public QDialog
{
    Q_OBJECT

public:
    explicit Regles(QWidget *parent = nullptr);
    ~Regles();

private:
    Ui::Regles *ui;
};

#endif // REGLES_H
