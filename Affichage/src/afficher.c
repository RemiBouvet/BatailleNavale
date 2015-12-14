#include "../../grille/Grille.h"
#include "../../grille/Struct.h"
#include "../../grille/Outil.h"
#include "../include/afficher.h"

t_portee gPortee[N][M];
t_plateau grille;
/* FAIRE UNE FONCTION POUR AFFICHER LA PORTE D'UN TORPILLEUR+SELECTION CASE A VISER  ET UNE FONCTION POUR LA SELECTION DE TORPILLEUR */

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
						printf(" XX ");
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
							if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t)
								printf("SM_T");
							else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present)
								printf("TSMT");
							else{
								printf(" SM ");
							}
						}
						else if(grille.grille1[i][j].bateau == Destroyer){
							if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t)
								printf("DE_T");
							else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present)
								printf("TDET");
							else{
								printf(" DE ");
							}
						}
						else if(grille.grille1[i][j].bateau == Porte_Avion ){
							if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t)
								printf("PA_T");
							else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present)
								printf("TPAT");
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
						printf(" XX ");
					else if (grille.grille2[i][j].obstacle == Aucun_o){
						if((grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Present)||(grille.grille2[i][j].bateau == Sous_Marin && grille.grille2[i][j].torpilleur==Present) || (grille.grille2[i][j].bateau == Destroyer && grille.grille2[i][j].torpilleur==Present) || (grille.grille2[i][j].bateau == Porte_Avion && grille.grille2[i][j].torpilleur==Present) ){
							printf(" TP ");
						}
						/*if(grille.grille2[i][j].bateau == Aucun_b){
							printf("    ");
						}*/
						else if(grille.grille2[i][j].bateau == Sous_Marin){
							if(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t)
								printf("SM_T");
							else if(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present)
								printf("TSMT");
							else{
								printf(" SM ");
							}
						}
						else if(grille.grille2[i][j].bateau == Destroyer){
							if(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t)
								printf("DE_T");
							else if(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present)
								printf("TDET");
							else{
								printf(" DE ");
							}
						}
						else if(grille.grille2[i][j].bateau == Porte_Avion){
							if(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t)
								printf("PA_T");
							else if(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present)
								printf("TPAT");
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
    	printf("TP = torpilleur seul ou sur un bateau");
    	printf("\n");
    	printf("SM = sous-matin");
    	printf("\n");
    	printf("DE = destroyer");
    	printf("\n");
    	printf("PA = porte-avion");
    	printf("\n");
    	printf("'nom'_T ='bateau' touché");
    	printf("\n");
    	printf("T'nom'T =torpilleur sur 'bateau' touché");
    	printf("\n");
    	printf("XX = obstacle");
    	printf("\n\n");
}

void Grille_masque_afficher(int num_grille){
/* Fonction permettant d'afficher la grille masquée de l'adversaire qui contient les obstacles ainsi que les cibles touchées */ 
	int i,j, k;
	int nL=0;
	if(num_grille==2){
	 	printf("***********************************  GRILLE ADVERSE CACHEE  *********************************** \n\n");
	 	printf("            A    B    C    D    E    F    G    H    I    J \n");
		for(i=0;i < N ; i++){
			printf("\t");
			for(k=0;k < N ; k++)
				printf("-----");
			printf("-\n\t%i |",nL);
				nL++;
			for(j=0; j < M ; j++){
				Grille_lire_case(i, j,num_grille,*(grille.grille1));
				/* si il y a un obstacle, on affcihe XX*/
				if(grille.grille1[i][j].obstacle == Obstacle )
					printf(" XX ");
				/*si il n'y pas d'obstacle */
				else if (grille.grille1[i][j].obstacle == Aucun_o){
					/* si il n'y a rien on affiche une espace*/
					if(grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t)
						printf("    ");
					/* si le joueur adverse a un torpilleur on affiche une espace*/
					else if((grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)||(grille.grille1[i][j].bateau == Sous_Marin && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t) || (grille.grille1[i][j].bateau == Destroyer && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t) || (grille.grille1[i][j].bateau == Porte_Avion && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t))
						printf("    ");
					/* si le joueur 1 a un sous marin*/
					else if(grille.grille1[i][j].bateau == Sous_Marin){
						/* si le joueur adverse a un sous marin touche et un torpilleur ou non on affiche BT*/
						if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)||(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
							printf(" BT ");
														/*else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t)
															printf(" BT ");
														else
															printf("    ");*/

						/*si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche*/  
						else if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
							printf("T_BT");
					}
					/* si le joueur 1 a un Destroyer */
					else if(grille.grille1[i][j].bateau == Destroyer ){
						/* si le joueur adverse a un Destroyer touche et un torpilleur ou non, on affiche BT*/
						if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)|| (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
							printf(" BT ");
														/*else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t)
															printf(" BT ");
														else
															printf("    ");*/
						/*si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche */
						else if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
							printf("T_BT");
					}
					/* si le joueur 1 a un Porte_Avion */
					else if(grille.grille1[i][j].bateau == Porte_Avion){
						/* si le joueur adverse a un porte avion touche et un torpilleur ou non, on affiche BT*/
						if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
							printf(" BT ");
														/*else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t)
															printf(" BT ");
														else
															printf("    ");*/
						/*si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche */
						else if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
							printf("T_BT");
					}
					/* si l'adversaire n'a pas de bateau touche,n'a pas de torpilleur et que le joueur qui joue a un torpilleur, on affiche le torpilleur*/
					else if ((grille.grille1[i][j].toucher == Non && grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present)||(grille.grille1[i][j].toucher == Non && grille.grille1[i][j].bateau == Sous_Marin && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Non && grille.grille1[i][j].bateau == Destroyer && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Non && grille.grille1[i][j].bateau == Porte_Avion && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present))
						printf(" TP ");
					/* si l'adversaire n'a pas de bateau touche, a un torpilleur et que le joueur qui joue a un torpilleur, on affiche le torpilleur */
					else if ((grille.grille1[i][j].toucher == Non && grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present)||(grille.grille1[i][j].toucher == Non && grille.grille1[i][j].bateau == Sous_Marin && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Non && grille.grille1[i][j].bateau == Destroyer && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Non && grille.grille1[i][j].bateau == Porte_Avion && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
						printf(" TP ");	
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
    /*else if(num_grille==1){
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
					printf(" XX ");
				else if (grille.grille2[i][j].obstacle == Aucun_o){
					if(grille.grille2[i][j].bateau == Aucun_b)
						printf("    ");
					else if((grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Present)||(grille.grille2[i][j].bateau == Sous_Marin && grille.grille2[i][j].torpilleur==Present) || (grille.grille2[i][j].bateau == Destroyer && grille.grille2[i][j].torpilleur==Present) || (grille.grille2[i][j].bateau == Porte_Avion && grille.grille2[i][j].torpilleur==Present))
						printf("    ");
					else if(grille.grille2[i][j].bateau == Sous_Marin){
						if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present)||(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t))
							printf(" BT ");
						else
							printf("    ");
					}
					else if(grille.grille2[i][j].bateau == Destroyer){
						if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present)||(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t))
							printf(" BT ");
						else
							printf("    ");
					}
					else if(grille.grille2[i][j].bateau == Porte_Avion){
						if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present)||(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t))
							printf(" BT ");
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
    }*/
    else if(num_grille==1){
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
				/* si il y a un obstacle, on affcihe XX*/
				if(grille.grille2[i][j].obstacle == Obstacle )
					printf(" XX ");
				/*si il n'y pas d'obstacle */
				else if (grille.grille2[i][j].obstacle == Aucun_o){
					/* si il n'y a rien on affiche une espace*/
					if(grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t)
						printf("    ");
					/* si le joueur adverse a un torpilleur on affiche une espace*/
					else if((grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t)||(grille.grille2[i][j].bateau == Sous_Marin && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t) || (grille.grille2[i][j].bateau == Destroyer && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t) || (grille.grille2[i][j].bateau == Porte_Avion && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t))
						printf("    ");
					/* si le joueur 1 a un sous marin*/
					else if(grille.grille2[i][j].bateau == Sous_Marin){
						/* si le joueur adverse a un sous marin touche et un torpilleur ou non on affiche BT*/
						if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t)||(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t))
							printf(" BT ");
														/*else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t)
															printf(" BT ");
														else
															printf("    ");*/

						/*si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche*/  
						else if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
							printf("T_BT");
					}
					/* si le joueur 1 a un Destroyer */
					else if(grille.grille2[i][j].bateau == Destroyer ){
						/* si le joueur adverse a un Destroyer touche et un torpilleur ou non, on affiche BT*/
						if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t)|| (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t))
							printf(" BT ");
														/*else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t)
															printf(" BT ");
														else
															printf("    ");*/
						/*si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche */
						else if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
							printf("T_BT");
					}
					/* si le joueur 1 a un Porte_Avion */
					else if(grille.grille2[i][j].bateau == Porte_Avion){
						/* si le joueur adverse a un porte avion touche et un torpilleur ou non, on affiche BT*/
						if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t))
							printf(" BT ");
														/*else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t)
															printf(" BT ");
														else
															printf("    ");*/
						/*si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche */
						else if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
							printf("T_BT");
					}
					/* si l'adversaire n'a pas de bateau touche,n'a pas de torpilleur et que le joueur qui joue a un torpilleur, on affiche le torpilleur*/
					else if ((grille.grille2[i][j].toucher == Non && grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present)||(grille.grille2[i][j].toucher == Non && grille.grille2[i][j].bateau == Sous_Marin && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Non && grille.grille2[i][j].bateau == Destroyer && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Non && grille.grille2[i][j].bateau == Porte_Avion && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present))
						printf(" TP ");
					/* si l'adversaire n'a pas de bateau touche, a un torpilleur et que le joueur qui joue a un torpilleur, on affiche le torpilleur */
					else if ((grille.grille2[i][j].toucher == Non && grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present)||(grille.grille2[i][j].toucher == Non && grille.grille2[i][j].bateau == Sous_Marin && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Non && grille.grille2[i][j].bateau == Destroyer && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Non && grille.grille2[i][j].bateau == Porte_Avion && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
						printf(" TP ");	
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
    	printf("BT = bateau touché");
    	printf("\n");
    	printf("T_BT = torpilleur sur bateau touché");
    	printf("\n");
    	printf("X = obstacle");
    	printf("\n\n");
}

/* FAIRE UNE FONCTION POUR AFFICHER LA PORTE D'UN TORPILLEUR+SELECTION CASE A VISER  ET UNE FONCTION POUR LA SELECTION DE TORPILLEUR */

void Portee_torpilleur_afficher(t_portee gPortee[N][M],int num_grille){
	int i,j, k;
	int nL=0;
	if(num_grille==2){
	 	printf("***********************************  GRILLE ATTAQUE JOUEUR 2 *********************************** \n\n");
	 	printf("            A    B    C    D    E    F    G    H    I    J \n");
		for(i=0;i < N ; i++){
			printf("\t");
			for(k=0;k < N ; k++)
				printf("-----");
			printf("-\n\t%i |",nL);
				nL++;
			for(j=0; j < M ; j++){
				Grille_lire_case(i, j,num_grille,*(grille.grille1));
				/* si il y a un obstacle, on affcihe XX*/
				if(grille.grille1[i][j].obstacle == Obstacle )
					printf(" XX ");
				/*si il n'y pas d'obstacle */
				else if (grille.grille1[i][j].obstacle == Aucun_o){
					/* si il n'y a rien on affiche une espace*/
					if(grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t)
						printf("    ");
					else if(grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t && gPortee[i][j]==1)
						printf(" PJ ");
					/* si le joueur adverse a un torpilleur on affiche une espace*/
					else if((grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)||(grille.grille1[i][j].bateau == Sous_Marin && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t) || (grille.grille1[i][j].bateau == Destroyer && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t) || (grille.grille1[i][j].bateau == Porte_Avion && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t))
						printf("    ");
					else if((grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t && gPortee[i][j]==1)||(grille.grille1[i][j].bateau == Sous_Marin && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t && gPortee[i][j]==1) || (grille.grille1[i][j].bateau == Destroyer && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t && gPortee[i][j]==1) || (grille.grille1[i][j].bateau == Porte_Avion && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t && gPortee[i][j]==1))
						printf(" PJ ");
					/* si le joueur 1 a un sous marin*/
					else if(grille.grille1[i][j].bateau == Sous_Marin && gPortee[i][j]==0){
						/* si le joueur adverse a un sous marin touche et un torpilleur ou non on affiche BT*/
						if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)||(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
							printf(" BT ");
													
						/*si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche*/  
						/*else if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
							printf("T_BT");*/
					}
					else if(grille.grille1[i][j].bateau == Sous_Marin && gPortee[i][j]==1){
						/* si le joueur adverse a un sous marin touche et un torpilleur ou non on affiche BT*/
						if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)||(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
							printf(" BT ");					

						/*si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche*/  
						else if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
							printf(" BT ");
					}
					/* si le joueur 1 a un Destroyer */
					else if(grille.grille1[i][j].bateau == Destroyer && gPortee[i][j]==0 ){
						/* si le joueur adverse a un Destroyer touche et un torpilleur ou non, on affiche BT*/
						if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)|| (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
							printf(" BT ");
														
						/*si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche */
						/*else if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
							printf("T_BT");*/
					}
					else if(grille.grille1[i][j].bateau == Destroyer && gPortee[i][j]==1){
						/* si le joueur adverse a un Destroyer touche et un torpilleur ou non, on affiche BT*/
						if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)|| (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
							printf(" BT ");
														
						/*si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche */
						else if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
							printf(" BT ");
					}
					/* si le joueur 1 a un Porte_Avion */
					else if(grille.grille1[i][j].bateau == Porte_Avion && gPortee[i][j]==0){
						/* si le joueur adverse a un porte avion touche et un torpilleur ou non, on affiche BT*/
						if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
							printf(" BT ");
													
						/*si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche */
						/*else if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
							printf("T_BT");*/
					}
					else if(grille.grille1[i][j].bateau == Porte_Avion && gPortee[i][j]==1){
						/* si le joueur adverse a un porte avion touche et un torpilleur ou non, on affiche BT*/
						if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
							printf(" BT ");
														
						/*si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche */
						else if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
							printf(" BT ");
					}
					/* si l'adversaire n'a pas de bateau touche,n'a pas de torpilleur et que le joueur qui joue a un torpilleur, on affiche le torpilleur*/
					else if (gPortee[i][j]==1 &&((grille.grille1[i][j].toucher == Non && grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present)||(grille.grille1[i][j].toucher == Non && grille.grille1[i][j].bateau == Sous_Marin && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Non && grille.grille1[i][j].bateau == Destroyer && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Non && grille.grille1[i][j].bateau == Porte_Avion && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present)))
						printf(" PJ ");
					/* si l'adversaire n'a pas de bateau touche, a un torpilleur et que le joueur qui joue a un torpilleur, on affiche le torpilleur */
					else if (gPortee[i][j]==1 &&((grille.grille1[i][j].toucher == Non && grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present)||(grille.grille1[i][j].toucher == Non && grille.grille1[i][j].bateau == Sous_Marin && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Non && grille.grille1[i][j].bateau == Destroyer && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Non && grille.grille1[i][j].bateau == Porte_Avion && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present)))
						printf(" PJ ");	
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
    else if(num_grille==1){
    	printf("***********************************  GRILLE ATTAQUE JOUEUR 1 *********************************** \n\n");
	 	printf("           A    B    C    D    E    F    G    H    I    J \n");
		for(i=0;i < N ; i++){
			printf("\t");
			for(k=0;k < N ; k++)
				printf("-----");
			printf("-\n\t%i |",nL);
				nL++;
			for(j=0; j < M ; j++){
				Grille_lire_case(i, j,num_grille,*(grille.grille1));
				/* si il y a un obstacle, on affcihe XX*/
				if(grille.grille2[i][j].obstacle == Obstacle )
					printf(" XX ");
				/*si il n'y pas d'obstacle */
				else if (grille.grille2[i][j].obstacle == Aucun_o){
					/* si il n'y a rien on affiche une espace*/
					if(grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t)
						printf("    ");
					else if(grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t && gPortee[i][j]==1)
						printf(" PJ ");
					
					/* si le joueur adverse a un torpilleur on affiche une espace*/
					else if((grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t)||(grille.grille2[i][j].bateau == Sous_Marin && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t) || (grille.grille2[i][j].bateau == Destroyer && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t) || (grille.grille2[i][j].bateau == Porte_Avion && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t))
						printf("    ");
					else if((grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t && gPortee[i][j]==1)||(grille.grille2[i][j].bateau == Sous_Marin && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t && gPortee[i][j]==1) || (grille.grille2[i][j].bateau == Destroyer && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t && gPortee[i][j]==1) || (grille.grille2[i][j].bateau == Porte_Avion && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t && gPortee[i][j]==1))
						printf(" PJ ");
					/* si le joueur 1 a un sous marin*/
					else if(grille.grille2[i][j].bateau == Sous_Marin && gPortee[i][j]==0){
						/* si le joueur adverse a un sous marin touche et un torpilleur ou non on affiche BT*/
						if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t)||(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t))
							printf(" BT ");
						/*si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche*/  
						/*else if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
							printf("T_BT");*/
					}
					else if(grille.grille2[i][j].bateau == Sous_Marin && gPortee[i][j]==1){
						/* si le joueur adverse a un sous marin touche et un torpilleur ou non on affiche BT*/
						if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t)||(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t))
							printf(" BT ");
						/*si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche*/  
						else if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
							printf(" BT ");
					}
					/* si le joueur 1 a un Destroyer */
					else if(grille.grille2[i][j].bateau == Destroyer && gPortee[i][j]==0){
						/* si le joueur adverse a un Destroyer touche et un torpilleur ou non, on affiche BT*/
						if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t)|| (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t))
							printf(" BT ");
						/*si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche */
						/*else if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
							printf("T_BT");*/
					}
					else if(grille.grille2[i][j].bateau == Destroyer && gPortee[i][j]==1){
						/* si le joueur adverse a un Destroyer touche et un torpilleur ou non, on affiche BT*/
						if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t)|| (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t))
							printf(" BT ");
						/*si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche */
						else if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
							printf(" BT ");
					}
					/* si le joueur 1 a un Porte_Avion */
					else if(grille.grille2[i][j].bateau == Porte_Avion && gPortee[i][j]==0){
						/* si le joueur adverse a un porte avion touche et un torpilleur ou non, on affiche BT*/
						if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t))
							printf(" BT ");
						/*si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche */
						/*else if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
							printf("T_BT");*/
					}
					else if(grille.grille2[i][j].bateau == Porte_Avion && gPortee[i][j]==1){
						/* si le joueur adverse a un porte avion touche et un torpilleur ou non, on affiche BT*/
						if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t))
							printf(" BT ");
						/*si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche */
						else if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
							printf(" BT ");
					}
					/* si l'adversaire n'a pas de bateau touche,n'a pas de torpilleur et que le joueur qui joue a un torpilleur, on affiche le torpilleur*/
					else if ((grille.grille2[i][j].toucher == Non && grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present)||(grille.grille2[i][j].toucher == Non && grille.grille2[i][j].bateau == Sous_Marin && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Non && grille.grille2[i][j].bateau == Destroyer && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Non && grille.grille2[i][j].bateau == Porte_Avion && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present))
						printf(" PJ ");
					/* si l'adversaire n'a pas de bateau touche, a un torpilleur et que le joueur qui joue a un torpilleur, on affiche le torpilleur */
					else if ((grille.grille2[i][j].toucher == Non && grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present)||(grille.grille2[i][j].toucher == Non && grille.grille2[i][j].bateau == Sous_Marin && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Non && grille.grille2[i][j].bateau == Destroyer && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Non && grille.grille2[i][j].bateau == Porte_Avion && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
						printf(" PJ ");	
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
    	printf("BT = bateau touché");
    	printf("\n");
    	/*printf("T_BT = torpilleur sur bateau touché");
    	printf("\n");*/
    	printf("PJ = portee torpilleur");
    	printf("\n");
    	printf("X = obstacle");
    	printf("\n\n");
}

void torpilleur_selection_afficher(int x,int y, int num_grille){
	int i,j, k;
	int nL=0;
	if(num_grille==2){
	 	printf("***********************************  GRILLE SYMBOLES TORPILLEUR  *********************************** \n\n");
	 	printf("            A    B    C    D    E    F    G    H    I    J \n");
		for(i=0;i < N ; i++){
			printf("\t");
			for(k=0;k < N ; k++)
				printf("-----");
			printf("-\n\t%i |",nL);
				nL++;
			for(j=0; j < M ; j++){
				Grille_lire_case(i, j,num_grille,*(grille.grille1));
				/* si il y a un obstacle, on affcihe XX*/
				if(grille.grille1[i][j].obstacle == Obstacle )
					printf(" XX ");
				/*si il n'y pas d'obstacle */
				else if (grille.grille1[i][j].obstacle == Aucun_o){
					/* si il n'y a rien on affiche une espace*/
					if(grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t)
						printf("    ");
					/* si le joueur adverse a un torpilleur on affiche une espace*/
					else if((grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)||(grille.grille1[i][j].bateau == Sous_Marin && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t) || (grille.grille1[i][j].bateau == Destroyer && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t) || (grille.grille1[i][j].bateau == Porte_Avion && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t))
						printf("    ");
					/* si le joueur 1 a un sous marin*/
					else if(grille.grille1[i][j].bateau == Sous_Marin){
						/* si le joueur adverse a un sous marin touche et un torpilleur ou non on affiche BT*/
						if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)||(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
							printf(" BT ");
														/*else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t)
															printf(" BT ");
														else
															printf("    ");*/

						/*si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche*/  
						else if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
							printf("JOUE");
					}
					/* si le joueur 1 a un Destroyer */
					else if(grille.grille1[i][j].bateau == Destroyer ){
						/* si le joueur adverse a un Destroyer touche et un torpilleur ou non, on affiche BT*/
						if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)|| (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
							printf(" BT ");
														/*else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t)
															printf(" BT ");
														else
															printf("    ");*/
						/*si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche */
						else if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
							printf("JOUE");
					}
					/* si le joueur 1 a un Porte_Avion */
					else if(grille.grille1[i][j].bateau == Porte_Avion){
						/* si le joueur adverse a un porte avion touche et un torpilleur ou non, on affiche BT*/
						if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
							printf(" BT ");
														/*else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t)
															printf(" BT ");
														else
															printf("    ");*/
						/*si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche */
						else if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
							printf("JOUE");
					}
					/* si l'adversaire n'a pas de bateau touche,n'a pas de torpilleur et que le joueur qui joue a un torpilleur, on affiche le torpilleur*/
					else if ((grille.grille1[i][j].toucher == Non && grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present)||(grille.grille1[i][j].toucher == Non && grille.grille1[i][j].bateau == Sous_Marin && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Non && grille.grille1[i][j].bateau == Destroyer && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Non && grille.grille1[i][j].bateau == Porte_Avion && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present))
						printf("JOUE");
					/* si l'adversaire n'a pas de bateau touche, a un torpilleur et que le joueur qui joue a un torpilleur, on affiche le torpilleur */
					else if ((grille.grille1[i][j].toucher == Non && grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present)||(grille.grille1[i][j].toucher == Non && grille.grille1[i][j].bateau == Sous_Marin && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Non && grille.grille1[i][j].bateau == Destroyer && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Non && grille.grille1[i][j].bateau == Porte_Avion && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
						printf("JOUE");	
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
    else if(num_grille==1){
    	printf("***********************************  GRILLE SELECTION TORPILLEUR  *********************************** \n\n");
	 	printf("           A    B    C    D    E    F    G    H    I    J \n");
		for(i=0;i < N ; i++){
			printf("\t");
			for(k=0;k < N ; k++)
				printf("-----");
			printf("-\n\t%i |",nL);
				nL++;
			for(j=0; j < M ; j++){
				Grille_lire_case(i, j,num_grille,*(grille.grille1));
				/* si il y a un obstacle, on affcihe XX*/
				if(grille.grille2[i][j].obstacle == Obstacle )
					printf(" XX ");
				/*si il n'y pas d'obstacle */
				else if (grille.grille2[i][j].obstacle == Aucun_o){
					/* si il n'y a rien on affiche une espace*/
					if(grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t)
						printf("    ");
					/* si le joueur adverse a un torpilleur on affiche une espace*/
					else if((grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t)||(grille.grille2[i][j].bateau == Sous_Marin && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t) || (grille.grille2[i][j].bateau == Destroyer && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t) || (grille.grille2[i][j].bateau == Porte_Avion && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t))
						printf("    ");
					/* si le joueur 1 a un sous marin*/
					else if(grille.grille2[i][j].bateau == Sous_Marin){
						/* si le joueur adverse a un sous marin touche et un torpilleur ou non on affiche BT*/
						if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t)||(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t))
							printf(" BT ");
														/*else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t)
															printf(" BT ");
														else
															printf("    ");*/

						/*si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche*/  
						else if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
							printf("JOUE");
					}
					/* si le joueur 1 a un Destroyer */
					else if(grille.grille2[i][j].bateau == Destroyer ){
						/* si le joueur adverse a un Destroyer touche et un torpilleur ou non, on affiche BT*/
						if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t)|| (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t))
							printf(" BT ");
														/*else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t)
															printf(" BT ");
														else
															printf("    ");*/
						/*si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche */
						else if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
							printf("JOUE");
					}
					/* si le joueur 1 a un Porte_Avion */
					else if(grille.grille2[i][j].bateau == Porte_Avion){
						/* si le joueur adverse a un porte avion touche et un torpilleur ou non, on affiche BT*/
						if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t))
							printf(" BT ");
														/*else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t)
															printf(" BT ");
														else
															printf("    ");*/
						/*si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche */
						else if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
							printf("JOUE");
					}
					/* si l'adversaire n'a pas de bateau touche,n'a pas de torpilleur et que le joueur qui joue a un torpilleur, on affiche le torpilleur*/
					else if ((grille.grille2[i][j].toucher == Non && grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present)||(grille.grille2[i][j].toucher == Non && grille.grille2[i][j].bateau == Sous_Marin && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Non && grille.grille2[i][j].bateau == Destroyer && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Non && grille.grille2[i][j].bateau == Porte_Avion && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present))
						printf("JOUE");
					/* si l'adversaire n'a pas de bateau touche, a un torpilleur et que le joueur qui joue a un torpilleur, on affiche le torpilleur */
					else if ((grille.grille2[i][j].toucher == Non && grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present)||(grille.grille2[i][j].toucher == Non && grille.grille2[i][j].bateau == Sous_Marin && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Non && grille.grille2[i][j].bateau == Destroyer && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Non && grille.grille2[i][j].bateau == Porte_Avion && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
						printf("JOUE");	
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
    	printf("BT = bateau touché");
    	printf("\n");
    	printf("JOUE = torpilleur selectionne");
    	printf("\n");
    	printf("X = obstacle");
    	printf("\n\n");
}