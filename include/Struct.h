/**
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
* \enum typedef enum{Aucun_b=0,Sous_Marin=3,Destroyer=4,Porte_Avion=5}t_bateau
* \brief enumeration regroupant les differents bateaux ainsi que leurs tailles en cases
* \enum typedef enum{Aucun_o=0,Obstacle=1}t_obstacle
* \brief enumeration pour presence obstacle ou non
* \enum typedef enum{Non=0,Oui=1}t_toucher
* \brief enumeration si un tir a touche un bateau ou non
* \enum typedef enum{Aucun_t=0,Present=1}t_torpilleur
* \brief enumeration s'il y a un torpilleur ou non
* \struct typedef struct {t_bateau bateau;t_obstacle obstacle;t_toucher toucher;t_torpilleur torpilleur;}t_case
* \brief structure connaitre contenu d'une case
* \struct typedef struct{t_case grille1[N][M];t_case grille2[N][M];}t_plateau
* \brief structure contenant les grilles
* \enum typedef enum{Hors_Portee, Portee} t_portee
* \brief enumeration permettant de savoir si la cible est a portee
*/

typedef enum{Aucun_b=0,Sous_Marin=3,Destroyer=4,Porte_Avion=5}t_bateau;
typedef enum{Aucun_o=0,Obstacle=1}t_obstacle;
typedef enum{Non=0,Oui=1}t_toucher;
typedef enum{Aucun_t=0,Present=1}t_torpilleur;

typedef struct {t_bateau bateau;t_obstacle obstacle;t_toucher toucher;t_torpilleur torpilleur;}t_case;

typedef struct{t_case grille1[N][M];t_case grille2[N][M];}t_plateau;


typedef enum{Hors_Portee, Portee} t_portee;

#endif
