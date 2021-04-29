#ifndef PILECOULEUR_H
#define PILECOULEUR_H
#include "carte.h"
#include<stack>
using namespace std  ;
class PileCouleur
{
public:
    PileCouleur();
    ~PileCouleur() ;
    bool AccepterAs(Carte ,int) ;
    bool Unicite(Carte,int) ;
    stack<Carte> getPile(int) ;
    void Supp_Carte(int) ;
    int sizePile(int) ;
    void afficherPileColeur(int);
    private :
    stack<Carte> pilecoleur[4] ;
};

#endif // PILECOULEUR_H
