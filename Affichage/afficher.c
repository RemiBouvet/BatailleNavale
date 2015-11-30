#include "Grille.h"
#include "Struct.h"
#include "Outil.h"
#include "afficher.h"

t_plateau grille;

void Grille_perso_afficher(int num_grille){
	 int i,j, k;
	 
	 Appel0("Grille_afficher");
	 printf("***********************************  GRILLE PERSONNEL  *********************************** \n");
		for(i=0;i < N ; i++){
			printf("\t");
			for(k=0;k < N ; k++)
				printf("----");
			printf("-\n\t|");
			for(j=0; j < M ; j++){
                Grille_lire_case(i, j,num_grille,*(grille.grille1));
				
				if(grille.grille1[i][j].obstacle == Obstacle )
					printf(" X ");
				else if (grille.grille1[i][j].obstacle == Aucun_o){
					if(grille.grille1[i][j].bateau == Aucun_b)
						printf(" 0 ");
					else if(grille.grille1[i][j].bateau == Torpilleur)
						printf(" TP ");
					else if(grille.grille1[i][j].bateau == Sous_Marin){
						if(grille.grille1[i][j].toucher == Oui)
							printf(" SM_T ");
						else
							printf(" SM ");
					}
					else if(grille.grille1[i][j].bateau == Destroyer){
						if(grille.grille1[i][j].toucher == Oui)
							printf(" D_T ");
						else
							printf(" D ");
					}
					else if(grille.grille1[i][j].bateau == Porte_Avion){
						if(grille.grille1[i][j].toucher == Oui)
							printf(" PA_T ");
						else
							printf(" PA ");
					}	
				}
				printf("|");
			}
			printf("\n");
		}
		printf("\t");
	 Appel1("Grille_afficher");
}

void Grille_masque_afficher(int num_grille){
	int i,j, k;

	 Appel0("Grille_afficher");
	 	printf("***********************************  GRILLE ADVERSE CACHEE  *********************************** \n");
		for(i=0;i < N ; i++){
			printf("\t");
			for(k=0;k < N ; k++)
				printf("----");
			printf("-\n\t|");
			for(j=0; j < M ; j++){
				Grille_lire_case(i, j,num_grille,*(grille.grille1));
				if(grille.grille1[i][j].obstacle == Obstacle )
					printf(" X ");
				else if (grille.grille1[i][j].obstacle == Aucun_o){
					if(grille.grille1[i][j].bateau == Aucun_b)
						printf(" 0 ");
					else if(grille.grille1[i][j].bateau == Torpilleur)
						printf(" 0 ");
					else if(grille.grille1[i][j].bateau == Sous_Marin){
						if(grille.grille1[i][j].toucher == Oui)
							printf(" T ");
						else
							printf(" 0 ");
					}
					else if(grille.grille1[i][j].bateau == Destroyer){
						if(grille.grille1[i][j].toucher == Oui)
							printf(" T ");
						else
							printf(" 0 ");
					}
					else if(grille.grille1[i][j].bateau == Porte_Avion){
						if(grille.grille1[i][j].toucher == Oui)
							printf(" T ");
						else
							printf(" 0 ");
					}	
				}
				printf("|");
			}
			printf("\n");
		}
		printf("\t");
	 Appel1("Grille_afficher");
}
