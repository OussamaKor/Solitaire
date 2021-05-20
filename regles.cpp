#include "regles.h"
#include "ui_regles.h"

Regles::Regles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Regles)
{
    ui->setupUi(this);
    ui->regle->setText("-Pour gagner il suffit de remplir les 4 piles couleurs par des valeurs de As jusqu'à Roi de meme Couleur \n") ;
    ui->regle->setText(ui->regle->text()+"-Dans le tableau il suffit de créer des suites décroissantes en alternant la \n couleur rouge et la noire dans les différentes colonnes. \n") ;
    ui->regle->setText(ui->regle->text()+"-Quand il est impossible de déplacer une carte, il faut alors piocher une carte de la pioche.\n") ;
    ui->regle->setText(ui->regle->text()+"-les colonnes sont numérotés de 1 à 7 et les piles de couleurs de 11 a 14 \n") ;
    ui->regle->setText(ui->regle->text()+"-Cliquer sur Astuce si tu ne trouve Aucun déplacement possible \n") ;
    ui->regle->setText(ui->regle->text()+"-la premiere case à remplir est pour la pile ou la colonne source \n") ;
    ui->regle->setText(ui->regle->text()+"-la deuxieme case à remplir est pour la pile ou la colonne destination \n") ;
    ui->regle->setText(ui->regle->text()+"-la troisieme case à remplir est pour le nombre de carte \n") ;
    ui->regle->setText(ui->regle->text()+"-pour faire un déplacement du pioche vers le tableau ou la pile \n il suffit de remplire la 2eme case \n") ;
    ui->regle->setText(ui->regle->text()+"-pour faire un déplacement d'une colonne du tableau vers une pile \n il suffit de remplire les deux premiers cases \n") ;
    ui->regle->setText(ui->regle->text()+"-pour faire un déplacement d'une colonne du tableau vers une autre \n il suffit faut remplire les 3 cases \n") ;
}

Regles::~Regles()
{
    delete ui;
}

