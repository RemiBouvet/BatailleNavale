/**
*\mainpage Bataille navale ++ by BOUVET Remi & PRADERE-NIQUET Alexandre & ZERBANE Mehdi
* \file TorpilleurDeplacer.h
* \brief fichier qui contient l'ensemble des prototypes de TorpilleurDeplacer.c
* \author BOUVET Remi
* \version 1.0
*/

#ifndef TORPILLEUR_DEPLACER
#define TORPILLEUR_DEPLACER

#include "JouerStruct.h"

int Jouer_Deplacement_Valide(int eJoueur, t_direction direction, int eNumero_Torpilleur, t_coordonnee cTorpilleur[], int N_Torpilleur);
void Jouer_Deplacer_Torpilleur(int eJoueur, t_direction direction, int eNumero_Torpilleur, t_coordonnee cTorpilleur[], int N_Torpilleur);
void Jouer_Choisir_Direction(t_direction *dDirection);

#endif
