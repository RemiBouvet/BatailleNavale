#include "Grille.h"
#include "Struct.h"
#include "Outil.h"
#include "afficher.h"

void Grille_perso_afficher(int num_grille,t_case ensemble[N][M]){
	 int nC,nL, k;
	 Appel0("Grille_afficher");
		for(nL=0;nL < N ; nL++){
			printf("\t");
			for(k=0;k < N ; k++)
				printf("-----");
			printf("-\n\t|");
			for(nC=0; nC < M ; nC++){
				Grille_lire_case(nL, nC,num_grille,ensemble);
				/*printf("%i %i %i", ensemble[nL][nC].obstacle, ensemble[nL][nC].bateau, ensemble[nL][nC].toucher);*/
				
				if(ensemble[nL][nC].obstacle == Obstacle )
					printf(" X ");
				else if (ensemble[nL][nC].obstacle == Aucun_o){
					if(ensemble[nL][nC].bateau == Aucun_b)
						printf(" 0 ");
					else if(ensemble[nL][nC].bateau == Torpilleur)
						printf(" TP ");
					else if(ensemble[nL][nC].bateau == Sous_Marin){
						if(ensemble[nL][nC].toucher == Oui)
							printf(" SM_T ");
						else
							printf(" SM ");
					}
					else if(ensemble[nL][nC].bateau == Destroyer){
						if(ensemble[nL][nC].toucher == Oui)
							printf(" D_T ");
						else
							printf(" D ");
					}
					else if(ensemble[nL][nC].bateau == Porte_Avion){
						if(ensemble[nL][nC].toucher == Oui)
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

void Grille_masque_afficher(int num_grille,t_case ensemble[N][M]){
	int nC,nL, k;
	 Appel0("Grille_afficher");
		for(nL=0;nL < N ; nL++){
			printf("\t");
			for(k=0;k < N ; k++)
				printf("-----");
			printf("-\n\t|");
			for(nC=0; nC < M ; nC++){
				Grille_lire_case(nL, nC,num_grille,ensemble);
				if(ensemble[nL][nC].obstacle == Obstacle )
					printf(" X ");
				else if (ensemble[nL][nC].obstacle == Aucun_o){
					if(ensemble[nL][nC].bateau == Aucun_b)
						printf(" 0 ");
					else if(ensemble[nL][nC].bateau == Torpilleur)
						printf(" 0 ");
					else if(ensemble[nL][nC].bateau == Sous_Marin){
						if(ensemble[nL][nC].toucher == Oui)
							printf(" T ");
						else
							printf(" 0 ");
					}
					else if(ensemble[nL][nC].bateau == Destroyer){
						if(ensemble[nL][nC].toucher == Oui)
							printf(" T ");
						else
							printf(" 0 ");
					}
					else if(ensemble[nL][nC].bateau == Porte_Avion){
						if(ensemble[nL][nC].toucher == Oui)
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
