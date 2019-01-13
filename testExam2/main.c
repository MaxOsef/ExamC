#include <stdio.h>
#include <stdlib.h>

// Prototypes de fonctions / procédures
int saisieNbrCotes();
void saisieCotes(float tab_cotes[1500], int nbr_cotes); 
void affichageCotes(float tab_cotes[1500], int nbr_cotes);
float moyenneCotes(float tab_cotes[1500], int nbr_cotes); 
void formatageDiag(float tab_cotes[1500], int nbr_cotes); 

// Programme principal
int main() {
    printf("----------------------------------------\n");
    printf("Programme realiser par: Maximilien LEBER\n");
    printf("Section:    IRT1\tGroupe:\tG1\n");
    printf("Date version:   12/01/2019\n");
    printf("----------------------------------------\n");
    
    // Déclaration de variables
    float tab_cotes[1500] = {0};
    int nbr_cotes = 0;
    
    // Exécution du programme
    nbr_cotes = saisieNbrCotes();

    saisieCotes(tab_cotes, nbr_cotes);

    affichageCotes(tab_cotes, nbr_cotes);

    printf("\n\nLa moyenne des cotes encodees est : %3.2f/100", moyenneCotes(tab_cotes, nbr_cotes));

    formatageDiag(tab_cotes, nbr_cotes);

    return 0;
}

// Fonctions / Procédures

//Saisie du nombre de cotes à encoder par l'utilisateur
int saisieNbrCotes() {
    int nbr = 0;

    do {
        printf("Entrez le nombre de cotes a encoder (Compris entre 0 et 1500) :\n");
        scanf("%d", &nbr);

        if(nbr < 0 || nbr > 1500) {
            printf("Nombre de cotes invalide, recommencez !\n");
            getc(stdin);
        }
        
        getc(stdin);
    } while (nbr < 0 || nbr > 1500);

    return nbr;
}

//Saisie des cotes et remplissage du tableau
void saisieCotes(float tab_cotes[1500], int nbr_cotes) {
    int i = 0;
    float tmp = 0;

    for(i=0; i<nbr_cotes; i++) {
        do {
            printf("Entrez la cote numero %d :", i+1);
            scanf("%f", &tmp);

            if (tmp>=0 && tmp<=100) {
                tab_cotes[i] = tmp;
            } else {
                printf("\nCote invalide, recommencez !\n");
            }

        } while (tmp<0 || tmp>100);
    }
}

//Formatage et affichage des cotes
void affichageCotes(float tab_cotes[1500], int nbr_cotes) {
    int i=0, cpt=1;
    
    system("clear");
    for (i=0; i<nbr_cotes; i++) {
        if (cpt%5 == 0) {
            printf("| %3.2f/100 |\n", tab_cotes[i]);
        } else { 
            printf("| %3.2f/100 ", tab_cotes[i]);
        }
        cpt++;
    }
}

//Calcul et affichage de la moyenne
float moyenneCotes(float tab_cotes[1500], int nbr_cotes) {
    float moyenne_cotes=0, total_cotes=0;
    int i=0;

    for(i=0; i<nbr_cotes; i++) {
        total_cotes=total_cotes+tab_cotes[i];
    }

    moyenne_cotes = total_cotes/nbr_cotes;
    
    return moyenne_cotes;
}

//Affichage du diagrame
void formatageDiag(float tab_cotes[1500], int nbr_cotes) {
    int i = 0, cpt1=0, cpt2=0, cpt3=0;
    for(i=0; i<nbr_cotes; i++) {
        if (tab_cotes[i]>=0 && tab_cotes[i]<=33) {
            cpt1++;
        } else if (tab_cotes[i]>33 && tab_cotes[i]<=66) {
            cpt2++;
        } else if (tab_cotes[i]>66 && tab_cotes[i]<=100) {
            cpt3++;
        }
    }

    printf("\nCotes comprises dans l'intervale 0 - 33 : %d\nCotes comprises dans l'intervale 34 - 66 : %d\nCotes comprises dans l'intervale 67 - 100 : %d", cpt1, cpt2, cpt3);
}
