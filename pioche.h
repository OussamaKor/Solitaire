#ifndef PIOCHE_H
#define PIOCHE_H
#include "carte.h"
#include<stack>
using namespace std  ;

class Pioche
{
public:
    Pioche();
    Pioche(stack<Carte>);
    void Melanger(Carte C);
    Carte Retourner_Carte();
    stack<Carte> getPioche() ;
    ~Pioche();
    void Ajouter_Carte(Carte ) ;
    void sup_Carte() ;

    private:
    stack<Carte> pioche ;
};

#endif // PIOCHE_H
