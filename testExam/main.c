#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int saisie();
void remplissage(int tab[25][25], int nb_ligcol);
void affichage(int tab[25][25], int nb_ligcol);
void permutation(int tab[25][25], int nb_ligcol);

int main() {

    // Déclaration de variables
    int tab[25][25], nb_ligcol;

    // Exécution du programme
    printf("----------------------------------------\n");
    printf("Programme realiser par: Maximilien LEBER\n");
    printf("Section:    IRT1\tGroupe:\tG1\n");
    printf("Date version:   12/01/2019\n");
    printf("----------------------------------------\n");


    nb_ligcol = saisie();

    remplissage(tab, nb_ligcol);
    
    affichage(tab, nb_ligcol);
    
    permutation(tab, nb_ligcol);
    
    affichage(tab, nb_ligcol);

    return 0;
}

//Saisie des dimensions du tableau par l'utilisateur
int saisie() {
    int nb_ligcol;
    do {
        printf("Entrez un nombre de lignes et de colonnes à remplir. (Compris entre 5 et 25) : ");
        scanf("%d", &nb_ligcol);
        if (nb_ligcol < 5 || nb_ligcol > 25) {
            printf("\nNombre invalide !\n");
            getchar();
        }
    } while (!(nb_ligcol >= 5 && nb_ligcol <= 25));
    return nb_ligcol;
}

//Remplissage du tableau avec des nombres aléatoires
void remplissage(int tab[25][25], int nb_ligcol) {
    int i=0, j=0;
    srand(time(NULL));

    for(i=0; i<nb_ligcol; i++) {
        for(j=0; j<nb_ligcol; j++) {
            tab[i][j] = rand() % 46 + 5;
        }
    }
}

//Affichage du tableau
void affichage(int tab[25][25], int nb_ligcol) {
    int i=0, j=0;

    //system("clear");
    for(i=0; i<nb_ligcol; i++) {
        printf("|");
        for(j=0; j<nb_ligcol; j++) {
            printf(" %2d |", tab[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
}

void permutation(int tab[25][25], int nb_ligcol) {
    int i=0, j=0, tmp;
    
    for(i=0;i<nb_ligcol;i++) {
        for(j=0; j<i; j++) {
            tmp = tab[i][j];
            tab[i][j] = tab[j][i];
            tab[j][i] = tmp;
        }
    }
}
