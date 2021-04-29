#include "pilecouleur.h"
#include "carte.h"
#include <stack>
using namespace std  ;

PileCouleur::PileCouleur()
{}
PileCouleur::~PileCouleur() {}
bool PileCouleur::AccepterAs(Carte C, int k)
{
    if ( pilecoleur[k].size() == 0 )
    {
        if (C.getValeur()== Carte::As)
        {
            pilecoleur[k].push(C) ;
            return true ;
        }
    return false ;
    }
}
bool PileCouleur::Unicite(Carte C,int k) {
    int q = C.getValeur()-1 ;
    Carte::Valeurs d ;
    d=(Carte::Valeurs)q ;
    if (pilecoleur[k].top().getValeur() == d  && pilecoleur[k].top().getForme() == C.getForme() )
    {
        pilecoleur[k].push(C) ;
        return true ;
    }
    else
    {
        return false ;
    }
}
void PileCouleur::Supp_Carte(int k){
  pilecoleur[k].pop() ;
}
stack<Carte> PileCouleur::getPile(int k){
  return pilecoleur[k] ;
}
int PileCouleur::sizePile(int k) {
    return pilecoleur[k].size() ;
}

