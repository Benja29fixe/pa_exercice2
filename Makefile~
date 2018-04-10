all: main

fonctions_ex1_p1.o: fonctions_ex1_p1.h fonctions_ex1_p1.c
	gcc -c fonctions_ex1_p1.c -o fonctions_ex1_p1.o

fonctions_ex2_p1.o: fonctions_ex2_p1.h fonctions_ex2_p1.c
	gcc -c fonctions_ex2_p1.c -o fonctions_ex2_p1.o

fonctions_ex3_p1.o: fonctions_ex3_p1.h fonctions_ex3_p1.c
	gcc -c fonctions_ex3_p1.c -o fonctions_ex3_p1.o

fonctions_ex4_p1.o: fonctions_ex4_p1.h fonctions_ex4_p1.c
	gcc -c fonctions_ex4_p1.c -o fonctions_ex4_p1.o

entree_sortie.o: entree_sortie.c entree_sortie.h
	gcc -c entree_sortie.c

Solution.o: Solution.c Solution.h entree_sortie.h
	gcc -c Solution.c

Grille.o: Grille.c Grille.h Solution.h
	gcc -c Grille.c

API_AffGrille.o: API_AffGrille.c API_AffGrille.h Grille.h
	gcc -c API_AffGrille.c

main.o: main.c Grille.h API_AffGrille.h Solution.h
	gcc -c main.c 

main: main.o API_AffGrille.o Grille.o Solution.o entree_sortie.o fonctions_ex1_p1.o fonctions_ex2_p1.o fonctions_ex3_p1.o fonctions_ex4_p1.o
	gcc -o main main.o API_AffGrille.o Grille.o Solution.o fonctions_ex1_p1.o fonctions_ex2_p1.o fonctions_ex3_p1.o fonctions_ex4_p1.o entree_sortie.o -lSDL


clean:
	rm -f *.o main
