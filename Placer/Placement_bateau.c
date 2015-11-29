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
#define nb_bateau 1

t_case grille1[N][M];

void Placer_bateau(int num_grille){
    int compteur=0,i,j,choix_sens,valeur=0;
    printf("Vous allez rentrer le torpilleur\n");
    for(compteur=0;compteur!=nb_bateau;compteur++){
        printf("Veuillez rentrer les coordonnées i et j de depart pour placer le bateau");
        scanf("%i%i",&i,&j);
        if(bCroit(0,i,N)){
            if(bCroit(0,j,M)){
                printf("Dans quelle sens souhaitez vous le placé ? 1 Horizontal , 2 Vertical");
                scanf("%i",&choix_sens);
                if(bCroit(1,choix_sens,2)){
                    if(choix_sens==1 || choix_sens==2){
                        while(valeur!=Torpilleur){
                            Grille_ecrire_bateau(i,j,num_grille,Torpilleur);
                            valeur++;
                        }
                    }
                }

            }
        }/*
        printf("Vous allez rentrer le Sous_Marin\n");
        scanf("%i%i",&i,&j);
        if(bCroit(0,i,N)){
            if(bCroit(0,j,M)){
                printf("Dans quelle sens souhaitez vous le placé ? 1 Horizontal , 2 Vertical");
                scanf("%i",&choix_sens);
                if(bCroit(1,choix_sens,2)){
                    if(choix_sens==1){
                        valeur=0;
                        while(valeur!=Sous_Marin){
                            Grille_ecrire_bateau(i,j,num_grille,Sous_Marin);
                            valeur++;
                            Grille_ecrire_bateau(i+1,j,num_grille,Sous_Marin);
                            valeur++;
                            Grille_ecrire_bateau(i+2,j,num_grille,Sous_Marin);
                            valeur++;
                        }
                    }
                }
                compteur++;
            }
        }
        printf("Vous allez placer le Destroyer\n");
        printf("Veuillez rentrer les coordonnées i et j pour placer le bateau");
        scanf("%i%i",&i,&j);
        if(bCroit(0,i,N)){
            if(bCroit(0,j,M)){
                printf("Dans quelle sens souhaitez vous le placé ? 1 Horizontal , 2 Vertical");
                scanf("%i",&choix_sens);
                if(bCroit(1,choix_sens,2)){
                    if(choix_sens==1){
                        valeur=0;
                        while(valeur!=Destroyer){
                            Grille_ecrire_bateau(i,j,num_grille,Destroyer);
                            valeur++;
                            Grille_ecrire_bateau(i+1,j,num_grille,Destroyer);
                            valeur++;
                            Grille_ecrire_bateau(i+2,j,num_grille,Destroyer);
                            valeur++;
                            Grille_ecrire_bateau(i+3,j,num_grille,Destroyer);
                            valeur++;
                        }
                    }
                }
                compteur++;
            }
        }
        printf("Vous allez placer le Porte_Avions\n");
        printf("Veuillez rentrer les coordonnées i et j pour placer le bateau");
        scanf("%i%i",&i,&j);
        if(bCroit(0,i,N)){
            if(bCroit(0,j,M)){
                printf("Dans quelle sens souhaitez vous le placé ? 1 Horizontal , 2 Vertical");
                scanf("%i",&choix_sens);
                if(bCroit(1,choix_sens,2)){
                    if(choix_sens==1){
                        valeur=0;
                        while(valeur!=Porte_Avion){
                            printf("%i",num_grille);
                            Grille_ecrire_bateau(i,j,num_grille,Porte_Avion);
                            valeur++;
                            Grille_ecrire_bateau(i+1,j,num_grille,Porte_Avion);
                            valeur++;
                            Grille_ecrire_bateau(i+2,j,num_grille,Porte_Avion);
                            valeur++;
                            Grille_ecrire_bateau(i+3,j,num_grille,Porte_Avion);
                            valeur++;
                            Grille_ecrire_bateau(i+4,j,num_grille,Porte_Avion);
                            valeur++;
                        }
                    }
                    if(choix_sens==2){
                        valeur=0;
                        while(valeur!=Porte_Avion){
                            printf("%i",num_grille);
                            Grille_ecrire_bateau(i,j,num_grille,Porte_Avion);
                            valeur++;
                            Grille_ecrire_bateau(i,j+1,num_grille,Porte_Avion);
                            valeur++;
                            Grille_ecrire_bateau(i,j+2,num_grille,Porte_Avion);
                            valeur++;
                            Grille_ecrire_bateau(i,j+3,num_grille,Porte_Avion);
                            valeur++;
                            Grille_ecrire_bateau(i,j+4,num_grille,Porte_Avion);
                            valeur++;
                        }
                    }
                }
                compteur++;
            }
        }
    }*/

    }
    Grille_lire_matrice(num_grille); //erreur presente
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf("%i  ",grille1[i][j].bateau);
        }
        printf("\n");
    }

}

int main(void){
    Placer_bateau(1);
    return 0;

}
