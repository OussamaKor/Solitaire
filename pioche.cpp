#include "pioche.h"
#include "carte.h"

Pioche::Pioche()
{

}
Pioche::Pioche(stack<Carte> c)
{
    Carte p;
    while (c.size() != 0)
    {
        p = c.top() ;
        pioche.push(p) ;
        c.pop() ;
    }
}
Pioche::~Pioche() {}
void Pioche::Melanger(Carte C)
{
    stack<Carte> pile ;
    while(pioche.size() != 0 )
    {
        pile.push(pioche.top()) ;
        pioche.pop() ;
    }
    C.setVisible(Carte::C) ;
    pile.push(C) ;
    while (pile.size() != 0)
    {
        pioche.push(pile.top()) ;
        pile.pop();
    }

}
void Pioche::Ajouter_Carte(Carte C){
  pioche.push(C) ;
}
void Pioche::sup_Carte()
{
  pioche.pop() ;
}
stack<Carte> Pioche::getPioche(){
  return pioche ;
}

Carte Pioche::Retourner_Carte()
{
    Carte c ;
    c = pioche.top() ;
    pioche.pop() ;
    c.setVisible(Carte::V) ;
    return c ;
}
