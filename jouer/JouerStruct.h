#ifndef STRUCTURE_JOUER
#define STRUCTURE_JOUER

//#define N_Torpilleur 2

#include "../grille/Grille.h"
#include "../Affichage/include/afficher.h"
#include <ncurses.h>

typedef struct {int x;int y;} t_coordonnee;
typedef enum{Aucune, Haut, Bas, Gauche, Droite}t_direction;

#endif
