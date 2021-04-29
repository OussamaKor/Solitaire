#ifndef GAME_H
#define GAME_H
#include "Tableau.h"
#include "pioche.h"
#include "pilecouleur.h"
#include "carte.h"
#include <stack>
using namespace std  ;

class Game
{
public:
    Game() ;
    ~Game();
    bool test(stack<Carte> ,Carte) ;
    stack<Carte> initialisation();
    bool endJeu(Pioche , Tableau , PileCouleur);
    void afficher(Tableau , PileCouleur , Pioche) ;
    stack<int> Help(Tableau , Pioche) ;
};

#endif // GAME_H
