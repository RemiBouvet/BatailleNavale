//
//  Placement_obstacle.c
//
//
//  Created by Zerbane Mehdi on 02/12/2015.
//
//
#include "Struct.h"
#include "Outil.h"
#include "Grille.h"
#define nb_obstacle 5
t_case grille[N][M];
void placer_obstacle(int num_grille){
	int compteur_o=0,i=0,j=0;	
	srand(time(NULL));
	for(compteur_o=0;compteur_o<nb_obstacle;compteur_o++){
		i=uHasard(N);
		j=uHasard(M);
		Grille_ecrire_obstacle(i,j,num_grille,Obstacle);
	}
}

