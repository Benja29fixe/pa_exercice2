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
  clock_t temps_initial;
  clock_t temps_final;
  double temps_cpu;
  FILE *f1;
 
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
  printf("\nAffichage des circuits : ");
  printf("\n========================\n");     
  Graphe_Rec_Circuit(&H, &Lc);
  afficher_Lcircuit(&Lc);

  printf("\nNbre de circuit : %d", Lc.nb_circuit);
  printf("\n====================\n");

  CalculJminJmax(&Lc);

  printf("\nAffichage des circuits (avec jmin, jmax) : ");
  printf("\n==========================================\n");
  afficher_Lcircuit_jmin_jmax(&Lc);

  printf("\nAlgorithme de Graf : ");
  printf("\n===================\n");

    /*******************************/
      f1=fopen("temps/algo_graf.temps", "a");
      /*******************************/
      /* Execution de l'algorithme naif */
       /*******************************/
      temps_initial=clock();
      /*******************************/
      
  algorithme_circuit_CasLigne1x1(&G, &S);

    /*******************************/
 temps_final=clock();
      temps_cpu =((double)(temps_final-temps_initial))/ CLOCKS_PER_SEC;
      fprintf(f1, "%d %d %d %f\n", G.m, G.n, G.nbcoul, temps_cpu);
      fclose(f1);
  
  Affiche(&S);
  
  return 0;
}

   
