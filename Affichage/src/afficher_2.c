#include "../../grille/Grille.h"
#include "../../grille/Struct.h"
#include "../../grille/Outil.h"
#include "../include/afficher.h"
#include "../include/couleur.h"

t_plateau grille;

void Grille_perso_afficher(int num_grille){
	 int i,j, k;
	 int nL=0;
	 if(num_grille==1){
		 printf("***********************************  GRILLE JOUEUR 1  *********************************** \n \n");
		 printf("            A   B   C   D   E   F   G   H   I   J \n");
			for(i=0;i < N ; i++){
				couleur(0);
				printf("\t");
				for(k=0;k < N ; k++){
					couleur(0);
					printf("----");
				}
				couleur(0);
				printf("-\n\t%i |",nL);
				nL++;
				for(j=0; j < M ; j++){
	                Grille_lire_case(i, j,num_grille,*(grille.grille1));
					
					if(grille.grille1[i][j].obstacle == Obstacle ){
						printf(" X ");
					}
					else if (grille.grille1[i][j].obstacle == Aucun_o){
						if((grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Present)||(grille.grille1[i][j].bateau == Sous_Marin && grille.grille1[i][j].torpilleur==Present) || (grille.grille1[i][j].bateau == Destroyer && grille.grille1[i][j].torpilleur==Present) || (grille.grille1[i][j].bateau == Porte_Avion && grille.grille1[i][j].torpilleur==Present)){
							/*printf("TP");*/
							printf("   ");
							couleur(43);
						}
						else if(grille.grille1[i][j].bateau == Sous_Marin){
							if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t){
								/*printf("SM_T");*/
								printf("   ");
								couleur(41);
							}else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present){
								printf("   ");
								couleur(43);
							}
							else{
								/*printf(" SM ");*/
								printf("   ");
								couleur(46);
							}
						}
						else if(grille.grille1[i][j].bateau == Destroyer){
							if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t){
								/*printf("DE_T");*/
								printf("   ");
								couleur(41);
							}
							else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present){
								printf("   ");
								couleur(43);
							}
							else{
								/*printf(" DE ");*/
								printf("   ");
								couleur(45);
							}
						}
						else if(grille.grille1[i][j].bateau == Porte_Avion){
							if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t){
								/*printf("PA_T");*/
								printf("   ");
								couleur(41);
							}
							else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present){
								printf("   ");
								couleur(43);
							}
							else{
								/*printf(" PA ");*/
								printf("   ");
								couleur(42);
							}
						}
						else{
							printf("   ");
							couleur(44);
						}	
					}
					printf("|");
				}
				printf("\n");
			}
			printf("\t");
			
			for(k=0;k < N ; k++){
				couleur(0);
				printf("----");
			}
			couleur(0);
	    	printf("\n\n");
		} else {
			printf("***********************************  GRILLE JOUEUR 2  *********************************** \n \n");
		 	printf("           A    B    C    D    E    F    G    H    I    J \n");
			for(i=0;i < N ; i++){
				couleur(0);
				printf("\t");
				for(k=0;k < N ; k++){
					couleur(0);
					printf("----");
				}
				couleur(0);
				printf("-\n\t%i |",nL);
				nL++;
				for(j=0; j < M ; j++){
	                Grille_lire_case(i, j,num_grille,*(grille.grille2));
					
					if(grille.grille2[i][j].obstacle == Obstacle ){
						printf(" X ");
					}
					else if (grille.grille2[i][j].obstacle == Aucun_o){
						if(grille.grille2[i][j].torpilleur==Present){
							/*printf("TP");*/
							printf("    ");
							couleur(43);
						}
						else if((grille.grille2[i][j].bateau == Sous_Marin && grille.grille2[i][j].torpilleur==Present) || (grille.grille2[i][j].bateau == Destroyer && grille.grille2[i][j].torpilleur==Present) || (grille.grille2[i][j].bateau == Porte_Avion && grille.grille2[i][j].torpilleur==Present)){
							/*printf("TPB");*/
							printf("    ");
							couleur(43);
						}
						if(grille.grille2[i][j].bateau == Aucun_b){
							printf("   ");
							couleur(44);
						}
						else if(grille.grille2[i][j].bateau == Sous_Marin){
							if(grille.grille2[i][j].toucher == Oui){
								/*printf("SM_T");*/
								printf("   ");
								couleur(41);
							}
							else{
								/*printf(" SM ");*/
								printf("   ");
								couleur(46);
							}
						}
						else if(grille.grille2[i][j].bateau == Destroyer){
							if(grille.grille2[i][j].toucher == Oui){
								/*printf("DE_T");*/
								printf("   ");
								couleur(41);
							}
							else{
								/*printf(" DE ");*/
								printf("   ");
								couleur(45);
							}
						}
						else if(grille.grille2[i][j].bateau == Porte_Avion){
							if(grille.grille2[i][j].toucher == Oui){
								/*printf("PA_T");*/
								printf("   ");
								couleur(41);
							}
							else{
								/*printf(" PA ");*/
								printf("   ");
								couleur(42);
							}
						}	
					}
					couleur(0);
					printf("|");
				}
				printf("\n");
			}
			printf("\t");
			
			for(k=0;k < N ; k++){
				couleur(0);
				printf("----");
			}
			couleur(0);
	    	printf("\n\n");
		}
		couleur(0);
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
	if(num_grille==2){
	 	printf("***********************************  GRILLE ADVERSE CACHEE  *********************************** \n\n");
	 	printf("           A    B    C    D    E    F    G    H    I    J \n");
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
			printf("-\n\t|");
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

