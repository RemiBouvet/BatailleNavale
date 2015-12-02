//
//  Placement_bateau.c
//
//
//  Created by Zerbane Mehdi on 27/11/2015.
//
//
#include "Outil.h"
#include "Grille.h"
#include "Struct.h"
#define nb_bateau 4
#define N_Torpilleur 2

t_case grille[N][M];

int bStringtonum(char *v,int *res){
    int bNum=1;
    int i;
    *res=0;
    for(i=0;i<strlen(v);i++)
        bNum=bNum && isdigit(v[i]);
    if(bNum==1){
        *res=atoi(v);
    }
    return bNum;
}

int verif_presence(t_bateau bateau,int i,int j,int choix_sens,int num_grille){
    int compteur=0,resultat_b=0,resultat_o=0;
    if(choix_sens==1){
	    while(compteur<bateau){
		Grille_lire_bateau(i,j+compteur,num_grille,&resultat_b);
		Grille_lire_obstacle(i,j+compteur,num_grille,&resultat_o);
		if(resultat_b!=0 || resultat_o!=0)return 0;
	        compteur++;
	   }
   }
    else if(choix_sens==2){
	while(compteur<bateau){
		Grille_lire_bateau(compteur+i,j,num_grille,&resultat_b);
		Grille_lire_obstacle(compteur+i,j,num_grille,&resultat_o);
		if(resultat_b!=0 || resultat_o!=0)return 0;
	        compteur++;
	   }

   }
	return 1;
}

void Placer_grillebateau(t_bateau bateau, int i,int j,int num_grille,int choix_sens){
	int compteur=0;
	if(choix_sens==1){
		while(compteur<bateau){
			Grille_ecrire_bateau(i,j+compteur,num_grille,bateau);
			compteur++;
		}
	}else if(choix_sens==2){
		while(compteur<bateau){
			Grille_ecrire_bateau(i+compteur,j,num_grille,bateau);
			compteur++;
		}
	}

}




void Placer_bateau(int num_grille,int nb_torpilleur){
    int compteur=0,choix_sens,i,j,ok=0,nb=0;
    char sI[20];
    char sJ[20];
    for(compteur=0;compteur!=1;compteur++){
	printf("Vous allez rentrer le Sous_Marin\n");
        do{
            printf("Veuillez rentrer les coordonnées i et j de depart pour placer le bateau : ");
            scanf("%s",sI);
            scanf("%s",sJ);
             if(bStringtonum(sI,&i) && bStringtonum(sJ,&j)){
                 if(bCroit(0,i,N) && bCroit(0,j,M)){
                    printf("Dans quelle sens souhaitez vous le placé ? 1 Horizontal , 2 Vertical\t : ");
                    scanf("%i",&choix_sens);
                    if(bCroit(1,choix_sens,2)){         
			if(verif_presence(Sous_Marin,i,j,choix_sens,num_grille)){
				Placer_grillebateau(Sous_Marin, i,j,num_grille,choix_sens);
				ok=1;
			}
                    }
            	}
             }
        }while(!ok);
        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                printf("%i  ",grille[i][j].bateau);
            }
            printf("\n");
        }
 	 ok=0;
        do{
            printf("Vous allez placer le Destroyer\n");
            printf("Veuillez rentrer les coordonnées i et j pour placer le bateau : ");
            scanf("%s",sI);
            scanf("%s",sJ);
            if(bStringtonum(sI,&i) && bStringtonum(sJ,&j)){
                if(bCroit(0,i,N) && bCroit(0,j,M)){
                    printf("Dans quelle sens souhaitez vous le placé ? 1 Horizontal , 2 Vertical\t : ");
                    scanf("%i",&choix_sens);
                    if(bCroit(1,choix_sens,2)){
				if(verif_presence(Destroyer,i,j,choix_sens,num_grille)){
		                        Placer_grillebateau(Destroyer, i,j,num_grille,choix_sens);
					ok=1;
				}
		    }
		}
	    }                    
        }while(!ok);
        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                printf("%i  ",grille[i][j].bateau);
            }
            printf("\n");
        }
        ok=0;
        do{
            printf("Vous allez placer le Porte_Avion\n");
            printf("Veuillez rentrer les coordonnées i et j pour placer le bateau : ");
            scanf("%s",sI);
            scanf("%s",sJ);
            if(bStringtonum(sI,&i) && bStringtonum(sJ,&j)){
                if(bCroit(0,i,N) && bCroit(0,j,M)){
                    printf("Dans quelle sens souhaitez vous le placé ? 1 Horizontal , 2 Vertical\t : ");
                    scanf("%i",&choix_sens);
                    if(bCroit(1,choix_sens,2)){
				if(verif_presence(Porte_Avion,i,j,choix_sens,num_grille)){
		                        Placer_grillebateau(Porte_Avion, i,j,num_grille,choix_sens);
					ok=1;
				}
                     }
                }
            }
        }while(!ok);
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
		    printf("%i  ",grille[i][j].bateau);
		}
        printf("\n");
    	}
	ok=0;
	printf("Vous allez rentrer le torpilleur\n");
	while(nb!=nb_torpilleur){
		do{
		    printf("Veuillez rentrer les coordonnées i et j de depart pour placer le bateau : ");
		    scanf("%s",sI);
		    scanf("%s",sJ);
		    if(bStringtonum(sI,&i) && bStringtonum(sJ,&j)){
		        if(bCroit(0,i,N) && bCroit(0,j,M)){
		            printf("%i \n",verif_presence(Torpilleur,i,j,choix_sens,num_grille));
				if(verif_presence(Torpilleur,i,j,choix_sens,num_grille)){
					Grille_ecrire_bateau(i,j,num_grille,Torpilleur);
					ok=1;
				}
		        }
		    }
		}while(!ok);
		nb++;	
	}
    }
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf("%i  ",grille[i][j].bateau);
        }
        printf("\n");
    }
    
}

int main(void){
	Grille_init();
	Placer_bateau(1,1);
	return 0;
}
