#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "game.h"
#include "Tableau.h"
#include "pioche.h"
#include "pilecouleur.h"
#include "carte.h"
#include "game.h"
#include <stack>
#include <stdlib.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent ,stack<Carte> ,stack<Carte> );
    ~MainWindow();

private slots:
    void on_pushButton_5_clicked();

    void on_Commencer_clicked();

    void on_pioche_clicked();

    void on_Accepte_clicked();

    void on_Astuce_clicked();
    void Affiche_cartes(Carte ,int) ;
    void Affiche_cartes1(Carte ,int,int) ;
    void Affiche_empty(int,int) ;

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Tableau T;
    Pioche P ;
    PileCouleur PC;
};
#endif // MAINWINDOW_H
