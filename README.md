# BatailleNavale

# Programme général

enum (Aucun, Torpilleur, Sous-Marin, Destroyer, Porte-Avion) t_bateau

enum (Aucun, Obstacle) t_obstacle

enum (Non, Oui) t_toucher

structure case{t_bateau, t_obstacle, t_toucher)

case grille1
case grille2

struture {grille1, grille2} t_grille
t_grille grille


struture {eBatNb, eTirNb, eTouchNb} t_donnee

t_donnee donnee1
t_donnee donnee2

struture {donnee1, donnee2} t_stats
t_stats info

int bQuitter


  Rep jusqu'à quitter(bQuitter)
    bQuitter = 0;
    MenuAfficher
      PartieLancer
      
        PartieInitialiser(##eJoueur, Grille, info)
            eJoueur = 1 ou 2
            InfoInitialiser(##info)
            GrilleGenerer(eJoueur ## Grille)
              ObstaclePlacer(##Grille)
              GrilleAfficher(Grille)
            BateauPlacer(eJoueur# Grille#)
              JoueurPlacer(eJoueur # Grille#)
              GrilleAfficher(eJoueur, Grille)
              JoueurPlacer(eJoueur # Grille #)
              GrilleAfficher(eJoueur, Grille)
      
      
        Rep jusqu'à bPartieFini(Grille, bQuitter)
            JoueurJouer(eJoueur # Grille, info#)
                PlateauAfficher(eJoueur,Grille,info)
                  GrilleAfficher(eJoueur,Grille)
                  GrilleMasque(eJoueur, Grille)
                  HUDAfficher(eJoueur,info) 
                TorpilleurDeplacer(eJoueur #Grille #)
                PlateauAfficher(eJoueur, Grille, infos)
                TorpilleurAttaquer(eJoueur # Grille, info #)
                PlateauAfficher(eJoueur, Grille, info)
            ChangerJoueur(#eJoueur, bQuitter#)
        fin rep
      
        ScoreAfficher(info)
  fin rep


## GrilleGenerer

## GrilleAfficher

## 
