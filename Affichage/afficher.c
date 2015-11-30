#include "Grille.h"
#include "Struct.h"
#include "Outil.h"
#include "afficher.h"

t_plateau grille;

void Grille_perso_afficher(int num_grille){
	 int i,j, k;
	 
	 printf("***********************************  GRILLE PERSONNEL  *********************************** \n");
		for(i=0;i < N ; i++){
			printf("\t");
			for(k=0;k < N ; k++)
				printf("-----");
			printf("-\n\t|");
			for(j=0; j < M ; j++){
                Grille_lire_case(i, j,num_grille,*(grille.grille1));
				
				if(grille.grille1[i][j].obstacle == Obstacle )
					printf(" X ");
				else if (grille.grille1[i][j].obstacle == Aucun_o){
					if(grille.grille1[i][j].bateau == Aucun_b)
						printf("    ");
					else if(grille.grille1[i][j].bateau == Torpilleur)
						printf(" TP ");
					else if(grille.grille1[i][j].bateau == Sous_Marin){
						if(grille.grille1[i][j].toucher == Oui)
							printf("SM_T");
						else
							printf(" SM ");
					}
					else if(grille.grille1[i][j].bateau == Destroyer){
						if(grille.grille1[i][j].toucher == Oui)
							printf("DE_T");
						else
							printf(" DE ");
					}
					else if(grille.grille1[i][j].bateau == Porte_Avion){
						if(grille.grille1[i][j].toucher == Oui)
							printf("PA_T");
						else
							printf(" PA ");
					}	
				}
				printf("|");
			}
			printf("\n");
		}
		printf("\t");
		for(k=0;k < N ; k++) printf("-----");
    	printf("\n\n");
    	printf("CORRESPONDANCE DES SYMBOLES :\n");
    	printf("TP = torpilleur");
    	printf("\n");
    	printf("SM = sous-matin");
    	printf("\n");
    	printf("DE = destroyer");
    	printf("\n");
    	printf("PA = porte-avion");
    	printf("\n");
    	printf("'nom'_T = 'nom' touché");
    	printf("\n");
    	printf("X = obstacle");
    	printf("\n\n");
}

void Grille_masque_afficher(int num_grille){
	int i,j, k;

	 	printf("***********************************  GRILLE ADVERSE CACHEE  *********************************** \n");
		for(i=0;i < N ; i++){
			printf("\t");
			for(k=0;k < N ; k++)
				printf("-----");
			printf("-\n\t|");
			for(j=0; j < M ; j++){
				Grille_lire_case(i, j,num_grille,*(grille.grille1));
				if(grille.grille1[i][j].obstacle == Obstacle )
					printf(" X ");
				else if (grille.grille1[i][j].obstacle == Aucun_o){
					if(grille.grille1[i][j].bateau == Aucun_b)
						printf("    ");
					else if(grille.grille1[i][j].bateau == Torpilleur)
						printf("    ");
					else if(grille.grille1[i][j].bateau == Sous_Marin){
						if(grille.grille1[i][j].toucher == Oui)
							printf(" T ");
						else
							printf("    ");
					}
					else if(grille.grille1[i][j].bateau == Destroyer){
						if(grille.grille1[i][j].toucher == Oui)
							printf(" T ");
						else
							printf("    ");
					}
					else if(grille.grille1[i][j].bateau == Porte_Avion){
						if(grille.grille1[i][j].toucher == Oui)
							printf(" T ");
						else
							printf("    ");
					}	
				}
				printf("|");
			}
			printf("\n");
		}
		printf("\t");
		for(k=0;k < N ; k++)
			printf("-----");
    	printf("\n\n");
    	printf("CORRESPONDANCE DES SYMBOLES :\n");
    	printf("T = touché");
    	printf("\n");
    	printf("X = obstacle");
    	printf("\n\n");

}
