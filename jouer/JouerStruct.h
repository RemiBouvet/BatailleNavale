#ifndef STRUCTURE_JOUER
#define STRUCTURE_JOUER


#include "../grille/Grille.h"
#include "../Affichage/include/afficher.h"
#include "../grille/Struct.h"
#include <stdlib.h>

typedef struct {int x;int y;} t_coordonnee;
typedef enum{Aucune, Haut, Bas, Gauche, Droite}t_direction;

#endif
