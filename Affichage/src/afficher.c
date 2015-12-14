#include "../../grille/Grille.h"
#include "../../grille/Struct.h"
#include "../../grille/Outil.h"
#include "../include/afficher.h"
#include "../../jouer/JouerStruct.h"

t_plateau grille;

void Grille_perso_afficher(int num_grille){
/* Fonction permettant d'afficher la grille du joueur qui contient ses bateaux, les obstacles, les cibles touchées et les torpilleurs*/
	 int i,j, k;
	 int nL=0; // numero de ligne
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
					// en presence d'obstacle, on affiche XX
					if(grille.grille1[i][j].obstacle == Obstacle){
						printw(" XX ");
					}
					else if (grille.grille1[i][j].obstacle == Aucun_o){
						// en presence du torpilleur du joueur, on affiche TP
						if((grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Present)||(grille.grille1[i][j].bateau == Sous_Marin && grille.grille1[i][j].torpilleur==Present) || (grille.grille1[i][j].bateau == Destroyer && grille.grille1[i][j].torpilleur==Present) || (grille.grille1[i][j].bateau == Porte_Avion && grille.grille1[i][j].torpilleur==Present) ){
							printw(" TP ");
						}
						/*else if((grille.grille1[i][j].bateau == Sous_Marin && grille.grille1[i][j].torpilleur==Present) || (grille.grille1[i][j].bateau == Destroyer && grille.grille1[i][j].torpilleur==Present) || (grille.grille1[i][j].bateau == Porte_Avion && grille.grille1[i][j].torpilleur==Present))
							printw("TPB");
						if(grille.grille1[i][j].bateau == Aucun_b){
							printw("    ");
						}*/
						// si on rencontre un sous-marin :
						else if(grille.grille1[i][j].bateau == Sous_Marin){
							// s'il est touche et qu'il n'y a pas de torpilleur, on affiche SM_T
							if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t)
								printw("SM_T");
							// s'il est touche et qu'il y a un torpilleur, on affiche TSMT
							else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present)
								printw("TSMT");
							// sinon on affiche seulement le sous-marin
							else{
								printw(" SM ");
							}
						}
						// si on rencontre un destroyer :
						else if(grille.grille1[i][j].bateau == Destroyer){
							// s'il est touche et qu'il n'y a pas de torpilleur, on affiche DE_T
							if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t)
								printw("DE_T");
							// s'il est touche et qu'il y a un torpilleur, on affiche TDET
							else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present)
								printw("TDET");
							// sinon on affiche seulement le destroyer
							else{
								printw(" DE ");
							}
						}
						// si on rencontre un porte-avion :
						else if(grille.grille1[i][j].bateau == Porte_Avion ){
							// s'il est touche et qu'il n'y a pas de torpilleur, on affiche PA_T
							if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t)
								printw("PA_T");
							// s'il est touche et qu'il y a un torpilleur, on affiche TPAT
							else if(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present)
								printw("TPAT");
							// sinon on affiche seulement le porte-avion
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
						printw(" XX ");
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
	 	printw("            A    B    C    D    E    F    G    H    I    J \n");
		for(i=0;i < N ; i++){
			printw("\t");
			for(k=0;k < N ; k++)
				printw("-----");
			printw("-\n\t%i |",nL);
				nL++;
			for(j=0; j < M ; j++){
				Grille_lire_case(i, j,num_grille,*(grille.grille1));
				// si il y a un obstacle, on affiche XX
				if(grille.grille1[i][j].obstacle == Obstacle )
					printw(" XX ");
				// si il n'y pas d'obstacle :
				else if (grille.grille1[i][j].obstacle == Aucun_o){
					if((grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t)||(grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t))
						printw("    ");
					// si le joueur adverse n'a pas de bateau , un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur de l'utilisateur
					else if((grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present)||(grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present))
						printw(" TP ");
					// si le joueur 1 a un sous marin :
					else if(grille.grille1[i][j].bateau == Sous_Marin){
						// si le joueur adverse a un sous marin touche , un torpilleur ou non et que l'utilisateur n'a pas de tropilleur, on affiche BT
						if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)||(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
							printw(" BT ");
						//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
						else if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
							printw("T_BT");
						//si le joueur adverse n'a pas de bateau touche et un torpilleur ou non et que le joueur qui joue n'a pas de torpilleur, on affiche rien
						if((grille.grille1[i][j].toucher == Non && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)||(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
							printw("    ");
						//si le joueur adverse n'a pas de bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur de l'utilisateur
						else if((grille.grille1[i][j].toucher == Non && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
							printw(" TP ");
						else 
							printw("    ");
					}
					// si le joueur 1 a un Destroyer :
					else if(grille.grille1[i][j].bateau == Destroyer ){
						// si le joueur adverse a un Destroyer touche et un torpilleur ou non, on affiche BT
						if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)||(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
							printw(" BT ");
						//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
						else if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
							printw("T_BT");
						//si le joueur adverse n'a pas de bateau touche et un torpilleur ou non et que le joueur qui joue n'a pas de torpilleur, on affiche rien
						else if((grille.grille1[i][j].toucher == Non && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)||(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
							printw("    ");
						//si le joueur adverse n'a pas de bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur de l'utilisateur
						else if((grille.grille1[i][j].toucher == Non && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
							printw(" TP ");
						else 
							printw("    ");
					}
					
					// si le joueur 1 a un Porte_Avion :
					else if(grille.grille1[i][j].bateau == Porte_Avion){
						// si le joueur adverse a un porte avion touche et un torpilleur ou non, on affiche BT
						if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)||(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
							printw(" BT ");
						//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
						else if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
							printw("T_BT");
						//si le joueur adverse n'a pas de bateau touche et un torpilleur ou non et que le joueur qui joue n'a pas de torpilleur, on affiche rien
						else if((grille.grille1[i][j].toucher == Non && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)||(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
							printw("    ");
						//si le joueur adverse n'a pas de bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur de l'utilisateur
						else if((grille.grille1[i][j].toucher == Non && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
							printw(" TP ");
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
    else if(num_grille==1){
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
				if(grille.grille2[i][j].obstacle == Obstacle )
					printw(" XX ");
				else if (grille.grille2[i][j].obstacle == Aucun_o){
					if((grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t)||(grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t))
						printw("    ");

					else if((grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present)||(grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present))
						printw(" TP ");

					else if(grille.grille2[i][j].bateau == Sous_Marin){
						if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t)||(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t))
							printw(" BT ");
						else if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
							printw("T_BT");
						else if((grille.grille2[i][j].toucher == Non && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t)||(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t))
							printw("    ");
						else if((grille.grille2[i][j].toucher == Non && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
							printw(" TP ");
						else 
							printw("    ");
					}
					
					else if(grille.grille2[i][j].bateau == Destroyer ){
						
						if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t)||(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t))
							printw(" BT ");
						else if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
							printw("T_BT");
						else if((grille.grille2[i][j].toucher == Non && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t)||(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t))
							printw("    ");
						else if((grille.grille2[i][j].toucher == Non && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
							printw(" TP ");
						else 
							printw("    ");
					}
					
					else if(grille.grille2[i][j].bateau == Porte_Avion){
						if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t)||(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t))
							printw(" BT ");
						else if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
							printw("T_BT");
						else if((grille.grille2[i][j].toucher == Non && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t)||(grille.grille2[i][j].toucher == Non && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t))
							printw("    ");
						else if((grille.grille2[i][j].toucher == Non && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Non && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
							printw(" TP ");
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
    	printw("T_BT = torpilleur sur bateau touché");
    	printw("\n");
    	printw("X = obstacle");
    	printw("\n\n");
    	refresh();
}

void Portee_torpilleur_afficher(t_portee gPortee[N][M],int num_grille,int x, int y){
/* Fonction permettant d'afficher la grille masquée de l'adversaire qui contient les obstacles ainsi que les cibles touchées */ 
	int i,j, k;
	int nL=0;
	if(num_grille==2){
	 	printw("*********************************** GRILLE ATTAQUE  JOUEUR 2 *********************************** \n\n");
	 	printw("            A    B    C    D    E    F    G    H    I    J \n");
		for(i=0;i < N ; i++){
			printw("\t");
			for(k=0;k < N ; k++)
				printw("-----");
			printw("-\n\t%i |",nL);
				nL++;
			for(j=0; j < M ; j++){
				Grille_lire_case(i, j,num_grille,*(grille.grille1));
				// si il y a un obstacle, on affiche XX
				if(grille.grille1[i][j].obstacle == Obstacle )
					printw(" XX ");
				// si il n'y pas d'obstacle 
				else if (grille.grille1[i][j].obstacle == Aucun_o){
					if(i == x && j == y)
						printw("TIRE");
					else if((gPortee[i][j]==1))
						printw(" PJ ");
					else{
						if((grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t)||(grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t))
							printw("    ");
						else if((grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present)||(grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present))
							printw(" TP ");
						// si le joueur 1 a un sous marin
						else if(grille.grille1[i][j].bateau == Sous_Marin){
							// si le joueur adverse a un sous marin touche et un torpilleur ou non on affiche BT
							if(grille.grille1[i][j].toucher == Oui )
								printw(" BT ");
							//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
							else if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
								printw("T_BT");
							if((grille.grille1[i][j].toucher == Non && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)||(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
								printw("    ");
							//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
							else if((grille.grille1[i][j].toucher == Non && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
								printw(" TP ");
							else 
								printw("    ");
						}
						// si le joueur 1 a un Destroyer 
						else if(grille.grille1[i][j].bateau == Destroyer ){
							// si le joueur adverse a un Destroyer touche et un torpilleur ou non, on affiche BT
							if(grille.grille1[i][j].toucher == Oui)
								printw(" BT ");
							//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
							else if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
								printw("T_BT");
							else if((grille.grille1[i][j].toucher == Non && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)||(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
								printw("    ");
							//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
							else if((grille.grille1[i][j].toucher == Non && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
								printw(" TP ");
							else 
								printw("    ");
						}
						
						// si le joueur 1 a un Porte_Avion 
						else if(grille.grille1[i][j].bateau == Porte_Avion){
							// si le joueur adverse a un porte avion touche et un torpilleur ou non, on affiche BT
							if(grille.grille1[i][j].toucher == Oui)
								printw(" BT ");
							//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
							else if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
								printw("T_BT");
							else if((grille.grille1[i][j].toucher == Non && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)||(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
								printw("    ");
							//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
							else if((grille.grille1[i][j].toucher == Non && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
								printw(" TP ");
							else 
								printw("    ");
						}
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
    else if(num_grille==1){
    	printw("***********************************  GRILLE ATTAQUE JOUEUR 1  *********************************** \n\n");
	 	printw("           A    B    C    D    E    F    G    H    I    J \n");
		for(i=0;i < N ; i++){
			printw("\t");
			for(k=0;k < N ; k++)
				printw("-----");
			printw("-\n\t%i |",nL);
				nL++;
			for(j=0; j < M ; j++){
				Grille_lire_case(i, j,num_grille,*(grille.grille1));
				// si il y a un obstacle, on affiche XX
				if(grille.grille2[i][j].obstacle == Obstacle )
					printw(" XX ");
				// si il n'y pas d'obstacle 
				else if (grille.grille1[i][j].obstacle == Aucun_o){
					if(i == x && j == y)
						printw("TIRE");
					else if((gPortee[i][j]==1))
						printw(" PJ ");
					else{
						if((grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t)||(grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t))
							printw("    ");
						else if((grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present)||(grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present))
							printw(" TP ");
						// si le joueur 1 a un sous marin
						else if(grille.grille2[i][j].bateau == Sous_Marin){
							// si le joueur adverse a un sous marin touche et un torpilleur ou non on affiche BT
							if(grille.grille2[i][j].toucher == Oui )
								printw(" BT ");
							//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
							else if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
								printw("T_BT");
							else if((grille.grille2[i][j].toucher == Non && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t)||(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t))
								printw("    ");
							//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
							else if((grille.grille2[i][j].toucher == Non && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
								printw(" TP ");
							else 
								printw("    ");
						}
						// si le joueur 1 a un Destroyer 
						else if(grille.grille2[i][j].bateau == Destroyer ){
							// si le joueur adverse a un Destroyer touche et un torpilleur ou non, on affiche BT
							if(grille.grille2[i][j].toucher == Oui )
								printw(" BT ");
							//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
							else if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
								printw("T_BT");
							else if((grille.grille2[i][j].toucher == Non && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t)||(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t))
								printw("    ");
							//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
							else if((grille.grille2[i][j].toucher == Non && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
								printw(" TP ");
							else 
								printw("    ");
						}
						
						// si le joueur 1 a un Porte_Avion 
						else if(grille.grille2[i][j].bateau == Porte_Avion){
							// si le joueur adverse a un porte avion touche et un torpilleur ou non, on affiche BT
							if(grille.grille2[i][j].toucher == Oui)
								printw(" BT ");
							//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
							else if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
								printw("T_BT");
							else if((grille.grille2[i][j].toucher == Non && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t)||(grille.grille2[i][j].toucher == Non && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t))
								printw("    ");
							//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
							else if((grille.grille2[i][j].toucher == Non && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Non && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
								printw(" TP ");
							else 
								printw("    ");
						}
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
    	printw("PJ = portee torpilleur");
    	printw("\n");
    	printw("XX = obstacle");
    	printw("\n\n");
    	refresh();
}

void torpilleur_selection_afficher(int x,int y, int num_grille){
/* Fonction qui permet d'afficher la selection du torpilleur */
int i,j, k;
	int nL=0;
	if(num_grille==2){
	 	printw("*********************************** GRILLE ATTAQUE  JOUEUR 2 *********************************** \n\n");
	 	printw("            A    B    C    D    E    F    G    H    I    J \n");
		for(i=0;i < N ; i++){
			printw("\t");
			for(k=0;k < N ; k++)
				printw("-----");
			printw("-\n\t%i |",nL);
				nL++;
			for(j=0; j < M ; j++){
				Grille_lire_case(i, j,num_grille,*(grille.grille1));
				// si il y a un obstacle, on affiche XX
				if(grille.grille1[i][j].obstacle == Obstacle )
					printw(" XX ");
				// si il n'y pas d'obstacle 
				else if (grille.grille1[i][j].obstacle == Aucun_o){
					if(i==x && j==y)
						printw("PLAY");
					else{
						if((grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t)||(grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t))
							printw("    ");
						else if((grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present)||(grille.grille1[i][j].bateau == Aucun_b && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present))
							printw(" TP ");
						// si le joueur 1 a un sous marin
						else if(grille.grille1[i][j].bateau == Sous_Marin){
							// si le joueur adverse a un sous marin touche et un torpilleur ou non on affiche BT
							if(grille.grille1[i][j].toucher == Oui )
								printw(" BT ");
							//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
							else if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
								printw("T_BT");
							if((grille.grille1[i][j].toucher == Non && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)||(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
								printw("    ");
							//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
							else if((grille.grille1[i][j].toucher == Non && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
								printw(" TP ");
							else 
								printw("    ");
						}
						// si le joueur 1 a un Destroyer 
						else if(grille.grille1[i][j].bateau == Destroyer ){
							// si le joueur adverse a un Destroyer touche et un torpilleur ou non, on affiche BT
							if(grille.grille1[i][j].toucher == Oui)
								printw(" BT ");
							//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
							else if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
								printw("T_BT");
							else if((grille.grille1[i][j].toucher == Non && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)||(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
								printw("    ");
							//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
							else if((grille.grille1[i][j].toucher == Non && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
								printw(" TP ");
							else 
								printw("    ");
						}
						
						// si le joueur 1 a un Porte_Avion 
						else if(grille.grille1[i][j].bateau == Porte_Avion){
							// si le joueur adverse a un porte avion touche et un torpilleur ou non, on affiche BT
							if(grille.grille1[i][j].toucher == Oui)
								printw(" BT ");
							//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
							else if((grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
								printw("T_BT");
							else if((grille.grille1[i][j].toucher == Non && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Aucun_t)||(grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Aucun_t))
								printw("    ");
							//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
							else if((grille.grille1[i][j].toucher == Non && grille.grille1[i][j].torpilleur==Present && grille.grille2[i][j].torpilleur==Present) || (grille.grille1[i][j].toucher == Oui && grille.grille1[i][j].torpilleur==Aucun_t && grille.grille2[i][j].torpilleur==Present))
								printw(" TP ");
							else 
								printw("    ");
						}
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
    else if(num_grille==1){
    	printw("***********************************  GRILLE ATTAQUE JOUEUR 1  *********************************** \n\n");
	 	printw("           A    B    C    D    E    F    G    H    I    J \n");
		for(i=0;i < N ; i++){
			printw("\t");
			for(k=0;k < N ; k++)
				printw("-----");
			printw("-\n\t%i |",nL);
				nL++;
			for(j=0; j < M ; j++){
				Grille_lire_case(i, j,num_grille,*(grille.grille1));
				// si il y a un obstacle, on affiche XX
				if(grille.grille2[i][j].obstacle == Obstacle )
					printw(" XX ");
				// si il n'y pas d'obstacle 
				else if (grille.grille2[i][j].obstacle == Aucun_o){
					if(i==x && j==y)
						printw("PLAY");
					else{
						if((grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t)||(grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t))
							printw("    ");
						else if((grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present)||(grille.grille2[i][j].bateau == Aucun_b && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present))
							printw(" TP ");
						// si le joueur 1 a un sous marin
						else if(grille.grille2[i][j].bateau == Sous_Marin){
							// si le joueur adverse a un sous marin touche et un torpilleur ou non on affiche BT
							if(grille.grille2[i][j].toucher == Oui )
								printw(" BT ");
							//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
							else if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
								printw("T_BT");
							else if((grille.grille2[i][j].toucher == Non && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t)||(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t))
								printw("    ");
							//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
							else if((grille.grille2[i][j].toucher == Non && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
								printw(" TP ");
							else 
								printw("    ");
						}
						// si le joueur 1 a un Destroyer 
						else if(grille.grille2[i][j].bateau == Destroyer ){
							// si le joueur adverse a un Destroyer touche et un torpilleur ou non, on affiche BT
							if(grille.grille2[i][j].toucher == Oui )
								printw(" BT ");
							//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
							else if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
								printw("T_BT");
							else if((grille.grille2[i][j].toucher == Non && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t)||(grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t))
								printw("    ");
							//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
							else if((grille.grille2[i][j].toucher == Non && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
								printw(" TP ");
							else 
								printw("    ");
						}
						
						// si le joueur 1 a un Porte_Avion 
						else if(grille.grille2[i][j].bateau == Porte_Avion){
							// si le joueur adverse a un porte avion touche et un torpilleur ou non, on affiche BT
							if(grille.grille2[i][j].toucher == Oui)
								printw(" BT ");
							//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
							else if((grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Oui && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
								printw("T_BT");
							else if((grille.grille2[i][j].toucher == Non && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Aucun_t)||(grille.grille2[i][j].toucher == Non && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Aucun_t))
								printw("    ");
							//si le joueur adverse a un bateau touche et un torpilleur ou non et que le joueur qui joue a un torpilleur, on affiche le torpilleur/bateau touche
							else if((grille.grille2[i][j].toucher == Non && grille.grille2[i][j].torpilleur==Present && grille.grille1[i][j].torpilleur==Present) || (grille.grille2[i][j].toucher == Non && grille.grille2[i][j].torpilleur==Aucun_t && grille.grille1[i][j].torpilleur==Present))
								printw(" TP ");
							else 
								printw("    ");
						}
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
    	printw("PLAY = torpilleur selectionne");
    	printw("\n");
    	printw("XX = obstacle");
    	printw("\n\n");
    	refresh();
}