# BatailleNavale

# Programme général


Rep jusqu'à l'arret du prog
  MenuAfficher
    PartieLancer
      GrilleGenerer
        ObstaclePlacer
        GrilleAfficher
      
    
      BateauPlacer
        JoueurPlacer(Joueur 1)
        GrilleAfficher(Grille vu 1)
        JoueurPlacer(Joueur 2)
        GrilleAfficher(Grille vu 2)
    
    
      Rep jusqu'à partie fini(L'un des deux joueurs n'a plus de bateau ou quitter la partie)
          JoueurJouer(N = numéro du joueur en cours)
              PlateauAfficher(Plateau vu N)
                * GrilleAfficher(Grille vu N)
                * HUDAfficher(N)
              TorpilleurDeplacer(N)
              PlateauAfficher(Plateau vu N)
              TorpilleurAttaquer(N)
              PlateauAfficher(Plateau vu N)
          ChangerJoueur
      fin rep
    
      ScoreAfficher
fin rep


## GrilleGenerer

## GrilleAfficher

## 
