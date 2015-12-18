/**
*\mainpage Bataille navale ++ by BOUVET Remi & PRADERE-NIQUET Alexandre & ZERBANE Mehdi
* \file TorpilleurChoisir.h
* \brief fichier qui contient l'ensemble des prototypes de TorpilleurChoisir.c
* \author BOUVET Remi
* \version 1.0
*/

#ifndef TORPILLEUR_CHOIX
#define TORPILLEUR_CHOIX

#include "JouerStruct.h"
void Jouer_Trouver_Torpilleur(int eJoueur, t_coordonnee cBateau[],int N_Torpilleur);
void Jouer_Selectionner_Torpilleur(int eJoueur, t_coordonnee cTorpilleur[], int *peNumero_Torpilleur, int N_Torpilleur);

#endif
