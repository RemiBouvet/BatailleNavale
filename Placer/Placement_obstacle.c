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
t_case grille[N][M];
void placer_obstacle(int num_grille){
	int compteur_o=0,i=0,j=0,res;	
	srand(time(NULL));
	while(compteur_o<nb_obstacle){
		i=uHasard(N);
		j=uHasard(M);
		Grille_lire_obstacle(i,j,num_grille,&res);
		if(res==0){
			Grille_ecrire_obstacle(i,j,num_grille,Obstacle);
			compteur_o++;
		}
	}
}

