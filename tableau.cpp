#include "Tableau.h"
#include "carte.h"
#include <stack>
using namespace std  ;

Tableau::Tableau()
{}
Tableau::Tableau(stack<Carte> pile)
{
    for (int i=0 ; i<7 ; i++)
    {
        for (int j=0 ; j<=i ; j++)
        {
            Carte c ;
            c=pile.top() ;
            tableau[i].push(c) ;
            pile.pop();
        }
        tableau[i].top().inverser();
    }
}
Tableau::~Tableau(){}
int *Tableau::getPileVide()
{
    int *T ;
    T=new int[7] ;
    int j=0;
    for (int i= 0 ; i<7 ; i++)
    {
        if (tableau[i].size() == 0)
        {
            T[j] = i ;
            j++ ;
        }
    }
    return T ;
}
void Tableau::setinverser(int k) {
  tableau[k].top().setVisible(Carte::Visibles::V) ;
}
bool Tableau::AccepterRoi (stack<Carte> C,int k)
{
    if (tableau[k].size() == 0)
    {
        stack<Carte> C1 ;
        while(C.size() != 0)
        {
            C1.push(C.top());
            C.pop();
        }
        if (C1.top().getValeur() == Carte::Roi)
        {
            while (C1.size() !=0)
            {
                tableau[k].push(C1.top()) ;
                C1.pop() ;
            }
            return true ;
        }
        else
        {
            while (C1.size() !=0)
            {
                C.push(C1.top()) ;
                C1.pop() ;
            }
        }
    }
    return false ;
}
bool Tableau::AccepterRoi (Carte C,int k)
{
    if (tableau[k].size() == 0)
    {
        if (C.getValeur() == Carte::Roi)
        {
            tableau[k].push(C) ;
            return true ;
        }

    }
    else
    return false ;
}
void Tableau::popCarte(int k){
  tableau[k].pop() ;
}
bool Tableau::Alternance(stack<Carte> C, int k)
{
    stack<Carte> C1 ;
    while(C.size() != 0)
    {
        C1.push(C.top());
        C.pop();
    }
    int q = C1.top().getValeur()+1 ;
    Carte::Valeurs d ;
    d=(Carte::Valeurs)q ;
    if (tableau[k].top().getValeur() == d && tableau[k].top().estRouge() != C1.top().estRouge() )
    // kifeh ne5dhou il successeur fil énumération ?
    {
        while (C1.size() != 0)
        {
            tableau[k].push(C1.top()) ;
            C1.pop();
        }
        return true ;

    }
    else
    {
        while (C1.size() != 0)
        {
            C.push(C1.top()) ;
            C1.pop();
        }
        return false ;

    }
}
bool Tableau::Alternance(Carte C, int k)
{
    bool b=false ;
    int q = C.getValeur() +1 ;
    Carte::Valeurs d ;
    d=(Carte::Valeurs)q ;
    if (tableau[k].top().getValeur() == d && tableau[k].top().estRouge() != C.estRouge() )
    // kifeh ne5dhou il successeur fil énumération ?
    {
        tableau[k].push(C) ;
        b=true ;
    }
    return b ;
}
void Tableau::setStack(int k)
{
  tableau[k].pop() ;
}
stack<Carte> Tableau::getColonne(int k) {
  return tableau[k] ;
}


stack<int> Tableau::Rech_Sol(int k){
  stack<int> Res ;
  stack<Carte> S,S1 ;
  bool b11=false ;
  S=Tableau::getColonne(k) ;
  while(S.empty() == false && b11 == false )
  {
        if (S.top().estVisible() == true )
        {
            S1.push(S.top());
            S.pop() ;
        }
        else
        {
            b11=true ;
        }
    }
    int w=0 ;
    bool b=false;

    while(w<7 && b == false)
    {
        if(w != k && S1.empty()==false )
        {
            int q =S1.top().getValeur()+1 ;
            Carte::Valeurs d ;
            d=(Carte::Valeurs)q ;
            if(tableau[w].empty() && S1.top().getValeur() == Carte::Roi)
            {
                int f ;
                f=S1.size() ;
                Res.push(f) ;
                Res.push(k+1) ;
                Res.push(w+1);
                b=true ;
                //cout<<"On peut faire un deplacement de"<<f<<"Carte de la colonne "<<k+1<<"vers la colonne "<<w+1<<endl ;
            }
            else if (tableau[w].top().getValeur() == d && tableau[w].top().estRouge() != S1.top().estRouge())
            {
                int f ;
                f=S1.size() ;
                Res.push(f) ;
                Res.push(k+1) ;
                Res.push(w+1);
                b=true ;
                //cout<<"On peut faire un deplacement de"<<f<<"Carte de la colonne "<<k+1<<"vers la colonne "<<w+1<<endl ;
            }
        }
        w++ ;
  }
  return Res ;
}
void Tableau::AjoutCarte(int k,Carte C){
    tableau[k].push(C) ;
}

