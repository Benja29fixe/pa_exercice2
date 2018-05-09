#include<stdlib.h>
#include<stdio.h>
#include"Graphe.h"
#include"ListeDC.h"
#include"circuit.h"

/*
 * Initialisation
 * Sommets sans successeurs sont noires
 * visit = -2
 */
void init_sommet(Graphe *H)
{
  int i, j;
  
  for(i=0; i<H->m; i++){
    for(j=0; j<H->n; j++){
      if(H->Tsom[i][j]->Lsucc==NULL){
	H->Tsom[i][j]->visit=-2;
      }
    }
  }
}

/*
 * Initialiser tous les sommets du graphe a -1 
 */
void init_zero(Graphe *H)
{
  int i, j;
  
  for(i=0; i<H->m; i++){
    for(j=0; j<H->n; j++){
     
      H->Tsom[i][j]->visit=-1;
    }
  }
}
  
/*
 * Affichage visit 
 */
void affiche_visit(Graphe *H)
{
  int i, j;

  printf("Visit :\n");
  for(i=0; i<H->m; i++){
    for(j=0; j<H->n; j++){
      printf("(%d, %d)visit: %d ", H->Tsom[i][j]->i,  H->Tsom[i][j]->j,  H->Tsom[i][j]->visit);
    }
  }
}

/*
 * Recherche d'un circuit d'un graphe,
 * à partir d'un sommet (a, b) 
 */
void recherche_circuit(Graphe *H, LDC *liste, int a, int b)
{
  Arc *courant=H->Tsom[a][b]->Lsucc;
  
  if( H->Tsom[a][b]->visit==-1){
    H->Tsom[a][b]->visit=0;
    LDCInsererEnFin(liste, a, b);
  }

  int v1=courant->succ->i;
  int v2=courant->succ->j;
    
  if(H->Tsom[v1][v2]->visit==-1){
    recherche_circuit(H, liste, v1, v2);
  }
}

/*
 * Initialisation cellule 
 */
void initialiser_Cell_circuit(Cell_circuit *cellule)
{
  cellule->jmin=0;
  cellule->jmax=0;
  cellule->suiv=NULL;
}

/*
 * Initialisation circuit
 */
void initialiser_Lcircuit(Lcircuit *liste_cellule)
{
  liste_cellule->nb_circuit=0;
  liste_cellule->premier=NULL;
  liste_cellule->dernier=NULL;

  printf("Liste circuit initialisée. \n");
}

/*
 * Teste si un circuit est vide 
 */
int Lcircuit_Vide(Lcircuit *ldc){
  return (ldc->premier==NULL);
}

/*
 * Creation d'une cellule
 */
Cell_circuit *creer_cellule(LDC* lc)
{
  Cell_circuit *n_cell=(Cell_circuit*)malloc(sizeof(Cell_circuit));
  if(n_cell==NULL){
    printf("Probleme d'allocation. \n");
    return 0;
  }

  n_cell->L=lc;
  n_cell->suiv=NULL;

  return n_cell;
}
/*
 * Ajout d'une cellule, en fin de liste
 */
void ajouter_cellule(Lcircuit *liste_cellule, Cell_circuit *cel)
{
  if(Lcircuit_Vide(liste_cellule)){
    liste_cellule->premier=cel;
    liste_cellule->dernier=cel;
    cel->suiv=NULL;
    (liste_cellule->nb_circuit)++;

  }else{
    liste_cellule->dernier->suiv=cel;
    liste_cellule->dernier=cel;
    cel->suiv=NULL;
    (liste_cellule->nb_circuit)++;
  }
}

/*
 * Affichage du circuit 
 */
void afficher_Lcircuit(Lcircuit *Lc)
{
  Cell_circuit *temp=Lc->premier;

  while(temp){
    LDCafficher(temp->L);

    printf("Valeur jmin, jmax : [%d, %d]\n", temp->jmin, temp->jmax);
   

    temp=temp->suiv;
  }
}

/*
 * Recherche et enregistre tous les circuits d'un graphe
 * dans une liste chainee de circuit
 */
void Graphe_Rec_Circuit(Graphe *H, Lcircuit *Lc)
{
  int i, j;
  initialiser_Lcircuit(Lc);
  LDC *liste=(LDC*)malloc((H->m)*(H->n)*sizeof(LDC));
  
  for(i=0; i<H->m; i++){
    for(j=0; j<H->n; j++){
     
      LDCInitialise(&liste[i*(H->m)*(H->n)+j]);
      init_zero(H);
      init_sommet(H);

      if(H->Tsom[i][j]->visit==-1){
	recherche_circuit(H, &liste[i*(H->m)*(H->n)+j], i, j);    

	Cell_circuit *cel_cir=creer_cellule(&liste[i*(H->m)*(H->n)+j]);
	ajouter_cellule(Lc, cel_cir);
      }     
    }
  }
  //afficher_Lcircuit(Lc);  
}

/*
 *
 */
void CalculJminJmax(Lcircuit *LC)
{
  Cell_circuit *cel=LC->premier;

  while(cel){
    cel->jmin=cel->L->premier->j;
    cel->jmax=cel->L->dernier->j;

    cel=cel->suiv;
  }
}

/*
 *
 */
void CalculJminJmaxxx(Lcircuit *LC)
{
  int i=0;
  int j=0;

  int *temp_min=(int *)malloc(LC->nb_circuit*sizeof(int));
  int *temp_max=(int *)malloc(LC->nb_circuit*sizeof(int));

  for(j=0; j<LC->nb_circuit; j++){
    temp_min[j]=LC->nb_circuit;
    temp_max[j]=0;
  }

  Cell_circuit *cel=LC->premier;

  
  //  for(i=0; i<LC->nb_circuit; i++){
  
    while(cel){

         CelluleLDC *celd=LC->premier->L->premier;
      while(celd){
      
	if(celd->j<temp_min[i]){
	  LC->premier->jmin=celd->j;
	  temp_min[i]=celd->j;
	  printf("\nt min : %d\n", temp_min[i]); 
	}

	if(celd->j>temp_max[i]){
	  LC->premier->jmax=celd->j;
	  temp_max[i]=celd->j;
	  printf("\nt max : %d\n", temp_max[i]); 
	}
	celd=celd->suiv;
      }
    
      printf("\ntemp_min[%d]: %d / temp_max[%d]: %d\n", i, temp_min[i], i, temp_max[i]);
      cel=cel->suiv;
      i++;
    }
  
}


