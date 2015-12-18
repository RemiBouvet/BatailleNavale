/**
*\mainpage Bataille navale ++ by BOUVET Remi & PRADERE-NIQUET Alexandre & ZERBANE Mehdi
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
 * \struct t_coordonnee JouerStruct.h Structure_Jouer
 * \brief structure qui permet de rassembler deux entier x et y pour y stocker comme son nom l’indique des coordonées
 */
typedef struct {int x;int y;} t_coordonnee;

/**
* \enum t_direction JouerStruct.h Structure_Jouer
* \brief enumeration permettant de definir la direction que le torpilleur pourra prendre
*/
typedef enum{Aucune, Haut, Bas, Gauche, Droite}t_direction;

#endif
