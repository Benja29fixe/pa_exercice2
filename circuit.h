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

void afficher_Lcircuit_jmin_jmax(Lcircuit *Lc);

void Graphe_Rec_Circuit(Graphe *H, Lcircuit *Lc);

void CalculJminJmaxCEL(Cell_circuit *Cir);

void CalculJminJmax(Lcircuit *LC);


Cell_char * pluscourtchemin_apres_c(Solution *S, Cell_char *c, int j, int l, Cell_char** Tref);

void Ajout_circuit_dans_solution(Cell_circuit *L, Solution *S, Cell_char *c, Cell_char **Tref, int* Jdroite);

void algorithme_circuit_CasLigne1x1(Grille *G, Solution *S);

void algorithme_circuit_CasLigne1x1(Grille *G, Solution *S);

void afficheTREF(Cell_char** Tref, int n);
