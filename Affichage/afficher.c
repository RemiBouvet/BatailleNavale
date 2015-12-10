#include "../grille/Grille.h"
#include "../grille/Struct.h"
#include "../grille/Outil.h"
#include "afficher.h"
#include "couleur.h"

t_plateau grille;

void Grille_perso_afficher(int num_grille){
/* Fonction permettant d'afficher la grille du joueur qui contient ses bateaux, les obstacles, les cibles touchées et les torpilleurs*/
	 int i,j, k;
	 int nL=0;
	 if(num_grille==1){
		 printf("***********************************  GRILLE JOUEUR 1  *********************************** \n \n");
		 printf("            A    B    C    D    E    F    G    H    I    J \n");
			for(i=0;i < N ; i++){
				printf("\t");
				for(k=0;k < N ; k++){
					printf("-----");
				}
				printf("-\n\t%i |",nL);
				nL++;
				for(j=0; j < M ; j++){
	                Grille_lire_case(i, j,num_grille,*(grille.grille1));
					
					if(grille.grille1[i][j].obstacle == Obstacle){
						printf(" X ");
					}
					else if (grille.grille1[i][j].obstacle == Aucun_o){
						if((grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Present)||(grille.grille1[i][j].bateau == Sous_Marin && grille.grille1[i][j].torpilleur==Present) || (grille.grille1[i][j].bateau == Destroyer && grille.grille1[i][j].torpilleur==Present) || (grille.grille1[i][j].bateau == Porte_Avion && grille.grille1[i][j].torpilleur==Present) ){
							printf(" TP ");
						}
						/*else if((grille.grille1[i][j].bateau == Sous_Marin && grille.grille1[i][j].torpilleur==Present) || (grille.grille1[i][j].bateau == Destroyer && grille.grille1[i][j].torpilleur==Present) || (grille.grille1[i][j].bateau == Porte_Avion && grille.grille1[i][j].torpilleur==Present))
							printf("TPB");
						if(grille.grille1[i][j].bateau == Aucun_b){
							printf("    ");
						}*/
						else if(grille.grille1[i][j].bateau == Sous_Marin){
							if(grille.grille1[i][j].toucher == Oui)
								printf("SM_T");
							else{
								printf(" SM ");
							}
						}
						else if(grille.grille1[i][j].bateau == Destroyer){
							if(grille.grille1[i][j].toucher == Oui)
								printf("DE_T");
							else{
								printf(" DE ");
							}
						}
						else if(grille.grille1[i][j].bateau == Porte_Avion){
							if(grille.grille1[i][j].toucher == Oui)
								printf("PA_T");
							else{
								printf(" PA ");
							}
						}
						else {printf("    ");}
					}
					printf("|");
				}
				printf("\n");
			}
			printf("\t");
			for(k=0;k < N ; k++) printf("-----");
	    	printf("\n\n");
		} else {
			printf("***********************************  GRILLE JOUEUR 2  *********************************** \n \n");
		 	printf("           A    B    C    D    E    F    G    H    I    J \n");
			for(i=0;i < N ; i++){
				printf("\t");
				for(k=0;k < N ; k++)
					printf("-----");
				printf("-\n\t%i |",nL);
				nL++;
				for(j=0; j < M ; j++){
	                Grille_lire_case(i, j,num_grille,*(grille.grille2));
					
					if(grille.grille2[i][j].obstacle == Obstacle )
						printf(" X ");
					else if (grille.grille2[i][j].obstacle == Aucun_o){
						if((grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Present)||(grille.grille1[i][j].bateau == Sous_Marin && grille.grille1[i][j].torpilleur==Present) || (grille.grille1[i][j].bateau == Destroyer && grille.grille1[i][j].torpilleur==Present) || (grille.grille1[i][j].bateau == Porte_Avion && grille.grille1[i][j].torpilleur==Present) ){
							printf(" TP ");
						}
						/*if(grille.grille2[i][j].bateau == Aucun_b){
							printf("    ");
						}*/
						else if(grille.grille2[i][j].bateau == Sous_Marin){
							if(grille.grille2[i][j].toucher == Oui)
								printf("SM_T");
							else{
								printf(" SM ");
							}
						}
						else if(grille.grille2[i][j].bateau == Destroyer){
							if(grille.grille2[i][j].toucher == Oui)
								printf("DE_T");
							else{
								printf(" DE ");
							}
						}
						else if(grille.grille2[i][j].bateau == Porte_Avion){
							if(grille.grille2[i][j].toucher == Oui)
								printf("PA_T");
							else{
								printf(" PA ");
							}
						}else {printf("    ");}	
					}
					printf("|");
				}
				printf("\n");
			}
			printf("\t");
			for(k=0;k < N ; k++) printf("-----");
	    	printf("\n\n");
		}
    	printf("CORRESPONDANCE DES SYMBOLES :\n");
    	printf("t = torpilleur");
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
/* Fonction permettant d'afficher la grille masquée de l'adversaire qui contient les obstacles ainsi que les cibles touchées */ 
	int i,j, k;
	int nL=0;
	if(num_grille==2){
	 	printf("***********************************  GRILLE ADVERSE CACHEE  *********************************** \n\n");
	 	printf("           A    B    C    D    E    F    G    H    I    J \n");
		for(i=0;i < N ; i++){
			printf("\t");
			for(k=0;k < N ; k++)
				printf("-----");
			printf("-\n\t%i |",nL);
				nL++;
			for(j=0; j < M ; j++){
				Grille_lire_case(i, j,num_grille,*(grille.grille1));
				if(grille.grille1[i][j].obstacle == Obstacle )
					printf(" X ");
				else if (grille.grille1[i][j].obstacle == Aucun_o){
					if(grille.grille1[i][j].bateau == Aucun_b)
						printf("    ");
					else if(grille.grille1[i][j].torpilleur == Present)
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
    }else {
    	printf("***********************************  GRILLE ADVERSE CACHEE  *********************************** \n\n");
	 	printf("           A    B    C    D    E    F    G    H    I    J \n");
		for(i=0;i < N ; i++){
			printf("\t");
			for(k=0;k < N ; k++)
				printf("-----");
			printf("-\n\t%i |",nL);
				nL++;
			for(j=0; j < M ; j++){
				Grille_lire_case(i, j,num_grille,*(grille.grille2));
				if(grille.grille2[i][j].obstacle == Obstacle )
					printf(" X ");
				else if (grille.grille2[i][j].obstacle == Aucun_o){
					if(grille.grille2[i][j].bateau == Aucun_b)
						printf("    ");
					else if(grille.grille2[i][j].torpilleur == Present)
						printf("    ");
					else if(grille.grille2[i][j].bateau == Sous_Marin){
						if(grille.grille2[i][j].toucher == Oui)
							printf(" T ");
						else
							printf("    ");
					}
					else if(grille.grille2[i][j].bateau == Destroyer){
						if(grille.grille2[i][j].toucher == Oui)
							printf(" T ");
						else
							printf("    ");
					}
					else if(grille.grille2[i][j].bateau == Porte_Avion){
						if(grille.grille2[i][j].toucher == Oui)
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
    }
    	printf("CORRESPONDANCE DES SYMBOLES :\n");
    	printf("T = touché");
    	printf("\n");
    	printf("X = obstacle");
    	printf("\n\n");
}