/**
* \file Placement_obstacle.c
* \brief fichier qui contient l'ensemble des fonctions pour placer des obstacles.
* \author ZERBANE Mehdi
* \version 1.0
*/

#include "../../include/Struct.h"
#include "../../include/Outil.h"
#include "../../include/Grille.h"
#define nb_obstacle 5

/**
* \fn placer_obstacle()
* \brief Fonction permettant de placer aléatoirement des obstacles
*
* \param Aucun
* \return Ne retourne rien
*
*/

void placer_obstacle(){
	int compteur_o=0,i=0,j=0,res,res2;	
	srand(time(NULL));
	while(compteur_o<nb_obstacle){
		i=uHasard(N);
		j=uHasard(M);
		Grille_lire_obstacle(i,j,1,&res);
				Grille_lire_obstacle(i,j,2,&res2);

		if(res==0){
			Grille_ecrire_obstacle(i,j,1,Obstacle);
						Grille_ecrire_obstacle(i,j,2,Obstacle);

			compteur_o++;
		}
	}
}

