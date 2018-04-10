typedef struct cell_circuit{
  LDC *L;
  int jmin, jmax;
  struct cell_circuit *suiv;
}Cell_circuit;

typedef struct{
  int nb_circuit;
  Cell_circuit *premier;
  Cell_circuit *dernier;
}Lcircuit;


void init_sommet(Graphe *H);

void init_zero(Graphe *H);

void affiche_visit(Graphe *H);

void recherche_circuit(Graphe *H, LDC *liste, int a, int b);

void initialiser_Cell_circuit(Cell_circuit *cellule);

void initialiser_Lcircuit(Lcircuit *liste_cellule);

int Lcircuit_Vide(Lcircuit *ldc);

Cell_circuit *creer_cellule(LDC *lc);

void ajouter_cellule(Lcircuit *liste_cellule, Cell_circuit *cel);

void afficher_Lcircuit(Lcircuit *Lc);

void Graphe_Rec_Circuit(Graphe *H, Lcircuit *Lc);


