#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "entree_sortie.h"
#include "Grille.h"
#include "Graphe.h"
#include "ListeDC.h"
#include "Solution.h"
#include "API_AffGrille.h"
#include "circuit.h"


int main(int argc,char**argv){

  Graphe H;
  Grille G;
  AffGrille AG;
  Solution S;
  int graine;
  int i,j;
  int num_algo;
  int nb1, nb2, nb3, nb4, nb5;
  LDC ldc;
  LDC liste, liste1;
  Lcircuit Lc;

  LDCInitialise(&liste);

  /* les différents arguments */  
  if(argc!=5){
    printf("usage: %s <nb_lignes> <nb_colonnes> <nb_couleur> <graine> \n",argv[0]);
    return 1;
  }

  G.m=atoi(argv[1]);
  G.n=atoi(argv[2]);
  
  if (G.m>G.n){
    printf("Il doit y avoir plus de colonnes que de lignes.\n");
    exit(1);
  }
  
  G.nbcoul=atoi(argv[3]);
  if (G.nbcoul!=G.m*G.n){
    printf("Il doit y avoir autand de couleurs différentes que de cases.\n");
    exit(1);
  }
  
  graine=atoi(argv[4]);

  /* Generation de l'instance */
  Grille_allocation(&G);
  Gene_Grille(&G,graine);
  Solution_init(&S);
 
  Graphe_init(&H, G.m, G.n);
  Graphe_creation(&G, &H);
  Graphe_affiche(&H);

  /* Initialisation et affichage des tous les circuits */
  printf("\n---- fonction Liste des circuits : ---\n");     
  Graphe_Rec_Circuit(&H, &Lc);
  afficher_Lcircuit(&Lc);

  printf("\n++++++Valeur test : [%d, %d]\n", Lc.premier->L->premier->i, Lc.premier->L->premier->j);

printf("\n++++++Nbre de circuit : %d\n", Lc.nb_circuit);

  
    CalculJminJmaxxx(&Lc);

  afficher_Lcircuit(&Lc);
  
  
  return 0;
}

   
