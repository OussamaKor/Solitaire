#include "game.h"
#include "Tableau.h"
#include "pioche.h"
#include "pilecouleur.h"
#include "carte.h"
#include <stack>
#include <stdlib.h>
using namespace std  ;
//Oussama Kordoghli
Game::Game(){}
Game::~Game(){}
bool Game::test(stack<Carte> S,Carte C)
{
    stack<Carte> S1;
    bool T=false ;
    while(S.size() != 0 && T == false )
    {
        if(S.top() == C)
        {
            T=true ;
        }
        else
        {
            S1.push(S.top()) ;
            S.pop() ;
        }

    }
    while(S1.size() != 0)
    {
        S.push(S1.top());
        S1.pop() ;

    }
    return T ;
}
stack<Carte> Game::initialisation(){
    int i=0 ;
    stack<Carte> S ;
    while (S.size() <52 ){
        int V1,V2;
        V1 = rand() % 4 ;
        V2 = rand() % 13 +1 ;
        Carte::Formes f ;
        Carte::Valeurs v;
        f=(Carte::Formes) V1 ;
        v=(Carte::Valeurs) V2 ;
        Carte C1(f,v,Carte::C) ;
        if(S.size()== 0)
        {
            S.push(C1) ;
            i++ ;

        }
        else if (test(S,C1) == false)
        {
          S.push(C1);
          i++ ;
        }
    }
    return S ;
}
bool Game::endJeu(Pioche P, Tableau T, PileCouleur PC){
  bool b = false ;
    if (PC.sizePile(0)==13 && PC.sizePile(1)==13 && PC.sizePile(2)==13 && PC.sizePile(3)==13 )
    {
        b= true ;
    }
    return b ;
}
stack<int> Game::Help(Tableau T, Pioche P){
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
return S1 ;
}

