#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*------------------------ Déclaration des prototypes de fonction / procédures ---------------------------*/
int saisie();
int saisieNbRechercher(); 
int rechercheSupp(int tab[25][25], int nb_ligcol, int nb_rechercher);
void remplissage(int tab[25][25], int nb_ligcol);
void affichage(int tab[25][25], int nb_ligcol);
void permutation(int tab[25][25], int nb_ligcol);

/*---------------------------- Déclaration du programme principal ----------------------------------------*/
int main() {

    // Déclaration de variables
    int tab[25][25], nb_ligcol, nb_rechercher, nb_supp;

    // Exécution du programme
    printf("----------------------------------------\n");
    printf("Programme realiser par: Maximilien LEBER\n");
    printf("Section:    IRT1\tGroupe:\tG1\n");
    printf("Date version:   12/01/2019\n");
    printf("----------------------------------------\n");


    nb_ligcol = saisie();

    remplissage(tab, nb_ligcol);
     
    permutation(tab, nb_ligcol);
 
    nb_rechercher = saisieNbRechercher();

    nb_supp = rechercheSupp(tab, nb_ligcol, nb_rechercher);

    printf("\nIl y a %d nombres plus grand que %d dans ce tableau.\n", nb_supp, nb_rechercher);

    return 0;
}

/*---------------------------- Déclaration des fonctions / procédures ----------------------------------------*/
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
    
    getchar();
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
    affichage(tab, nb_ligcol);
}

//Affichage du tableau
void affichage(int tab[25][25], int nb_ligcol) {
    int i=0, j=0;

    system("clear");
    for(i=0; i<nb_ligcol; i++) {
        printf("|");
        for(j=0; j<nb_ligcol; j++) {
            printf(" %2d |", tab[i][j]);
        }
        printf("\n");
    }
    
    printf("\nAppuyez sur une touche pour continuer...\n");
    getchar();
}

//Permutation des valeurs du tableau selon une diagonale descendante
void permutation(int tab[25][25], int nb_ligcol) {
    int i=0, j=0, tmp;
    
    for(i=0; i<nb_ligcol; i++) {
        for(j=0; j<i; j++) {
            tmp = tab[i][j];
            tab[i][j] = tab[j][i];
            tab[j][i] = tmp;
        }
    }
    affichage(tab, nb_ligcol);
}

int saisieNbRechercher() {
    int i=0, j=0, nb_rechercher;
    do {
        printf("Entrez le nombre a comparer avec les nombres du tableau. (Compris entre 5 et 50) : ");
        scanf("%d", &nb_rechercher);

        if (nb_rechercher < 5 || nb_rechercher > 50) {
            printf("\nNombre invalide !\n");
            getchar();
        }
    } while (!(nb_rechercher >= 5 && nb_rechercher <= 50));
    getchar();

    return nb_rechercher;
}

int rechercheSupp(int tab[25][25], int nb_ligcol, int nb_rechercher) {
    int i=0, j=0, cpt=0;
    
    for(i=0; i<nb_ligcol; i++) {
        for(j=0; j<nb_ligcol; j++) {
            if(tab[i][j] > nb_rechercher) {
                cpt++;
            }
        }
    }
    return cpt;
}
