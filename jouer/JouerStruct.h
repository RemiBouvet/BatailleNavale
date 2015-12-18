/**
* \file JouerStruct.h
* \brief fichier qui contient l'ensemble des structures pour le module jouer.
* \author BOUVET Remi
* \version 1.0
*/

#ifndef STRUCTURE_JOUER
#define STRUCTURE_JOUER


#include "../grille/Grille.h"
#include "../Affichage/include/afficher.h"
#include "../grille/Struct.h"
#include <stdlib.h>

/**
* \struct typedef struct {int x;int y;} t_coordonnee
* \brief structure pour des coordonnées 
* \enum typedef enum{Aucune, Haut, Bas, Gauche, Droite}t_direction
* \brief enumeration permettant de definir la direction que le torpilleur pourra prendre
*/
typedef struct {int x;int y;} t_coordonnee;
typedef enum{Aucune, Haut, Bas, Gauche, Droite}t_direction;

#endif
