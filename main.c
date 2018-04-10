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

  /*
  init_sommet(&H);
  affiche_visit(&H);
 
  printf("\n");

recherche_circuit(&H, &liste, 0, 0);
  LDCafficher(&liste);

  
 init_zero(&H);
  affiche_visit(&H);
printf("\n");
 
  LDCInitialise(&liste);
  init_sommet(&H);
  affiche_visit(&H);
printf("\n");
 
  recherche_circuit(&H, &liste, 0, 1);
  LDCafficher(&liste);
  
  /*
  
  recherche_circuit(&H, &liste, 0, 3);
  LDCafficher(&liste);
printf("Vide : %d\n", LDCVide(&liste));
 
  
   

    printf("Vide : %d\n", LDCVide(&liste2));
    
    recherche_circuit(&H, &liste2, 0, 4);
  LDCafficher(&liste2);
  
  

  initialiser_Lcircuit(&Lc);
  /*
  afficher_Lcircuit(&Lc);

  printf("1/ Verification si liste est vide : %d. \n", Lcircuit_Vide(&Lc));

  Cell_circuit *c1=creer_cellule(&liste);

  ajouter_cellule(&Lc, c1);
  printf("---- c1 ---\n");
   afficher_Lcircuit(&Lc);
  

    recherche_circuit(&H, &liste1, 0, 1);
    printf("---- c2 ---\n");
 LDCafficher(&liste1);
 
    Cell_circuit *c2=creer_cellule(&liste1);

  ajouter_cellule(&Lc, c2);

  printf("---- aff du circuit : ---\n");
   afficher_Lcircuit(&Lc);
  */
  
     printf("---- fonction Liste des circuits : ---\n");
     
  Graphe_Rec_Circuit(&H, &Lc);

  afficher_Lcircuit(&Lc);

  /*********
  initialiser_Lcircuit(&Lc);
    afficher_Lcircuit(&Lc);
    
      init_zero(&H);
      init_sommet(&H);
      recherche_circuit(&H, &liste, 0, 0);    
      Cell_circuit *cel_cir=creer_cellule(&liste);
      ajouter_cellule(&Lc, cel_cir);
        afficher_Lcircuit(&Lc);

	
      LDCInitialise(&liste1);
      init_zero(&H);
      init_sommet(&H);
      recherche_circuit(&H, &liste1, 0, 1);    

      Cell_circuit *cel_cir1=creer_cellule(&liste1);

      ajouter_cellule(&Lc, cel_cir1);
  afficher_Lcircuit(&Lc);
  */
  return 0;

}

   
