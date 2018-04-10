all: main


entree_sortie.o: entree_sortie.c entree_sortie.h
	gcc -c entree_sortie.c

Solution.o: Solution.c Solution.h entree_sortie.h
	gcc -c Solution.c

Grille.o: Grille.c Grille.h Solution.h
	gcc -c Grille.c

API_AffGrille.o: API_AffGrille.c API_AffGrille.h Grille.h
	gcc -c API_AffGrille.c

Graphe.o: Graphe.c Graphe.h
	gcc -c Graphe.c

ListeDC.o: ListeDC.h ListeDC.c
	gcc -c ListeDC.c

circuit.o: circuit.h circuit.c
	gcc -c circuit.c

main.o: main.c Grille.h API_AffGrille.h Solution.h
	gcc -c main.c 

main: main.o API_AffGrille.o Grille.o Solution.o entree_sortie.o Graphe.o ListeDC.o circuit.o
	gcc -o main main.o API_AffGrille.o Grille.o Solution.o Graphe.o entree_sortie.o ListeDC.o circuit.o -lSDL


clean:
	rm -f *.o main
