#include <stdio.h>
#include <stdlib.h>

int saisie();
void remplissage(int tab[25][25], int nb_ligcol);

int main() {
    printf("----------------------------------------\n");
    printf("Programme realiser par: Maximilien LEBER\n");
    printf("Section:    IRT1\tGroupe:\tG1\n");
    printf("Date version:   12/01/2019\n");
    printf("----------------------------------------\n");

    int tab[25][25], nb_ligcol;

    nb_ligcol = saisie();
    return 0;
}

int saisie() {
    int nb_ligcol;
    do {
        printf("Entrez un nombre de lignes et de colonnes à remplir. (Compris entre 5 et 25) : ");
        scanf("%d", &nb_ligcol);
        if (nb_ligcol<5||nb_ligcol>25) {
            printf("\nNombre invalide !\n");
            getchar();
        }
    } while (!(nb_ligcol>=5&&nb_ligcol<=25));
    return nb_ligcol;
}

int remplissage(int tab[25][25], int nb_ligcol) {
    int i=0, j=0;
}
