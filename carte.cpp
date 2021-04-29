#include "carte.h"

Carte::Carte()
{

}
Carte::Carte(Formes F, Valeurs V, Visibles Vi=C ) : Forme(F) ,Valeur(V) ,Visible(Vi)
{}
Carte::Carte(const Carte& obj)
{
    Forme=obj.Forme;
    Valeur=obj.Valeur;
    Visible=obj.Visible ;
    //construteur de recopie
}
Carte::~Carte() {}
bool Carte::operator== ( const Carte& c) {

    return c.Valeur==Valeur && c.Forme==Forme ;
}
void Carte::operator= ( const Carte& c) {

    Valeur= c.Valeur;
    Forme= c.Forme ;
    Visible= c.Visible ;
}
Carte::Formes Carte::getForme() const {return Forme ;}
Carte::Valeurs Carte::getValeur() const {return Valeur ;}
void Carte::setVisible (Visibles Vis = V)  {Visible = Vis  ;}
bool Carte::estRouge() const
{
    if (Forme == coeur || Forme == carreau )
    {
        return true ;
    }
    else
    {
        return false ;
    }
}
bool Carte::estVisible() const
{
    if (Visible == V)
    {
        return true ;
    }
    else
    {
        return false ;
    }
}
void Carte::inverser()
{
    if (Visible == V)
    {
        Visible = C ;
    }
    else
    {
        Visible = V ;
    }
}
