//
//  Placement_obstacle.c
//
//
//  Created by Zerbane Mehdi on 02/12/2015.
//
//
#include "../grille/Struct.h"
#include "../grille/Outil.h"
#include "../grille/Grille.h"
#define nb_obstacle 5
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

