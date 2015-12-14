#include "../../grille/Grille.h"
#include "../../grille/Struct.h"
#include "../../grille/Outil.h"
#include "../include/afficher.h"

t_plateau grille;

void Grille_perso_afficher(int num_grille){
/* Fonction permettant d'afficher la grille du joueur qui contient ses bateaux, les obstacles, les cibles touchées et les torpilleurs*/
	 int i,j, k;
	 int nL=0;
	 if(num_grille==1){
		 printw("***********************************  GRILLE JOUEUR 1  *********************************** \n \n");
		 printw("            A    B    C    D    E    F    G    H    I    J \n");
			for(i=0;i < N ; i++){
				printw("\t");
				for(k=0;k < N ; k++){
					printw("-----");
				}
				printw("-\n\t%i |",nL);
				nL++;
				for(j=0; j < M ; j++){
	                Grille_lire_case(i, j,num_grille,*(grille.grille1));
					
					if(grille.grille1[i][j].obstacle == Obstacle){
						printw(" XX ");
					}
					else if (grille.grille1[i][j].obstacle == Aucun_o){
						if((grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Present)||(grille.grille1[i][j].bateau == Sous_Marin && grille.grille1[i][j].torpilleur==Present) || (grille.grille1[i][j].bateau == Destroyer && grille.grille1[i][j].torpilleur==Present) || (grille.grille1[i][j].bateau == Porte_Avion && grille.grille1[i][j].torpilleur==Present) ){
							printw(" TP ");
						}
						/*else if((grille.grille1[i][j].bateau == Sous_Marin && grille.grille1[i][j].torpilleur==Present) || (grille.grille1[i][j].bateau == Destroyer && grille.grille1[i][j].torpilleur==Present) || (grille.grille1[i][j].bateau == Porte_Avion && grille.grille1[i][j].torpilleur==Present))
							printw("TPB");
						if(grille.grille1[i][j].bateau == Aucun_b){
							printw("    ");
						}*/
						else if(grille.grille1[i][j].bateau == Sous_Marin){
							if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t)
								printw("SM_T");
							else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present)
								printw("TSMT");
							else{
								printw(" SM ");
							}
						}
						else if(grille.grille1[i][j].bateau == Destroyer){
							if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t)
								printw("DE_T");
							else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present)
								printw("TDET");
							else{
								printw(" DE ");
							}
						}
						else if(grille.grille1[i][j].bateau == Porte_Avion ){
							if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t)
								printw("PA_T");
							else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present)
								printw("TPAT");
							else{
								printw(" PA ");
							}
						}
						else {printw("    ");}
					}
					printw("|");
				}
				printw("\n");
			}
			printw("\t");
			for(k=0;k < N ; k++) printw("-----");
	    	printw("\n\n");
		} else {
			printw("***********************************  GRILLE JOUEUR 2  *********************************** \n \n");
		 	printw("           A    B    C    D    E    F    G    H    I    J \n");
			for(i=0;i < N ; i++){
				printw("\t");
				for(k=0;k < N ; k++)
					printw("-----");
				printw("-\n\t%i |",nL);
				nL++;
				for(j=0; j < M ; j++){
	                Grille_lire_case(i, j,num_grille,*(grille.grille2));
					
					if(grille.grille2[i][j].obstacle == Obstacle )
						printw(" X ");
					else if (grille.grille2[i][j].obstacle == Aucun_o){
						if((grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Present)||(grille.grille2[i][j].bateau == Sous_Marin && grille.grille2[i][j].torpilleur==Present) || (grille.grille2[i][j].bateau == Destroyer && grille.grille2[i][j].torpilleur==Present) || (grille.grille2[i][j].bateau == Porte_Avion && grille.grille2[i][j].torpilleur==Present) ){
							printw(" TP ");
						}
						/*if(grille.grille2[i][j].bateau == Aucun_b){
							printw("    ");
						}*/
						else if(grille.grille2[i][j].bateau == Sous_Marin){
							if(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t)
								printw("SM_T");
							else if(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present)
								printw("TSMT");
							else{
								printw(" SM ");
							}
						}
						else if(grille.grille2[i][j].bateau == Destroyer){
							if(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t)
								printw("DE_T");
							else if(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present)
								printw("TDET");
							else{
								printw(" DE ");
							}
						}
						else if(grille.grille2[i][j].bateau == Porte_Avion){
							if(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t)
								printw("PA_T");
							else if(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present)
								printw("TPAT");
							else{
								printw(" PA ");
							}
						}else {printw("    ");}	
					}
					printw("|");
				}
				printw("\n");
			}
			printw("\t");
			for(k=0;k < N ; k++) printw("-----");
	    	printw("\n\n");
		}
    	printw("CORRESPONDANCE DES SYMBOLES :\n");
    	printw("TP = torpilleur seul ou sur un bateau");
    	printw("\n");
    	printw("SM = sous-matin");
    	printw("\n");
    	printw("DE = destroyer");
    	printw("\n");
    	printw("PA = porte-avion");
    	printw("\n");
    	printw("'nom'_T ='bateau' touché");
    	printw("\n");
    	printw("T'nom'T =torpilleur sur 'bateau' touché");
    	printw("\n");
    	printw("XX = obstacle");
    	printw("\n\n");
    	refresh();
}

void Grille_masque_afficher(int num_grille){
/* Fonction permettant d'afficher la grille masquée de l'adversaire qui contient les obstacles ainsi que les cibles touchées */ 
	int i,j, k;
	int nL=0;
	if(num_grille==2){
	 	printw("***********************************  GRILLE ADVERSE CACHEE  *********************************** \n\n");
	 	printw("           A    B    C    D    E    F    G    H    I    J \n");
		for(i=0;i < N ; i++){
			printw("\t");
			for(k=0;k < N ; k++)
				printw("-----");
			printw("-\n\t%i |",nL);
				nL++;
			for(j=0; j < M ; j++){
				Grille_lire_case(i, j,num_grille,*(grille.grille1));
				if(grille.grille1[i][j].obstacle == Obstacle )
					printw(" X ");
				else if (grille.grille1[i][j].obstacle == Aucun_o){
					if(grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t)
						printw("    ");
					else if((grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)||(grille.grille1[i][j].bateau == Sous_Marin && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t) || (grille.grille1[i][j].bateau == Destroyer && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t) || (grille.grille1[i][j].bateau == Porte_Avion && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t))
						printw("    ");
					else if(grille.grille1[i][j].bateau == Sous_Marin){
						if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)||(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
							printw(" BT ");
						/*else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t)
							printw(" BT ");
						else
							printw("    ");*/
					}
					else if(grille.grille1[i][j].bateau == Destroyer ){
						if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)|| (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
							printw(" BT ");
						/*else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t)
							printw(" BT ");
						else
							printw("    ");*/
					}
					else if(grille.grille1[i][j].bateau == Porte_Avion){
						if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
							printw(" BT ");
						/*else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t)
							printw(" BT ");
						else
							printw("    ");*/
					}
					else printw("TP");	
				}
				printw("|");
			}
			printw("\n");
		}
		printw("\t");
		for(k=0;k < N ; k++)
			printw("-----");
    	printw("\n\n");
    }else if(num_grille==1){
    	printw("***********************************  GRILLE ADVERSE CACHEE  *********************************** \n\n");
	 	printw("           A    B    C    D    E    F    G    H    I    J \n");
		for(i=0;i < N ; i++){
			printw("\t");
			for(k=0;k < N ; k++)
				printw("-----");
			printw("-\n\t%i |",nL);
				nL++;
			for(j=0; j < M ; j++){
				Grille_lire_case(i, j,num_grille,*(grille.grille2));
				if(grille.grille2[i][j].obstacle == Obstacle )
					printw(" X ");
				else if (grille.grille2[i][j].obstacle == Aucun_o){
					if(grille.grille2[i][j].bateau == Aucun_b)
						printw("    ");
					else if((grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Present)||(grille.grille2[i][j].bateau == Sous_Marin && grille.grille2[i][j].torpilleur==Present) || (grille.grille2[i][j].bateau == Destroyer && grille.grille2[i][j].torpilleur==Present) || (grille.grille2[i][j].bateau == Porte_Avion && grille.grille2[i][j].torpilleur==Present))
						printw("    ");
					else if(grille.grille2[i][j].bateau == Sous_Marin){
						if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present)||(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t))
							printw(" BT ");
						else
							printw("    ");
					}
					else if(grille.grille2[i][j].bateau == Destroyer){
						if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present)||(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t))
							printw(" BT ");
						else
							printw("    ");
					}
					else if(grille.grille2[i][j].bateau == Porte_Avion){
						if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present)||(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t))
							printw(" BT ");
						else
							printw("    ");
					}	
				}
				printw("|");
			}
			printw("\n");
		}
		printw("\t");
		for(k=0;k < N ; k++)
			printw("-----");
    	printw("\n\n");
    }
    	printw("CORRESPONDANCE DES SYMBOLES :\n");
    	printw("BT = bateau touché");
    	printw("\n");
    	printw("X = obstacle");
    	printw("\n\n");
    	refresh();
}