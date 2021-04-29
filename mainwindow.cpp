#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include "game.h"
#include "Tableau.h"
#include "pioche.h"
#include "pilecouleur.h"
#include "carte.h"
#include "game.h"
#include <stack>
#include <stdlib.h>
#include <QDebug>
#include <QPixmap>
#include <QPainter>
using namespace std  ;

MainWindow::MainWindow(QWidget *parent,stack<Carte> S,stack<Carte> S1): QMainWindow(parent=nullptr), ui (new Ui::MainWindow),T(S1),P(S)
{
    ui->setupUi(this);
    //Ch = ui->textEdit->toPlainText() ;
    //ui->cartejoueur1->setText(ui->cartejoueur1->text()+ "")
    //ui->cartejoueur1->setPixmap(QPixmap(":/images/Jd.gif"));//kif bish n7ot kaaba barka nekteb ken star hedha
    //const QPixmap* pixmap1 = ui->cartejoueur1->pixmap(); --> yjiib le9dim lkoll
   /*QPixmap *pixmap=new QPixmap(71, 96*(i));
    //tosna3 les dim mtal war9aa
   pixmap->fill(Qt::transparent);
   QPainter *painter=new QPainter(pixmap);
   painter->drawPixmap(0, 0, 71, 96*(i-1), *pixmap1);
   painter->drawPixmap(0, 20*i, 71, 96, QPixmap(":/images/Jh"));
   painter->end();
   ui->cartejoueur1->setPixmap(*pixmap)*/
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pushButton_5_clicked()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

void MainWindow::on_Commencer_clicked()
{
      ui->pioch->setPixmap(QPixmap(":/images/empty.gif")) ;
      Carte C1 ;
      C1=T.getColonne(0).top() ;
      Carte::Formes F;
      Carte::Valeurs V;
      F=C1.getForme() ;
      V=C1.getValeur() ;
      Affiche_cartes1(C1,1,1) ;
      //ui->colonne1->setText('('+QString::number(V)+','+QString::number(F) + ')') ;
      Carte C2 ;
      C2=T.getColonne(1).top() ;
      F=C2.getForme() ;
      V=C2.getValeur() ;
      Affiche_empty(2,1) ;
      Affiche_cartes1(C2,2,2) ;
      //ui->colonne2->setText("\n (" +QString::number(V)+","+QString::number(F) + ")") ;
      Carte C3 ;
      C3=T.getColonne(2).top() ;
      F=C3.getForme() ;
      V=C3.getValeur() ;
      Affiche_empty(3,1) ;
      Affiche_empty(3,2) ;
      Affiche_cartes1(C3,3,3) ;
      //ui->colonne3->setText("\n \n ("+QString::number(V)+','+QString::number(F) + ')') ;
      Carte C4 ;
      C4=T.getColonne(3).top() ;
      F=C4.getForme() ;
      V=C4.getValeur() ;
      Affiche_empty(4,1) ;
      Affiche_empty(4,2) ;
      Affiche_empty(4,3) ;
      Affiche_cartes1(C4,4,4) ;
      //ui->colonne4->setText("\n \n \n ( "+QString::number(V)+','+QString::number(F) + ')') ;
      Carte C5 ;
      C5=T.getColonne(4).top() ;
      F=C5.getForme() ;
      V=C5.getValeur() ;
      Affiche_empty(5,1) ;
      Affiche_empty(5,2) ;
      Affiche_empty(5,3) ;
      Affiche_empty(5,4) ;
      Affiche_cartes1(C5,5,5) ;
      //ui->colonne5->setText("\n \n \n \n ( "+QString::number(V)+','+QString::number(F) + ')') ;
      Carte C6 ;
      C6=T.getColonne(5).top() ;
      F=C6.getForme() ;
      V=C6.getValeur() ;
      Affiche_empty(6,1) ;
      Affiche_empty(6,2) ;
      Affiche_empty(6,3) ;
      Affiche_empty(6,4) ;
      Affiche_empty(6,5) ;
      Affiche_cartes1(C6,6,6) ;
      //ui->colonne6->setText("\n \n \n \n \n ( "+QString::number(V)+','+QString::number(F) + ')') ;
      Carte C7 ;
      C7=T.getColonne(6).top() ;
      F=C7.getForme() ;
      V=C7.getValeur() ;
      Affiche_empty(7,1) ;
      Affiche_empty(7,2) ;
      Affiche_empty(7,3) ;
      Affiche_empty(7,4) ;
      Affiche_empty(7,5) ;
      Affiche_empty(7,6) ;
      Affiche_cartes1(C7,7,7) ;
      //ui->colonne7->setText("\n \n \n \n \n \n ( "+QString::number(V)+','+QString::number(F) + ')') ;
      ui->Commencer->setDisabled(true);
}

void MainWindow::on_pioche_clicked()
{
    //ui->pioche->setText("dsf") ;
    if(P.getPioche().empty())
    {
        ui->pioche->setText("Empty") ;
    }
    else if(P.getPioche().top().estVisible()== true)
    {
        Carte C1 ;
        C1=P.Retourner_Carte() ;
        P.Melanger(C1) ;
        C1=P.Retourner_Carte() ;
        P.Ajouter_Carte(C1) ;
        Carte::Formes F;
        Carte::Valeurs V;
        F=C1.getForme() ;
        V=C1.getValeur() ;
        Affiche_cartes(C1,0) ;
        //ui->pioche->setText('('+QString::number(V)+','+QString::number(F) + ')') ;

    }
    else
    {
        Carte C1 ;
        C1=P.Retourner_Carte() ;
        P.Ajouter_Carte(C1) ;
        Carte::Formes F;
        Carte::Valeurs V;
        F=C1.getForme() ;
        V=C1.getValeur() ;
        Affiche_cartes(C1,0) ;
        //ui->pioche->setText('('+QString::number(V)+','+QString::number(F) + ')') ;

    }
}


void MainWindow::on_Accepte_clicked()
{
    QString Ch1 , Ch2 , Ch3 ;
    Ch1 = ui->NumPile->toPlainText() ;
    Ch2 = ui->NumDest->toPlainText() ;
    Ch3 = ui->NbrCarte->toPlainText() ;
    if(Ch1 != "" && Ch2 != "" && Ch3 != "" )
    {
      qDebug()<<"hi" ;
      int nump=Ch1.toInt() ;
      int numd=Ch2.toInt() ;
      int nbrc=Ch3.toInt() ;
      bool t3=false ;
          bool t4=false ;
      stack<Carte> S2,S3,S4,S5 ;
      S4=T.getColonne(nump-1) ;
      while(S2.size()<nbrc && S4.empty()==false)
      {
        S2.push(S4.top()) ;
        S5.push(S4.top()) ;
        S4.pop() ;
      }

      while(S3.size()<nbrc && S2.empty()==false)
      {
        S3.push(S2.top()) ;
        S2.pop() ;
      }
      if (T.getColonne(numd-1).empty())
      {
        t3=T.AccepterRoi(S3, numd-1) ;
        if (t3==true )
        {
          for(int j=0 ; j<nbrc  ; j++)
          {
            T.popCarte(nump-1) ;
          }
        int B = T.getColonne(numd-1).size()-S5.size() ;
        while(S5.size() != 0)
        {
            switch (numd)
            {
                case 1:
                {
                    B++ ;
                    Carte::Formes F;
                    Carte::Valeurs V;
                    F=S5.top().getForme() ;
                    V=S5.top().getValeur() ;
                    Affiche_cartes1(S5.top(),1,B) ;
                    //ui->colonne1->setText(ui->colonne1->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                    S5.pop() ;
                    break ;
                }
            case 2:
            {
                B++ ;
                Carte::Formes F;
                Carte::Valeurs V;
                F=S5.top().getForme() ;
                V=S5.top().getValeur() ;
                Affiche_cartes1(S5.top(),2,B) ;
                //ui->colonne2->setText(ui->colonne1->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                S5.pop() ;
                break ;
            }
            case 3:
            {
                B++ ;
                Carte::Formes F;
                Carte::Valeurs V;
                F=S5.top().getForme() ;
                V=S5.top().getValeur() ;
                Affiche_cartes1(S5.top(),3,B) ;
                //ui->colonne3->setText(ui->colonne1->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                S5.pop() ;
                break ;
            }
            case 4:
            {
                B++ ;
                Carte::Formes F;
                Carte::Valeurs V;
                F=S5.top().getForme() ;
                V=S5.top().getValeur() ;
                Affiche_cartes1(S5.top(),4,B) ;
                //ui->colonne4->setText(ui->colonne1->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                S5.pop() ;
                break ;
            }
            case 5:
            {
                B++ ;
                Carte::Formes F;
                Carte::Valeurs V;
                F=S5.top().getForme() ;
                V=S5.top().getValeur() ;
                Affiche_cartes1(S5.top(),5,B) ;
                //ui->colonne5->setText(ui->colonne1->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                S5.pop() ;
                break ;
            }
            case 6:
            {
                B++ ;
                Carte::Formes F;
                Carte::Valeurs V;
                F=S5.top().getForme() ;
                V=S5.top().getValeur() ;
                Affiche_cartes1(S5.top(),6,B) ;
                //ui->colonne6->setText(ui->colonne1->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                S5.pop() ;
                break ;
            }
            case 7:
            {
                B++ ;
                Carte::Formes F;
                Carte::Valeurs V;
                F=S5.top().getForme() ;
                V=S5.top().getValeur() ;
                Affiche_cartes1(S5.top(),7,B) ;
                //ui->colonne7->setText(ui->colonne1->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                S5.pop() ;
                break ;
            }

            }

        }


          if (T.getColonne(nump-1).empty()==false)
          {
            T.setinverser(nump-1)  ;
            switch (nump)
            {
                case 1:
                    {                        
                        Carte C1 ;
                        C1=T.getColonne(0).top() ;
                        Carte::Formes F;
                        Carte::Valeurs V;
                        F=C1.getForme() ;
                        V=C1.getValeur() ;
                        int J ;
                        J=T.getColonne(0).size() ;
                        //ui->colonne1->setText("\n")   ;
                        for(int i=0 ; i<J-1 ; i++)
                        {
                            Affiche_empty(1,i+1) ;
                            //ui->colonne1->setText(ui->colonne1->text()+"\n")   ;
                        }
                        Affiche_cartes1(C1,1,J) ;
                        //ui->colonne1->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                        break ;
                    }
            case 2:
                {
                    Carte C1 ;
                    C1=T.getColonne(1).top() ;
                    Carte::Formes F;
                    Carte::Valeurs V;
                    F=C1.getForme() ;
                    V=C1.getValeur() ;
                    int J ;
                    J=T.getColonne(1).size() ;
                    //ui->colonne1->setText("\n")   ;
                    for(int i=0 ; i<J-1 ; i++)
                    {
                        Affiche_empty(2,i+1) ;
                        //ui->colonne2->setText(ui->colonne1->text()+"\n")   ;
                    }
                    Affiche_cartes1(C1,2,J) ;
                    //ui->colonne2->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                    break ;
                }
            case 3:
                {
                    Carte C1 ;
                    C1=T.getColonne(2).top() ;
                    Carte::Formes F;
                    Carte::Valeurs V;
                    F=C1.getForme() ;
                    V=C1.getValeur() ;
                    int J ;
                    J=T.getColonne(2).size() ;
                    //ui->colonne1->setText("\n")   ;
                    for(int i=0 ; i<J-1 ; i++)
                    {
                        Affiche_empty(3,i+1) ;
                        //ui->colonne3->setText(ui->colonne1->text()+"\n")   ;
                    }
                    Affiche_cartes1(C1,3,J) ;
                    //ui->colonne3->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                    break ;
                }
            case 4:
                {
                    Carte C1 ;
                    C1=T.getColonne(3).top() ;
                    Carte::Formes F;
                    Carte::Valeurs V;
                    F=C1.getForme() ;
                    V=C1.getValeur() ;
                    int J ;
                    J=T.getColonne(3).size() ;
                    //ui->colonne1->setText("\n")   ;
                    for(int i=0 ; i<J-1 ; i++)
                    {
                        Affiche_empty(4,i+1) ;
                        //ui->colonne4->setText(ui->colonne1->text()+"\n")   ;
                    }
                    Affiche_cartes1(C1,4,J) ;
                    //ui->colonne4->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                    break ;
                }
            case 5:
                {
                    Carte C1 ;
                    C1=T.getColonne(4).top() ;
                    Carte::Formes F;
                    Carte::Valeurs V;
                    F=C1.getForme() ;
                    V=C1.getValeur() ;
                    int J ;
                    J=T.getColonne(4).size() ;
                    //ui->colonne1->setText("\n")   ;
                    for(int i=0 ; i<J-1 ; i++)
                    {
                        Affiche_empty(5,i+1) ;
                        //ui->colonne5->setText(ui->colonne1->text()+"\n")   ;
                    }
                    Affiche_cartes1(C1,5,J) ;
                    //ui->colonne5->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                    break ;
                }
            case 6:
                {
                    Carte C1 ;
                    C1=T.getColonne(5).top() ;
                    Carte::Formes F;
                    Carte::Valeurs V;
                    F=C1.getForme() ;
                    V=C1.getValeur() ;
                    int J ;
                    J=T.getColonne(5).size() ;
                    //ui->colonne1->setText("\n")   ;
                    for(int i=0 ; i<J-1 ; i++)
                    {
                        Affiche_empty(6,i+1) ;
                        //ui->colonne6->setText(ui->colonne1->text()+"\n")   ;
                    }
                    Affiche_cartes1(C1,6,J) ;
                    //ui->colonne6->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                    break ;
                }
            case 7:
                {
                    Carte C1 ;
                    C1=T.getColonne(6).top() ;
                    Carte::Formes F;
                    Carte::Valeurs V;
                    F=C1.getForme() ;
                    V=C1.getValeur() ;
                    int J ;
                    J=T.getColonne(6).size() ;
                    //ui->colonne1->setText("\n")   ;
                    for(int i=0 ; i<J-1 ; i++)
                    {
                        Affiche_empty(7,i+1) ;
                        //ui->colonne7->setText(ui->colonne1->text()+"\n")   ;
                    }
                    Affiche_cartes1(C1,7,J) ;
                    //ui->colonne7->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                    break ;
                }

            }
          }
          else
          {
              switch (nump)
              {
                    case 1 :
                      {
                          ui->colonne1->setText("\n")   ;
                          break ;
                      }
                  case 2 :
                    {
                        ui->colonne2->setText("\n")   ;
                        break ;
                    }
                  case 3 :
                    {
                        ui->colonne3->setText("\n")   ;
                        break ;
                    }
                  case 4 :
                    {
                        ui->colonne4->setText("\n")   ;
                        break ;
                    }
                  case 5 :
                    {
                        ui->colonne5->setText("\n")   ;
                        break ;
                    }
                  case 6 :
                    {
                        ui->colonne6->setText("\n")   ;
                        break ;
                    }
                  case 7 :
                    {
                        ui->colonne7->setText("\n")   ;
                        break ;
                    }


              }

          }

        }
      }
      else
      {
        t4=T.Alternance(S3, numd-1) ;
        if (t4==true )
        {
          for(int j=0 ; j<nbrc && T.getColonne(nump-1).empty()== false ; j++)
          {
            T.popCarte(nump-1) ;
          }
          int B = T.getColonne(numd-1).size()-S5.size() ;
          while(S5.size() != 0)
          {
              switch (numd)
              {
                  case 1:
                  {
                      B++ ;
                      Carte::Formes F;
                      Carte::Valeurs V;
                      F=S5.top().getForme() ;
                      V=S5.top().getValeur() ;
                      Affiche_cartes1(S5.top(),1,B) ;
                      //ui->colonne1->setText(ui->colonne1->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                      S5.pop() ;
                      break ;
                  }
              case 2:
              {
                  B++ ;
                  Carte::Formes F;
                  Carte::Valeurs V;
                  F=S5.top().getForme() ;
                  V=S5.top().getValeur() ;
                  Affiche_cartes1(S5.top(),2,B) ;
                  //ui->colonne2->setText(ui->colonne1->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                  S5.pop() ;
                  break ;
              }
              case 3:
              {
                  B++ ;
                  Carte::Formes F;
                  Carte::Valeurs V;
                  F=S5.top().getForme() ;
                  V=S5.top().getValeur() ;
                  Affiche_cartes1(S5.top(),3,B) ;
                  //ui->colonne3->setText(ui->colonne1->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                  S5.pop() ;
                  break ;
              }
              case 4:
              {
                  B++ ;
                  Carte::Formes F;
                  Carte::Valeurs V;
                  F=S5.top().getForme() ;
                  V=S5.top().getValeur() ;
                  Affiche_cartes1(S5.top(),4,B) ;
                  //ui->colonne4->setText(ui->colonne1->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                  S5.pop() ;
                  break ;
              }
              case 5:
              {
                  B++ ;
                  Carte::Formes F;
                  Carte::Valeurs V;
                  F=S5.top().getForme() ;
                  V=S5.top().getValeur() ;
                  Affiche_cartes1(S5.top(),5,B) ;
                  //ui->colonne5->setText(ui->colonne1->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                  S5.pop() ;
                  break ;
              }
              case 6:
              {
                  B++ ;
                  Carte::Formes F;
                  Carte::Valeurs V;
                  F=S5.top().getForme() ;
                  V=S5.top().getValeur() ;
                  Affiche_cartes1(S5.top(),6,B) ;
                  //ui->colonne6->setText(ui->colonne1->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                  S5.pop() ;
                  break ;
              }
              case 7:
              {
                  B++ ;
                  Carte::Formes F;
                  Carte::Valeurs V;
                  F=S5.top().getForme() ;
                  V=S5.top().getValeur() ;
                  Affiche_cartes1(S5.top(),7,B) ;
                  //ui->colonne7->setText(ui->colonne1->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                  S5.pop() ;
                  break ;
              }

              }

          }

          if (T.getColonne(nump-1).empty()==false)
          {
            T.setinverser(nump-1)  ;
            switch (nump)
            {
                case 1:
                    {
                        Carte C1 ;
                        C1=T.getColonne(0).top() ;
                        Carte::Formes F;
                        Carte::Valeurs V;
                        F=C1.getForme() ;
                        V=C1.getValeur() ;
                        int J ;
                        J=T.getColonne(0).size() ;
                        //ui->colonne1->setText("\n")   ;
                        for(int i=0 ; i<J-1 ; i++)
                        {
                            Affiche_empty(1,i+1) ;
                            //ui->colonne1->setText(ui->colonne1->text()+"\n")   ;
                        }
                        Affiche_cartes1(C1,1,J) ;
                        //ui->colonne1->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                        break ;
                    }
            case 2:
                {
                    Carte C1 ;
                    C1=T.getColonne(1).top() ;
                    Carte::Formes F;
                    Carte::Valeurs V;
                    F=C1.getForme() ;
                    V=C1.getValeur() ;
                    int J ;
                    J=T.getColonne(1).size() ;
                    //ui->colonne1->setText("\n")   ;
                    for(int i=0 ; i<J-1 ; i++)
                    {
                        Affiche_empty(2,i+1) ;
                        //ui->colonne2->setText(ui->colonne1->text()+"\n")   ;
                    }
                    Affiche_cartes1(C1,2,J) ;
                    //ui->colonne2->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                    break ;
                }
            case 3:
                {
                    Carte C1 ;
                    C1=T.getColonne(2).top() ;
                    Carte::Formes F;
                    Carte::Valeurs V;
                    F=C1.getForme() ;
                    V=C1.getValeur() ;
                    int J ;
                    J=T.getColonne(2).size() ;
                    //ui->colonne1->setText("\n")   ;
                    for(int i=0 ; i<J-1 ; i++)
                    {
                        Affiche_empty(3,i+1) ;
                        //ui->colonne3->setText(ui->colonne1->text()+"\n")   ;
                    }
                    Affiche_cartes1(C1,3,J) ;
                    //ui->colonne3->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                    break ;
                }
            case 4:
                {
                    Carte C1 ;
                    C1=T.getColonne(3).top() ;
                    Carte::Formes F;
                    Carte::Valeurs V;
                    F=C1.getForme() ;
                    V=C1.getValeur() ;
                    int J ;
                    J=T.getColonne(3).size() ;
                    //ui->colonne1->setText("\n")   ;
                    for(int i=0 ; i<J-1 ; i++)
                    {
                        Affiche_empty(4,i+1) ;
                        //ui->colonne4->setText(ui->colonne1->text()+"\n")   ;
                    }
                    Affiche_cartes1(C1,4,J) ;
                    //ui->colonne4->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                    break ;
                }
            case 5:
                {
                    Carte C1 ;
                    C1=T.getColonne(4).top() ;
                    Carte::Formes F;
                    Carte::Valeurs V;
                    F=C1.getForme() ;
                    V=C1.getValeur() ;
                    int J ;
                    J=T.getColonne(4).size() ;
                    //ui->colonne1->setText("\n")   ;
                    for(int i=0 ; i<J-1 ; i++)
                    {
                        Affiche_empty(5,i+1) ;
                        //ui->colonne5->setText(ui->colonne1->text()+"\n")   ;
                    }
                    Affiche_cartes1(C1,5,J) ;
                    //ui->colonne5->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                    break ;
                }
            case 6:
                {
                    Carte C1 ;
                    C1=T.getColonne(5).top() ;
                    Carte::Formes F;
                    Carte::Valeurs V;
                    F=C1.getForme() ;
                    V=C1.getValeur() ;
                    int J ;
                    J=T.getColonne(5).size() ;
                    //ui->colonne1->setText("\n")   ;
                    for(int i=0 ; i<J-1 ; i++)
                    {
                        Affiche_empty(6,i+1) ;
                        //ui->colonne6->setText(ui->colonne1->text()+"\n")   ;
                    }
                    Affiche_cartes1(C1,6,J) ;
                    //ui->colonne6->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                    break ;
                }
            case 7:
                {
                    Carte C1 ;
                    C1=T.getColonne(6).top() ;
                    Carte::Formes F;
                    Carte::Valeurs V;
                    F=C1.getForme() ;
                    V=C1.getValeur() ;
                    int J ;
                    J=T.getColonne(6).size() ;
                    //ui->colonne1->setText("\n")   ;
                    for(int i=0 ; i<J-1 ; i++)
                    {
                        Affiche_empty(7,i+1) ;
                        //ui->colonne7->setText(ui->colonne1->text()+"\n")   ;
                    }
                    Affiche_cartes1(C1,7,J) ;
                    //ui->colonne7->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                    break ;
                }

            }
        }
          else
          {
              switch (nump)
              {
                    case 1 :
                      {
                          ui->colonne1->setText("\n")   ;
                          break ;
                      }
                  case 2 :
                    {
                        ui->colonne2->setText("\n")   ;
                        break ;
                    }
                  case 3 :
                    {
                        ui->colonne3->setText("\n")   ;
                        break ;
                    }
                  case 4 :
                    {
                        ui->colonne4->setText("\n")   ;
                        break ;
                    }
                  case 5 :
                    {
                        ui->colonne5->setText("\n")   ;
                        break ;
                    }
                  case 6 :
                    {
                        ui->colonne6->setText("\n")   ;
                        break ;
                    }
                  case 7 :
                    {
                        ui->colonne7->setText("\n")   ;
                        break ;
                    }


              }

          }
      }


    }

}

        else if (Ch1 == "" && Ch2 != "" && Ch3=="")
        {
            qDebug()<<"hi1" ;
            int numd=Ch2.toInt() ;
            if(numd<=7)
            {
                bool t1=false ;
                                      bool t2=false ;
                                      if(T.getColonne(numd-1).empty())
                                      {
                                        t1=T.AccepterRoi(P.getPioche().top(), numd-1) ;
                                        if(t1 == true)
                                        {
                                            switch (numd)
                                                {
                                                    case 1:
                                                    {
                                                        Carte::Formes F;
                                                        Carte::Valeurs V;
                                                        F=P.getPioche().top().getForme() ;
                                                        V=P.getPioche().top().getValeur() ;
                                                        int B = T.getColonne(numd-1).size() ;
                                                        Affiche_cartes1(P.getPioche().top(),1,B) ;
                                                        //ui->colonne1->setText(ui->colonne1->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                                                        break ;
                                                    }
                                                case 2:
                                                {
                                                    Carte::Formes F;
                                                    Carte::Valeurs V;
                                                    F=P.getPioche().top().getForme() ;
                                                    V=P.getPioche().top().getValeur() ;
                                                    int B = T.getColonne(numd-1).size() ;
                                                    Affiche_cartes1(P.getPioche().top(),2,B) ;
                                                    //ui->colonne2->setText(ui->colonne2->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                                                    break ;
                                                }
                                                case 3:
                                                {
                                                    Carte::Formes F;
                                                    Carte::Valeurs V;
                                                    F=P.getPioche().top().getForme() ;
                                                    V=P.getPioche().top().getValeur() ;
                                                    int B = T.getColonne(numd-1).size() ;
                                                    Affiche_cartes1(P.getPioche().top(),3,B) ;
                                                    //ui->colonne3->setText(ui->colonne3->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                                                    break ;
                                                }
                                                case 4:
                                                {
                                                    Carte::Formes F;
                                                    Carte::Valeurs V;
                                                    F=P.getPioche().top().getForme() ;
                                                    V=P.getPioche().top().getValeur() ;
                                                    int B = T.getColonne(numd-1).size() ;
                                                    Affiche_cartes1(P.getPioche().top(),4,B) ;
                                                    //ui->colonne4->setText(ui->colonne4->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                                                    break ;
                                                }
                                                case 5:
                                                {
                                                    Carte::Formes F;
                                                    Carte::Valeurs V;
                                                    F=P.getPioche().top().getForme() ;
                                                    V=P.getPioche().top().getValeur() ;
                                                    int B = T.getColonne(numd-1).size() ;
                                                    Affiche_cartes1(P.getPioche().top(),5,B) ;
                                                    //ui->colonne5->setText(ui->colonne5->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                                                    break ;
                                                }
                                                case 6:
                                                {
                                                    Carte::Formes F;
                                                    Carte::Valeurs V;
                                                    F=P.getPioche().top().getForme() ;
                                                    V=P.getPioche().top().getValeur() ;
                                                    int B = T.getColonne(numd-1).size() ;
                                                    Affiche_cartes1(P.getPioche().top(),6,B) ;
                                                    //ui->colonne6->setText(ui->colonne6->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                                                    break ;
                                                }
                                                case 7:
                                                {
                                                    Carte::Formes F;
                                                    Carte::Valeurs V;
                                                    F=P.getPioche().top().getForme() ;
                                                    V=P.getPioche().top().getValeur() ;
                                                    int B = T.getColonne(numd-1).size() ;
                                                    Affiche_cartes1(P.getPioche().top(),7,B) ;
                                                    //ui->colonne7->setText(ui->colonne7->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                                                    break ;
                                                }

                                                }

                                            P.sup_Carte() ;
                                            ui->pioch->setPixmap(QPixmap(":/images/empty.gif")) ;

                                        }
                                      }
                                      else if (t1 == false)
                                      {
                                        t2=T.Alternance(P.getPioche().top(), numd-1) ;

                                        if (t2 == true)
                                        {
                                            switch (numd)
                                                {
                                                    case 1:
                                                    {
                                                        Carte::Formes F;
                                                        Carte::Valeurs V;
                                                        F=P.getPioche().top().getForme() ;
                                                        V=P.getPioche().top().getValeur() ;
                                                        int B = T.getColonne(numd-1).size() ;
                                                        Affiche_cartes1(P.getPioche().top(),1,B) ;
                                                        //ui->colonne1->setText(ui->colonne1->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                                                        break ;
                                                    }
                                                case 2:
                                                {
                                                    Carte::Formes F;
                                                    Carte::Valeurs V;
                                                    F=P.getPioche().top().getForme() ;
                                                    V=P.getPioche().top().getValeur() ;
                                                    int B = T.getColonne(numd-1).size() ;
                                                    Affiche_cartes1(P.getPioche().top(),2,B) ;
                                                    //ui->colonne2->setText(ui->colonne2->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                                                    break ;
                                                }
                                                case 3:
                                                {
                                                    Carte::Formes F;
                                                    Carte::Valeurs V;
                                                    F=P.getPioche().top().getForme() ;
                                                    V=P.getPioche().top().getValeur() ;
                                                    int B = T.getColonne(numd-1).size() ;
                                                    Affiche_cartes1(P.getPioche().top(),3,B) ;
                                                    //ui->colonne3->setText(ui->colonne3->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                                                    break ;
                                                }
                                                case 4:
                                                {
                                                    Carte::Formes F;
                                                    Carte::Valeurs V;
                                                    F=P.getPioche().top().getForme() ;
                                                    V=P.getPioche().top().getValeur() ;
                                                    int B = T.getColonne(numd-1).size() ;
                                                    Affiche_cartes1(P.getPioche().top(),4,B) ;
                                                    //ui->colonne4->setText(ui->colonne4->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                                                    break ;
                                                }
                                                case 5:
                                                {
                                                    Carte::Formes F;
                                                    Carte::Valeurs V;
                                                    F=P.getPioche().top().getForme() ;
                                                    V=P.getPioche().top().getValeur() ;
                                                    int B = T.getColonne(numd-1).size() ;
                                                    Affiche_cartes1(P.getPioche().top(),5,B) ;
                                                    //ui->colonne5->setText(ui->colonne5->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                                                    break ;
                                                }
                                                case 6:
                                                {
                                                    Carte::Formes F;
                                                    Carte::Valeurs V;
                                                    F=P.getPioche().top().getForme() ;
                                                    V=P.getPioche().top().getValeur() ;
                                                    int B = T.getColonne(numd-1).size() ;
                                                    Affiche_cartes1(P.getPioche().top(),6,B) ;
                                                    //ui->colonne6->setText(ui->colonne6->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                                                    break ;
                                                }
                                                case 7:
                                                {
                                                    Carte::Formes F;
                                                    Carte::Valeurs V;
                                                    F=P.getPioche().top().getForme() ;
                                                    V=P.getPioche().top().getValeur() ;
                                                    int B = T.getColonne(numd-1).size() ;
                                                    Affiche_cartes1(P.getPioche().top(),7,B) ;
                                                    //ui->colonne7->setText(ui->colonne7->text()+"\n ("+QString::number(V)+','+QString::number(F) + ')') ;
                                                    break ;
                                                }

                                                }
                                            P.sup_Carte();
                                            ui->pioch->setPixmap(QPixmap(":/images/empty.gif")) ;

                                        }
                                      }
                                      else if (t1== false && t2 == false)
                                      {}
            }
            if (numd==11 || numd==12 || numd==13 || numd==14)
            {
                          bool t1=false ;
                          bool t2=false ;
                          if(PC.getPile(numd-11).empty())
                          {
                            t1=PC.AccepterAs(P.getPioche().top(), numd-11) ;
                            if(t1 == true)
                            {
                                switch (numd)
                                    {
                                        case 11:
                                        {
                                            Carte::Formes F;
                                            Carte::Valeurs V;
                                            F=P.getPioche().top().getForme() ;
                                            V=P.getPioche().top().getValeur() ;
                                            Affiche_cartes(P.getPioche().top(),numd) ;
                                            //ui->pile11->setText("("+QString::number(V)+','+QString::number(F) + ')') ;
                                            break ;
                                        }
                                    case 12:
                                    {
                                        Carte::Formes F;
                                        Carte::Valeurs V;
                                        F=P.getPioche().top().getForme() ;
                                        V=P.getPioche().top().getValeur() ;
                                        Affiche_cartes(P.getPioche().top(),numd) ;
                                        //ui->pile12->setText("("+QString::number(V)+','+QString::number(F) + ')') ;
                                        break ;
                                    }
                                    case 13:
                                    {
                                        Carte::Formes F;
                                        Carte::Valeurs V;
                                        F=P.getPioche().top().getForme() ;
                                        V=P.getPioche().top().getValeur() ;
                                        Affiche_cartes(P.getPioche().top(),numd) ;
                                        //ui->pile13->setText("("+QString::number(V)+','+QString::number(F) + ')') ;
                                        break ;
                                    }
                                    case 14:
                                    {
                                        Carte::Formes F;
                                        Carte::Valeurs V;
                                        F=P.getPioche().top().getForme() ;
                                        V=P.getPioche().top().getValeur() ;
                                        Affiche_cartes(P.getPioche().top(),numd) ;
                                        //ui->pile14->setText("("+QString::number(V)+','+QString::number(F) + ')') ;
                                        break ;
                                    }
                                }
                               P.sup_Carte();
                               ui->pioch->setPixmap(QPixmap(":/images/empty.gif"));
                            }
                          }
                          else if (t1 == false)
                          {
                            t2=PC.Unicite(P.getPioche().top(), numd-11) ;
                            if (t2 == true)
                            {
                                switch (numd)
                                    {
                                        case 11:
                                        {
                                            Carte::Formes F;
                                            Carte::Valeurs V;
                                            F=P.getPioche().top().getForme() ;
                                            V=P.getPioche().top().getValeur() ;
                                            Affiche_cartes(P.getPioche().top(),numd) ;
                                            //ui->pile11->setText("("+QString::number(V)+','+QString::number(F) + ')') ;
                                            break ;
                                        }
                                    case 12:
                                    {
                                        Carte::Formes F;
                                        Carte::Valeurs V;
                                        F=P.getPioche().top().getForme() ;
                                        V=P.getPioche().top().getValeur() ;
                                        Affiche_cartes(P.getPioche().top(),numd) ;
                                        //ui->pile12->setText("("+QString::number(V)+','+QString::number(F) + ')') ;
                                        break ;
                                    }
                                    case 13:
                                    {
                                        Carte::Formes F;
                                        Carte::Valeurs V;
                                        F=P.getPioche().top().getForme() ;
                                        V=P.getPioche().top().getValeur() ;
                                        Affiche_cartes(P.getPioche().top(),numd) ;
                                        //ui->pile13->setText("("+QString::number(V)+','+QString::number(F) + ')') ;
                                        break ;
                                    }
                                    case 14:
                                    {
                                        Carte::Formes F;
                                        Carte::Valeurs V;
                                        F=P.getPioche().top().getForme() ;
                                        V=P.getPioche().top().getValeur() ;
                                        Affiche_cartes(P.getPioche().top(),numd) ;
                                        //ui->pile14->setText("("+QString::number(V)+','+QString::number(F) + ')') ;
                                        break ;
                                    }
                                }
                               P.sup_Carte();
                               ui->pioch->setPixmap(QPixmap(":/images/empty.gif"));
                            }
                          }
                          else if (t1== false && t2 == false){}

            }
        }
        else if(Ch1 != "" && Ch2 != "" && Ch3 == "")
        {
            qDebug()<<"hi3" ;
            int nump=Ch1.toInt() ;
            int numd=Ch2.toInt() ;
            if (nump<=7 && (numd==11 || numd==12 || numd==13 || numd==14 ))
            {
                //cout<<"choisir une pile couleur comme destination "<<endl;
                               Carte CP ;
                               bool t1=false ;
                               CP = T.getColonne(nump-1).top() ;
                               if ( PC.getPile(numd-11).empty())
                              {

                                     t1=PC.AccepterAs(CP,numd-11) ;
                                     if (t1)
                                      {
                                         switch (numd)
                                             {
                                                 case 11:
                                                 {
                                                     Carte::Formes F;
                                                     Carte::Valeurs V;
                                                     F=CP.getForme() ;
                                                     V=CP.getValeur() ;
                                                     Affiche_cartes(CP,11) ;
                                                     //ui->pile11->setText("("+QString::number(V)+','+QString::number(F) + ')') ;
                                                     break ;
                                                 }
                                             case 12:
                                             {
                                                 Carte::Formes F;
                                                 Carte::Valeurs V;
                                                 F=CP.getForme() ;
                                                 V=CP.getValeur() ;
                                                 Affiche_cartes(CP,12) ;
                                                 //ui->pile12->setText("("+QString::number(V)+','+QString::number(F) + ')') ;
                                                 break ;
                                             }
                                             case 13:
                                             {
                                                 Carte::Formes F;
                                                 Carte::Valeurs V;
                                                 F=CP.getForme() ;
                                                 V=CP.getValeur() ;
                                                 Affiche_cartes(CP,13) ;
                                                 //ui->pile13->setText("("+QString::number(V)+','+QString::number(F) + ')') ;
                                                 break ;
                                             }
                                             case 14:
                                             {
                                                 Carte::Formes F;
                                                 Carte::Valeurs V;
                                                 F=CP.getForme() ;
                                                 V=CP.getValeur() ;
                                                 Affiche_cartes(CP,14) ;
                                                 //ui->pile14->setText("("+QString::number(V)+','+QString::number(F) + ')') ;
                                                 break ;
                                             }
                                         }

                                             T.popCarte(nump-1) ;
                                             if(T.getColonne(nump-1).size() !=0 && T.getColonne(nump-1).top().estVisible()==false)
                                             {
                                                 T.setinverser(nump-1) ;
                                             }
                                             stack<Carte> S8,S9 ;
                                             S9 =T.getColonne(nump-1) ;
                                             while(S9.size()!= 0)
                                             {
                                                 S8.push(S9.top()) ;
                                                 S9.pop() ;
                                             }

                                             switch (nump)
                                             {
                                             case 1:
                                                 {
                                                     int Z=S8.size() ;
                                                     for(int i=0 ;i<Z ; i++)
                                                     {
                                                         if(S8.top().estVisible()==false)
                                                         {
                                                             Affiche_empty(1,i+1) ;
                                                         }
                                                         else
                                                         {
                                                             Affiche_cartes1(S8.top(),1,i+1) ;

                                                         }
                                                         S8.pop() ;
                                                     }
                                                     if(T.getColonne(0).size()==0)
                                                     {
                                                         ui->colonne1->setText("empty") ;
                                                     }
                                                     break ;
                                                 }
                                         case 2:
                                             {
                                                 int Z=S8.size() ;
                                                 for(int i=0 ;i<Z ; i++)
                                                 {
                                                     if(S8.top().estVisible()==false)
                                                     {
                                                         Affiche_empty(2,i+1) ;
                                                     }
                                                     else
                                                     {
                                                         Affiche_cartes1(S8.top(),2,i+1) ;

                                                     }
                                                     S8.pop() ;
                                                 }
                                                 if(T.getColonne(1).size()==0)
                                                 {
                                                     ui->colonne2->setText("empty") ;
                                                 }
                                                 break ;
                                             }
                                         case 3:
                                             {
                                                 int Z=S8.size() ;
                                                 for(int i=0 ;i<Z ; i++)
                                                 {
                                                     if(S8.top().estVisible()==false)
                                                     {
                                                         Affiche_empty(3,i+1) ;
                                                     }
                                                     else
                                                     {
                                                         Affiche_cartes1(S8.top(),3,i+1) ;

                                                     }
                                                     S8.pop() ;
                                                 }
                                                 if(T.getColonne(2).size()==0)
                                                 {
                                                     ui->colonne3->setText("empty") ;
                                                 }
                                                 break ;
                                             }
                                         case 4:
                                             {
                                                 int Z=S8.size() ;
                                                 for(int i=0 ;i<Z ; i++)
                                                 {
                                                     if(S8.top().estVisible()==false)
                                                     {
                                                         Affiche_empty(4,i+1) ;
                                                     }
                                                     else
                                                     {
                                                         Affiche_cartes1(S8.top(),4,i+1) ;

                                                     }
                                                     S8.pop() ;
                                                 }
                                                 if(T.getColonne(3).size()==0)
                                                 {
                                                     ui->colonne4->setText("empty") ;
                                                 }
                                                 break ;
                                             }
                                         case 5:
                                             {
                                                 int Z=S8.size() ;
                                                 for(int i=0 ;i<Z ; i++)
                                                 {
                                                     if(S8.top().estVisible()==false)
                                                     {
                                                         Affiche_empty(5,i+1) ;
                                                     }
                                                     else
                                                     {
                                                         Affiche_cartes1(S8.top(),5,i+1) ;

                                                     }
                                                     S8.pop() ;
                                                 }
                                                 if(T.getColonne(4).size()==0)
                                                 {
                                                     ui->colonne5->setText("empty") ;
                                                 }
                                                 break ;
                                             }
                                         case 6:
                                             {
                                                 int Z=S8.size() ;
                                                 for(int i=0 ;i<Z ; i++)
                                                 {
                                                     if(S8.top().estVisible()==false)
                                                     {
                                                         Affiche_empty(6,i+1) ;
                                                     }
                                                     else
                                                     {
                                                         Affiche_cartes1(S8.top(),6,i+1) ;

                                                     }
                                                     S8.pop() ;
                                                 }
                                                 if(T.getColonne(5).size()==0)
                                                 {
                                                     ui->colonne6->setText("empty") ;
                                                 }
                                                 break ;
                                             }
                                         case 7:
                                             {
                                                 int Z=S8.size() ;
                                                 for(int i=0 ;i<Z ; i++)
                                                 {
                                                     if(S8.top().estVisible()==false)
                                                     {
                                                         Affiche_empty(7,i+1) ;
                                                     }
                                                     else
                                                     {
                                                         Affiche_cartes1(S8.top(),7,i+1) ;

                                                     }
                                                     S8.pop() ;
                                                 }
                                                 if(T.getColonne(6).size()==0)
                                                 {
                                                     ui->colonne7->setText("empty") ;
                                                 }
                                                 break ;
                                             }
                                           }


                                      }
                              }
                               else
                               {
                                        t1=PC.Unicite(CP, numd-11);
                                        if (t1)
                                        {
                                            switch (numd)
                                                {
                                                    case 11:
                                                    {
                                                        Carte::Formes F;
                                                        Carte::Valeurs V;
                                                        F=CP.getForme() ;
                                                        V=CP.getValeur() ;
                                                        Affiche_cartes(CP,11) ;
                                                        //ui->pile11->setText("("+QString::number(V)+','+QString::number(F) + ')') ;
                                                        break ;
                                                    }
                                                case 12:
                                                {
                                                    Carte::Formes F;
                                                    Carte::Valeurs V;
                                                    F=CP.getForme() ;
                                                    V=CP.getValeur() ;
                                                    Affiche_cartes(CP,12) ;
                                                    //ui->pile12->setText("("+QString::number(V)+','+QString::number(F) + ')') ;
                                                    break ;
                                                }
                                                case 13:
                                                {
                                                    Carte::Formes F;
                                                    Carte::Valeurs V;
                                                    F=CP.getForme() ;
                                                    V=CP.getValeur() ;
                                                    Affiche_cartes(CP,13) ;
                                                    //ui->pile13->setText("("+QString::number(V)+','+QString::number(F) + ')') ;
                                                    break ;
                                                }
                                                case 14:
                                                {
                                                    Carte::Formes F;
                                                    Carte::Valeurs V;
                                                    F=CP.getForme() ;
                                                    V=CP.getValeur() ;
                                                    Affiche_cartes(CP,14) ;
                                                    //ui->pile14->setText("("+QString::number(V)+','+QString::number(F) + ')') ;
                                                    break ;
                                                }
                                            }

                                            T.popCarte(nump-1) ;
                                            if(T.getColonne(nump-1).size() !=0 && T.getColonne(nump-1).top().estVisible()==false)
                                            {
                                                T.setinverser(nump-1) ;
                                            }
                                            stack<Carte> S8,S9 ;
                                            S9 =T.getColonne(nump-1) ;
                                            while(S9.size()!= 0)
                                            {
                                                S8.push(S9.top()) ;
                                                S9.pop() ;
                                            }

                                            switch (nump)
                                            {
                                            case 1:
                                                {
                                                    int Z=S8.size() ;
                                                    for(int i=0 ;i<Z ; i++)
                                                    {
                                                        if(S8.top().estVisible()==false)
                                                        {
                                                            Affiche_empty(1,i+1) ;
                                                        }
                                                        else
                                                        {
                                                            Affiche_cartes1(S8.top(),1,i+1) ;

                                                        }
                                                        S8.pop() ;
                                                    }
                                                    if(T.getColonne(0).size()==0)
                                                    {
                                                        ui->colonne1->setText("empty") ;
                                                    }
                                                    break ;
                                                }
                                        case 2:
                                            {
                                                int Z=S8.size() ;
                                                for(int i=0 ;i<Z ; i++)
                                                {
                                                    if(S8.top().estVisible()==false)
                                                    {
                                                        Affiche_empty(2,i+1) ;
                                                    }
                                                    else
                                                    {
                                                        Affiche_cartes1(S8.top(),2,i+1) ;

                                                    }
                                                    S8.pop() ;
                                                }
                                                if(T.getColonne(1).size()==0)
                                                {
                                                    ui->colonne2->setText("empty") ;
                                                }
                                                break ;
                                            }
                                        case 3:
                                            {
                                                int Z=S8.size() ;
                                                for(int i=0 ;i<Z ; i++)
                                                {
                                                    if(S8.top().estVisible()==false)
                                                    {
                                                        Affiche_empty(3,i+1) ;
                                                    }
                                                    else
                                                    {
                                                        Affiche_cartes1(S8.top(),3,i+1) ;

                                                    }
                                                    S8.pop() ;
                                                }
                                                if(T.getColonne(2).size()==0)
                                                {
                                                    ui->colonne3->setText("empty") ;
                                                }
                                                break ;
                                            }
                                        case 4:
                                            {
                                                int Z=S8.size() ;
                                                for(int i=0 ;i<Z ; i++)
                                                {
                                                    if(S8.top().estVisible()==false)
                                                    {
                                                        Affiche_empty(4,i+1) ;
                                                    }
                                                    else
                                                    {
                                                        Affiche_cartes1(S8.top(),4,i+1) ;

                                                    }
                                                    S8.pop() ;
                                                }
                                                if(T.getColonne(3).size()==0)
                                                {
                                                    ui->colonne4->setText("empty") ;
                                                }
                                                break ;
                                            }
                                        case 5:
                                            {
                                                int Z=S8.size() ;
                                                for(int i=0 ;i<Z ; i++)
                                                {
                                                    if(S8.top().estVisible()==false)
                                                    {
                                                        Affiche_empty(5,i+1) ;
                                                    }
                                                    else
                                                    {
                                                        Affiche_cartes1(S8.top(),5,i+1) ;

                                                    }
                                                    S8.pop() ;
                                                }
                                                if(T.getColonne(4).size()==0)
                                                {
                                                    ui->colonne5->setText("empty") ;
                                                }
                                                break ;
                                            }
                                        case 6:
                                            {
                                                int Z=S8.size() ;
                                                for(int i=0 ;i<Z ; i++)
                                                {
                                                    if(S8.top().estVisible()==false)
                                                    {
                                                        Affiche_empty(6,i+1) ;
                                                    }
                                                    else
                                                    {
                                                        Affiche_cartes1(S8.top(),6,i+1) ;

                                                    }
                                                    S8.pop() ;
                                                }
                                                if(T.getColonne(5).size()==0)
                                                {
                                                    ui->colonne6->setText("empty") ;
                                                }
                                                break ;
                                            }
                                        case 7:
                                            {
                                                int Z=S8.size() ;
                                                for(int i=0 ;i<Z ; i++)
                                                {
                                                    if(S8.top().estVisible()==false)
                                                    {
                                                        Affiche_empty(7,i+1) ;
                                                    }
                                                    else
                                                    {
                                                        Affiche_cartes1(S8.top(),7,i+1) ;

                                                    }
                                                    S8.pop() ;
                                                }
                                                if(T.getColonne(6).size()==0)
                                                {
                                                    ui->colonne7->setText("empty") ;
                                                }
                                                break ;
                                            }
                                          }

                                       }

                               }
            }
            if (numd<=7 && (nump==11 || nump==12 || nump==13 || nump==14 ))
            {
                  Carte CP1 ;
                  bool t2=false ;
                  CP1= PC.getPile( nump-11).top();
                  if (T.getColonne(numd-1).empty())
                  {
                    t2=T.AccepterRoi(CP1, numd-1) ;
                    if(t2)
                    {
                        switch (nump)
                        {
                        case 1:
                            {
                                Carte C1 ;
                                C1=T.getColonne(0).top() ;
                                Carte::Formes F;
                                Carte::Valeurs V;
                                F=C1.getForme() ;
                                V=C1.getValeur() ;
                                int J ;
                                J=T.getColonne(0).size() ;
                                //ui->colonne1->setText("\n")   ;
                                for(int i=0 ; i<J-1 ; i++)
                                {
                                    Affiche_empty(1,i+1) ;
                                    //ui->colonne1->setText(ui->colonne1->text()+"\n")   ;
                                }
                                Affiche_cartes1(C1,1,J) ;
                                //ui->colonne1->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                                break ;
                            }
                    case 2:
                        {
                            Carte C1 ;
                            C1=T.getColonne(1).top() ;
                            Carte::Formes F;
                            Carte::Valeurs V;
                            F=C1.getForme() ;
                            V=C1.getValeur() ;
                            int J ;
                            J=T.getColonne(1).size() ;
                            //ui->colonne1->setText("\n")   ;
                            for(int i=0 ; i<J-1 ; i++)
                            {
                                Affiche_empty(2,i+1) ;
                                //ui->colonne2->setText(ui->colonne1->text()+"\n")   ;
                            }
                            Affiche_cartes1(C1,2,J) ;
                            //ui->colonne2->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                            break ;
                        }
                    case 3:
                        {
                            Carte C1 ;
                            C1=T.getColonne(2).top() ;
                            Carte::Formes F;
                            Carte::Valeurs V;
                            F=C1.getForme() ;
                            V=C1.getValeur() ;
                            int J ;
                            J=T.getColonne(2).size() ;
                            //ui->colonne1->setText("\n")   ;
                            for(int i=0 ; i<J-1 ; i++)
                            {
                                Affiche_empty(3,i+1) ;
                                //ui->colonne3->setText(ui->colonne1->text()+"\n")   ;
                            }
                            Affiche_cartes1(C1,3,J) ;
                            //ui->colonne3->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                            break ;
                        }
                    case 4:
                        {
                            Carte C1 ;
                            C1=T.getColonne(3).top() ;
                            Carte::Formes F;
                            Carte::Valeurs V;
                            F=C1.getForme() ;
                            V=C1.getValeur() ;
                            int J ;
                            J=T.getColonne(3).size() ;
                            //ui->colonne1->setText("\n")   ;
                            for(int i=0 ; i<J-1 ; i++)
                            {
                                Affiche_empty(4,i+1) ;
                                //ui->colonne4->setText(ui->colonne1->text()+"\n")   ;
                            }
                            Affiche_cartes1(C1,4,J) ;
                            //ui->colonne4->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                            break ;
                        }
                    case 5:
                        {
                            Carte C1 ;
                            C1=T.getColonne(4).top() ;
                            Carte::Formes F;
                            Carte::Valeurs V;
                            F=C1.getForme() ;
                            V=C1.getValeur() ;
                            int J ;
                            J=T.getColonne(4).size() ;
                            //ui->colonne1->setText("\n")   ;
                            for(int i=0 ; i<J-1 ; i++)
                            {
                                Affiche_empty(5,i+1) ;
                                //ui->colonne5->setText(ui->colonne1->text()+"\n")   ;
                            }
                            Affiche_cartes1(C1,5,J) ;
                            //ui->colonne5->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                            break ;
                        }
                    case 6:
                        {
                            Carte C1 ;
                            C1=T.getColonne(5).top() ;
                            Carte::Formes F;
                            Carte::Valeurs V;
                            F=C1.getForme() ;
                            V=C1.getValeur() ;
                            int J ;
                            J=T.getColonne(5).size() ;
                            //ui->colonne1->setText("\n")   ;
                            for(int i=0 ; i<J-1 ; i++)
                            {
                                Affiche_empty(6,i+1) ;
                                //ui->colonne6->setText(ui->colonne1->text()+"\n")   ;
                            }
                            Affiche_cartes1(C1,6,J) ;
                            //ui->colonne6->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                            break ;
                        }
                    case 7:
                        {
                            Carte C1 ;
                            C1=T.getColonne(6).top() ;
                            Carte::Formes F;
                            Carte::Valeurs V;
                            F=C1.getForme() ;
                            V=C1.getValeur() ;
                            int J ;
                            J=T.getColonne(6).size() ;
                            //ui->colonne1->setText("\n")   ;
                            for(int i=0 ; i<J-1 ; i++)
                            {
                                Affiche_empty(7,i+1) ;
                                //ui->colonne7->setText(ui->colonne1->text()+"\n")   ;
                            }
                            Affiche_cartes1(C1,7,J) ;
                            //ui->colonne7->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                            break ;
                        }
                      }

                        PC.Supp_Carte(nump-11);

                        switch (numd)
                            {
                                case 11:
                                {
                                    Carte::Formes F;
                                    Carte::Valeurs V;
                                    F=PC.getPile(0).top().getForme() ;
                                    V=PC.getPile(0).top().getValeur() ;
                                    Affiche_cartes(PC.getPile(0).top(),11) ;
                                    //ui->pile11->setText("("+QString::number(V)+','+QString::number(F) + ')') ;
                                    break ;
                                }
                            case 12:
                            {
                                Carte::Formes F;
                                Carte::Valeurs V;
                                F=PC.getPile(1).top().getForme() ;
                                V=PC.getPile(1).top().getValeur() ;
                                Affiche_cartes(PC.getPile(1).top(),12) ;
                                //ui->pile12->setText("("+QString::number(V)+','+QString::number(F) + ')') ;
                                break ;
                            }
                            case 13:
                            {
                                Carte::Formes F;
                                Carte::Valeurs V;
                                F=PC.getPile(2).top().getForme() ;
                                V=PC.getPile(2).top().getValeur() ;
                                Affiche_cartes(PC.getPile(2).top(),13) ;
                                //ui->pile13->setText("("+QString::number(V)+','+QString::number(F) + ')') ;
                                break ;
                            }
                            case 14:
                            {
                                Carte::Formes F;
                                Carte::Valeurs V;
                                F=PC.getPile(3).top().getForme() ;
                                V=PC.getPile(3).top().getValeur() ;
                                Affiche_cartes(PC.getPile(3).top(),13) ;
                                //ui->pile14->setText("("+QString::number(V)+','+QString::number(F) + ')') ;
                                break ;
                            }
                        }


                    }
                  }
                  else
                  {
                    t2=T.Alternance(CP1, numd-1) ;
                    if (t2)
                    {
                        switch (nump)
                        {
                        case 1:
                            {
                                Carte C1 ;
                                C1=T.getColonne(0).top() ;
                                Carte::Formes F;
                                Carte::Valeurs V;
                                F=C1.getForme() ;
                                V=C1.getValeur() ;
                                int J ;
                                J=T.getColonne(0).size() ;
                                //ui->colonne1->setText("\n")   ;
                                for(int i=0 ; i<J-1 ; i++)
                                {
                                    Affiche_empty(1,i+1) ;
                                    //ui->colonne1->setText(ui->colonne1->text()+"\n")   ;
                                }
                                Affiche_cartes1(C1,1,J) ;
                                //ui->colonne1->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                                break ;
                            }
                    case 2:
                        {
                            Carte C1 ;
                            C1=T.getColonne(1).top() ;
                            Carte::Formes F;
                            Carte::Valeurs V;
                            F=C1.getForme() ;
                            V=C1.getValeur() ;
                            int J ;
                            J=T.getColonne(1).size() ;
                            //ui->colonne1->setText("\n")   ;
                            for(int i=0 ; i<J-1 ; i++)
                            {
                                Affiche_empty(2,i+1) ;
                                //ui->colonne2->setText(ui->colonne1->text()+"\n")   ;
                            }
                            Affiche_cartes1(C1,2,J) ;
                            //ui->colonne2->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                            break ;
                        }
                    case 3:
                        {
                            Carte C1 ;
                            C1=T.getColonne(2).top() ;
                            Carte::Formes F;
                            Carte::Valeurs V;
                            F=C1.getForme() ;
                            V=C1.getValeur() ;
                            int J ;
                            J=T.getColonne(2).size() ;
                            //ui->colonne1->setText("\n")   ;
                            for(int i=0 ; i<J-1 ; i++)
                            {
                                Affiche_empty(3,i+1) ;
                                //ui->colonne3->setText(ui->colonne1->text()+"\n")   ;
                            }
                            Affiche_cartes1(C1,3,J) ;
                            //ui->colonne3->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                            break ;
                        }
                    case 4:
                        {
                            Carte C1 ;
                            C1=T.getColonne(3).top() ;
                            Carte::Formes F;
                            Carte::Valeurs V;
                            F=C1.getForme() ;
                            V=C1.getValeur() ;
                            int J ;
                            J=T.getColonne(3).size() ;
                            //ui->colonne1->setText("\n")   ;
                            for(int i=0 ; i<J-1 ; i++)
                            {
                                Affiche_empty(4,i+1) ;
                                //ui->colonne4->setText(ui->colonne1->text()+"\n")   ;
                            }
                            Affiche_cartes1(C1,4,J) ;
                            //ui->colonne4->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                            break ;
                        }
                    case 5:
                        {
                            Carte C1 ;
                            C1=T.getColonne(4).top() ;
                            Carte::Formes F;
                            Carte::Valeurs V;
                            F=C1.getForme() ;
                            V=C1.getValeur() ;
                            int J ;
                            J=T.getColonne(4).size() ;
                            //ui->colonne1->setText("\n")   ;
                            for(int i=0 ; i<J-1 ; i++)
                            {
                                Affiche_empty(5,i+1) ;
                                //ui->colonne5->setText(ui->colonne1->text()+"\n")   ;
                            }
                            Affiche_cartes1(C1,5,J) ;
                            //ui->colonne5->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                            break ;
                        }
                    case 6:
                        {
                            Carte C1 ;
                            C1=T.getColonne(5).top() ;
                            Carte::Formes F;
                            Carte::Valeurs V;
                            F=C1.getForme() ;
                            V=C1.getValeur() ;
                            int J ;
                            J=T.getColonne(5).size() ;
                            //ui->colonne1->setText("\n")   ;
                            for(int i=0 ; i<J-1 ; i++)
                            {
                                Affiche_empty(6,i+1) ;
                                //ui->colonne6->setText(ui->colonne1->text()+"\n")   ;
                            }
                            Affiche_cartes1(C1,6,J) ;
                            //ui->colonne6->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                            break ;
                        }
                    case 7:
                        {
                            Carte C1 ;
                            C1=T.getColonne(6).top() ;
                            Carte::Formes F;
                            Carte::Valeurs V;
                            F=C1.getForme() ;
                            V=C1.getValeur() ;
                            int J ;
                            J=T.getColonne(6).size() ;
                            //ui->colonne1->setText("\n")   ;
                            for(int i=0 ; i<J-1 ; i++)
                            {
                                Affiche_empty(7,i+1) ;
                                //ui->colonne7->setText(ui->colonne1->text()+"\n")   ;
                            }
                            Affiche_cartes1(C1,7,J) ;
                            //ui->colonne7->setText(ui->colonne1->text()+'('+QString::number(V)+','+QString::number(F) + ')') ;
                            break ;
                        }
                      }

                            PC.Supp_Carte(nump-11) ;

                            switch (numd)
                                {
                                    case 11:
                                    {
                                        Carte::Formes F;
                                        Carte::Valeurs V;
                                        F=PC.getPile(0).top().getForme() ;
                                        V=PC.getPile(0).top().getValeur() ;
                                        Affiche_cartes(PC.getPile(0).top(),11) ;
                                        //ui->pile11->setText("("+QString::number(V)+','+QString::number(F) + ')') ;
                                        break ;
                                    }
                                case 12:
                                {
                                    Carte::Formes F;
                                    Carte::Valeurs V;
                                    F=PC.getPile(1).top().getForme() ;
                                    V=PC.getPile(1).top().getValeur() ;
                                    Affiche_cartes(PC.getPile(1).top(),12) ;
                                    //ui->pile12->setText("("+QString::number(V)+','+QString::number(F) + ')') ;
                                    break ;
                                }
                                case 13:
                                {
                                    Carte::Formes F;
                                    Carte::Valeurs V;
                                    F=PC.getPile(2).top().getForme() ;
                                    V=PC.getPile(2).top().getValeur() ;
                                    Affiche_cartes(PC.getPile(2).top(),13) ;
                                    //ui->pile13->setText("("+QString::number(V)+','+QString::number(F) + ')') ;
                                    break ;
                                }
                                case 14:
                                {
                                    Carte::Formes F;
                                    Carte::Valeurs V;
                                    F=PC.getPile(3).top().getForme() ;
                                    V=PC.getPile(3).top().getValeur() ;
                                    Affiche_cartes(PC.getPile(3).top(),13) ;
                                    //ui->pile14->setText("("+QString::number(V)+','+QString::number(F) + ')') ;
                                    break ;
                                }
                            }
                    }

                  }

            }

        }

}


void MainWindow::on_Astuce_clicked()
{
    int t=0 ;
    stack<int> S1 ;
    for(int i= 0 ;i<7 && t==0 ; i++)
    {
      S1=T.Rech_Sol(i) ;
      t=S1.size() ;
    }
    if (t != 3)
    {
      if (P.getPioche().empty() == false )
      {
        if (P.getPioche().top().estVisible())
        {
          Carte C ;
          C=P.getPioche().top() ;
          bool b1=false ;
          int x=0 ;
          while(x<7 && b1 == false)
          {
            if(T.getColonne(x).empty())
            {
              b1=T.AccepterRoi(C, x) ;
              if (b1 == true)
              {
                T.popCarte(x) ;
                //cout<<"la carte visible de la pioche peux etre utiliser dans la colonne"<<x+1<<endl ;
                S1.push(x+1) ;
              }

            }
            else
            {
              b1=T.Alternance(C, x) ;
              if (b1 == true)
              {
                T.popCarte(x) ;
                //cout<<"la carte visible de la pioche peux etre utiliser dans la colonne"<<x+1<<endl ;
                S1.push(x+1) ;
              }

            }
            x++;
          }
        }

      }
    }

    if (S1.size()== 3)
    {
        ui->numd1->setText(QString::number(S1.top())) ;
        S1.pop() ;
        ui->nump1->setText(QString::number(S1.top())) ;
        S1.pop() ;
        ui->nbrc1->setText(QString::number(S1.top())) ;
    }
    else if (S1.size()==1)
    {
        ui->numd1->setText(QString::number(S1.top())) ;
    }
    else
    {
        ui->numd1->setText("") ;
        ui->nump1->setText("") ;
        ui->nbrc1->setText("") ;
    }
}

void MainWindow::Affiche_cartes(Carte C,int x)
{
    Carte::Formes F;
    Carte::Valeurs V;
    F=C.getForme() ;
    V=C.getValeur() ;
    if(C.estVisible()== false)
    {
        switch (x)
        {
            case 0 :
            {
                ui->pioch->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"empty.gif"));
                break ;
            }
            case 1 :
            {
                ui->colonne1->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"empty.gif"));
                break ;
            }
            case 2 :
            {
                ui->colonne2->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"empty.gif"));
                break ;
            }
            case 3 :
            {
                ui->colonne3->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"empty.gif"));
                break ;
            }
            case 4 :
            {
                ui->colonne4->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"empty.gif"));
                break ;
            }
            case 5 :
            {
                ui->colonne5->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"empty.gif"));
                break ;
            }
            case 6 :
            {
                ui->colonne6->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"empty.gif"));
                break ;
            }
            case 7 :
            {
                ui->colonne7->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"empty.gif"));
                break ;
            }
            case 11 :
            {
                ui->pile11->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"empty.gif"));
                break ;
            }
            case 12 :
            {
                ui->pile12->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"empty.gif"));
                break ;
            }
            case 13 :
            {
                ui->pile13->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"empty.gif"));
                break ;
            }
            case 14 :
            {
                ui->pile14->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"empty.gif"));
                break ;
            }

        }

    }
    else if(F==Carte::carreau)
    {
        switch (x)
        {
        case 0 :
            {
                ui->pioch->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"d.gif"));
                break ;
            }
            case 1 :
            {
                ui->colonne1->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"d.gif"));
                break ;
            }
            case 2 :
            {
                ui->colonne2->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"d.gif"));
                break ;
            }
            case 3 :
            {
                ui->colonne3->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"d.gif"));
                break ;
            }
            case 4 :
            {
                ui->colonne4->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"d.gif"));
                break ;
            }
            case 5 :
            {
                ui->colonne5->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"d.gif"));
                break ;
            }
            case 6 :
            {
                ui->colonne6->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"d.gif"));
                break ;
            }
            case 7 :
            {
                ui->colonne7->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"d.gif"));
                break ;
            }
            case 11 :
            {
                ui->pile11->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"d.gif"));
                break ;
            }
            case 12 :
            {
                ui->pile12->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"d.gif"));
                break ;
            }
            case 13 :
            {
                ui->pile13->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"d.gif"));
                break ;
            }
            case 14 :
            {
                ui->pile14->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"d.gif"));
                break ;
            }

        }


    }
    else if(F==Carte::coeur)
    {
        switch (x)
        {
            case 0 :
            {
                ui->pioch->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"h.gif"));
                break ;
            }
            case 1 :
            {
                ui->colonne1->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"h.gif"));
                break ;
            }
            case 2 :
            {
                ui->colonne2->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"h.gif"));
                break ;
            }
            case 3 :
            {
                ui->colonne3->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"h.gif"));
                break ;
            }
            case 4 :
            {
                ui->colonne4->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"h.gif"));
                break ;
            }
            case 5 :
            {
                ui->colonne5->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"h.gif"));
                break ;
            }
            case 6 :
            {
                ui->colonne6->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"h.gif"));
                break ;
            }
            case 7 :
            {
                ui->colonne7->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"h.gif"));
                break ;
            }
            case 11 :
            {
                ui->pile11->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"h.gif"));
                break ;
            }
            case 12 :
            {
                ui->pile12->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"h.gif"));
                break ;
            }
            case 13 :
            {
                ui->pile13->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"h.gif"));
                break ;
            }
            case 14 :
            {
                ui->pile14->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"h.gif"));
                break ;
            }

        }
    }
    else if(F==Carte::pique)
    {
        switch (x)
        {
            case 0 :
            {
                ui->pioch->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"s.gif"));
                break ;
            }
            case 1 :
            {
                ui->colonne1->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"s.gif"));
                break ;
            }
            case 2 :
            {
                ui->colonne2->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"s.gif"));
                break ;
            }
            case 3 :
            {
                ui->colonne3->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"s.gif"));
                break ;
            }
            case 4 :
            {
                ui->colonne4->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"s.gif"));
                break ;
            }
            case 5 :
            {
                ui->colonne5->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"s.gif"));
                break ;
            }
            case 6 :
            {
                ui->colonne6->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"s.gif"));
                break ;
            }
            case 7 :
            {
                ui->colonne7->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"s.gif"));
                break ;
            }
            case 11 :
            {
                ui->pile11->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"s.gif"));
                break ;
            }
            case 12 :
            {
                ui->pile12->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"s.gif"));
                break ;
            }
            case 13 :
            {
                ui->pile13->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"s.gif"));
                break ;
            }
            case 14 :
            {
                ui->pile14->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"s.gif"));
                break ;
            }

        }
    }
    else if(F==Carte::trefle)
    {
        switch (x)
        {
            case 0 :
            {
                ui->pioch->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"c.gif"));
                break ;
            }
            case 1 :
            {
                ui->colonne1->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"c.gif"));
                break ;
            }
            case 2 :
            {
                ui->colonne2->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"c.gif"));
                break ;
            }
            case 3 :
            {
                ui->colonne3->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"c.gif"));
                break ;
            }
            case 4 :
            {
                ui->colonne4->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"c.gif"));
                break ;
            }
            case 5 :
            {
                ui->colonne5->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"c.gif"));
                break ;
            }
            case 6 :
            {
                ui->colonne6->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"c.gif"));
                break ;
            }
            case 7 :
            {
                ui->colonne7->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"c.gif"));
                break ;
            }
            case 11 :
            {
                ui->pile11->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"c.gif"));
                break ;
            }
            case 12 :
            {
                ui->pile12->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"c.gif"));
                break ;
            }
            case 13 :
            {
                ui->pile13->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"c.gif"));
                break ;
            }
            case 14 :
            {
                ui->pile14->setPixmap(QPixmap(":/images/"+QString::number(C.getValeur())+"c.gif"));
                break ;
            }

        }
    }







}

void MainWindow::Affiche_cartes1(Carte C, int x, int i)
{
    const QPixmap pixmap1 = ui->colonne1->pixmap();
    const QPixmap pixmap2 = ui->colonne2->pixmap();
    const QPixmap pixmap3 = ui->colonne3->pixmap();
    const QPixmap pixmap4 = ui->colonne4->pixmap();
    const QPixmap pixmap5 = ui->colonne5->pixmap();
    const QPixmap pixmap6 = ui->colonne6->pixmap();
    const QPixmap pixmap7 = ui->colonne7->pixmap();
    Carte::Formes F;
    Carte::Valeurs V;
    F=C.getForme() ;
    V=C.getValeur() ;
    if(F==Carte::carreau)
        {
            switch (x)
            {
            case 1 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap1);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"d.gif"));
                   painter->end();
                   ui->colonne1->setPixmap(*pixmap) ;

                   break ;
                }
            case 2 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap2);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"d.gif"));
                   painter->end();
                   ui->colonne2->setPixmap(*pixmap) ;

                   break ;
                }
            case 3 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap3);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"d.gif"));
                   painter->end();
                   ui->colonne3->setPixmap(*pixmap) ;

                   break ;
                }
            case 4 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap4);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"d.gif"));
                   painter->end();
                   ui->colonne4->setPixmap(*pixmap) ;

                   break ;
                }
            case 5 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap5);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"d.gif"));
                   painter->end();
                   ui->colonne5->setPixmap(*pixmap) ;

                   break ;
                }
            case 6 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap6);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"d.gif"));
                   painter->end();
                   ui->colonne6->setPixmap(*pixmap) ;

                   break ;
                }
            case 7 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap7);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"d.gif"));
                   painter->end();
                   ui->colonne7->setPixmap(*pixmap) ;

                   break ;
                }

            }
         }
    if(F==Carte::pique)
        {
            switch (x)
            {
            case 1 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap1);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"s.gif"));
                   painter->end();
                   ui->colonne1->setPixmap(*pixmap) ;

                   break ;
                }
            case 2 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap2);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"s.gif"));
                   painter->end();
                   ui->colonne2->setPixmap(*pixmap) ;

                   break ;
                }
            case 3 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap3);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"s.gif"));
                   painter->end();
                   ui->colonne3->setPixmap(*pixmap) ;

                   break ;
                }
            case 4 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap4);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"s.gif"));
                   painter->end();
                   ui->colonne4->setPixmap(*pixmap) ;

                   break ;
                }
            case 5 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap5);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"s.gif"));
                   painter->end();
                   ui->colonne5->setPixmap(*pixmap) ;

                   break ;
                }
            case 6 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap6);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"s.gif"));
                   painter->end();
                   ui->colonne6->setPixmap(*pixmap) ;

                   break ;
                }
            case 7 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap7);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"s.gif"));
                   painter->end();
                   ui->colonne7->setPixmap(*pixmap) ;

                   break ;
                }

            }
         }
    else if (F==Carte::coeur)
        {
            switch (x)
            {
            case 1 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap1);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"h.gif"));
                   painter->end();
                   ui->colonne1->setPixmap(*pixmap) ;

                   break ;
                }
            case 2 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap2);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"h.gif"));
                   painter->end();
                   ui->colonne2->setPixmap(*pixmap) ;

                   break ;
                }
            case 3 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap3);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"h.gif"));
                   painter->end();
                   ui->colonne3->setPixmap(*pixmap) ;

                   break ;
                }
            case 4 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap4);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"h.gif"));
                   painter->end();
                   ui->colonne4->setPixmap(*pixmap) ;

                   break ;
                }
            case 5 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap5);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"h.gif"));
                   painter->end();
                   ui->colonne5->setPixmap(*pixmap) ;

                   break ;
                }
            case 6 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap6);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"h.gif"));
                   painter->end();
                   ui->colonne6->setPixmap(*pixmap) ;

                   break ;
                }
            case 7 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap7);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"h.gif"));
                   painter->end();
                   ui->colonne7->setPixmap(*pixmap) ;

                   break ;
                }

            }
         }
    if(F==Carte::trefle)
        {
            switch (x)
            {
            case 1 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap1);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"c.gif"));
                   painter->end();
                   ui->colonne1->setPixmap(*pixmap) ;

                   break ;
                }
            case 2 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap2);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"c.gif"));
                   painter->end();
                   ui->colonne2->setPixmap(*pixmap) ;

                   break ;
                }
            case 3 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap3);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"c.gif"));
                   painter->end();
                   ui->colonne3->setPixmap(*pixmap) ;

                   break ;
                }
            case 4 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap4);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"c.gif"));
                   painter->end();
                   ui->colonne4->setPixmap(*pixmap) ;

                   break ;
                }
            case 5 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap5);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"c.gif"));
                   painter->end();
                   ui->colonne5->setPixmap(*pixmap) ;

                   break ;
                }
            case 6 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap6);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"c.gif"));
                   painter->end();
                   ui->colonne6->setPixmap(*pixmap) ;

                   break ;
                }
            case 7 :
                {
                QPixmap *pixmap=new QPixmap(71, 96*(i));
                    //tosna3 les dim mtal war9aa
                   pixmap->fill(Qt::transparent);
                   QPainter *painter=new QPainter(pixmap);
                   painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap7);
                   painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/"+QString::number(C.getValeur())+"c.gif"));
                   painter->end();
                   ui->colonne7->setPixmap(*pixmap) ;

                   break ;
                }

            }
         }


}

void MainWindow::Affiche_empty(int x, int i)
{
    const QPixmap pixmap1 = ui->colonne1->pixmap();
    const QPixmap pixmap2 = ui->colonne2->pixmap();
    const QPixmap pixmap3 = ui->colonne3->pixmap();
    const QPixmap pixmap4 = ui->colonne4->pixmap();
    const QPixmap pixmap5 = ui->colonne5->pixmap();
    const QPixmap pixmap6 = ui->colonne6->pixmap();
    const QPixmap pixmap7 = ui->colonne7->pixmap();
    switch (x)
    {
    case 1 :
        {
        QPixmap *pixmap=new QPixmap(71, 96*(i));
            //tosna3 les dim mtal war9aa
           pixmap->fill(Qt::transparent);
           QPainter *painter=new QPainter(pixmap);
           painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap1);
           painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/empty.gif"));
           painter->end();
           ui->colonne1->setPixmap(*pixmap) ;

           break ;
        }
    case 2 :
        {
        QPixmap *pixmap=new QPixmap(71, 96*(i));
            //tosna3 les dim mtal war9aa
           pixmap->fill(Qt::transparent);
           QPainter *painter=new QPainter(pixmap);
           painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap2);
           painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/empty.gif"));
           painter->end();
           ui->colonne2->setPixmap(*pixmap) ;

           break ;
        }
    case 3 :
        {
        QPixmap *pixmap=new QPixmap(71, 96*(i));
            //tosna3 les dim mtal war9aa
           pixmap->fill(Qt::transparent);
           QPainter *painter=new QPainter(pixmap);
           painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap3);
           painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/empty.gif"));
           painter->end();
           ui->colonne3->setPixmap(*pixmap) ;

           break ;
        }
    case 4 :
        {
        QPixmap *pixmap=new QPixmap(71, 96*(i));
            //tosna3 les dim mtal war9aa
           pixmap->fill(Qt::transparent);
           QPainter *painter=new QPainter(pixmap);
           painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap4);
           painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/empty.gif"));
           painter->end();
           ui->colonne4->setPixmap(*pixmap) ;

           break ;
        }
    case 5 :
        {
        QPixmap *pixmap=new QPixmap(71, 96*(i));
            //tosna3 les dim mtal war9aa
           pixmap->fill(Qt::transparent);
           QPainter *painter=new QPainter(pixmap);
           painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap5);
           painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/empty.gif"));
           painter->end();
           ui->colonne5->setPixmap(*pixmap) ;

           break ;
        }
    case 6 :
        {
        QPixmap *pixmap=new QPixmap(71, 96*(i));
            //tosna3 les dim mtal war9aa
           pixmap->fill(Qt::transparent);
           QPainter *painter=new QPainter(pixmap);
           painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap6);
           painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/empty.gif"));
           painter->end();
           ui->colonne6->setPixmap(*pixmap) ;

           break ;
        }
    case 7 :
        {
        QPixmap *pixmap=new QPixmap(71, 96*(i));
            //tosna3 les dim mtal war9aa
           pixmap->fill(Qt::transparent);
           QPainter *painter=new QPainter(pixmap);
           painter->drawPixmap(0, 0, 71, 96*(i-1), pixmap7);
           painter->drawPixmap(0, 15*i, 71, 96, QPixmap(":/images/empty.gif"));
           painter->end();
           ui->colonne7->setPixmap(*pixmap) ;

           break ;
        }

    }


}

void MainWindow::on_pushButton_clicked()
{
    Carte C(Carte::carreau,Carte::deux,Carte::V) ;
    Carte C1(Carte::carreau,Carte::As,Carte::V) ;
    T.popCarte(0) ;
    T.AjoutCarte(0,C) ;
    T.AjoutCarte(0,C1) ;
    Affiche_cartes1(C,1,1) ;
    Affiche_cartes1(C1,1,2) ;


}

