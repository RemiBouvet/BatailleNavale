/**
*\mainpage Bataille navale ++ by BOUVET Remi & PRADERE-NIQUET Alexandre & ZERBANE Mehdi
* \file Struct.h
* \brief fichier qui contient l'ensemble des structures pour gestion grille.
* \author BOUVET Remi & PRADERE-NIQUET Alexandre & ZERBANE Mehdi
* \version 1.0
*/

#ifndef STRUCTURE
#define STRUCTURE

#define N 10
#define M 10
#include <ncurses.h>

/**
* \enum t_bateau Struct.h Structure
* \brief enumeration regroupant les differents bateaux ainsi que leurs tailles en cases
*/
typedef enum{Aucun_b=0,Sous_Marin=3,Destroyer=4,Porte_Avion=5}t_bateau;
/**
* \enum t_toucher Struct.h Structure
* \brief enumeration pour verifier presence obstacle ou non
*/
typedef enum{Aucun_o=0,Obstacle=1}t_obstacle;
/**
* \enum t_obstacle Struct.h Structure
* \brief enumeration si un tir a touche une case ou non
*/
typedef enum{Non=0,Oui=1}t_toucher;
/**
* \enum t_torpilleur Struct.h Structure
* \brief enumeration pour verifier s'il y a un torpilleur ou non
*/
typedef enum{Aucun_t=0,Present=1}t_torpilleur;

/**
 * \struct t_case Struct.h Structure
 * \brief structure pour connaitre contenu d'une case
 */
typedef struct {t_bateau bateau;t_obstacle obstacle;t_toucher toucher;t_torpilleur torpilleur;}t_case;
/**
 * \struct t_plateau Struct.h Structure
 * \brief structure contenant les grilles
 */
typedef struct{t_case grille1[N][M];t_case grille2[N][M];}t_plateau;

/**
* \enum t_portee Struct.h Structure
* \brief enumeration permettant de savoir si la cible est a portee
*/
typedef enum{Hors_Portee, Portee} t_portee;

#endif
