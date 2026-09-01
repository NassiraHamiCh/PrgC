#include <stdio.h>
#include <string.h>// utlise dans les exercices de 14 a  18.
#include <ctype.h>// utlise dans le exercice  20.
#include <stdlib.h>// utlise dans l'exercice 19

int main() {
    int n;
    printf("Entrez le nombre d'elements : ");
    scanf("%d", &n);

    int tab[n];

    for (int i = 0; i < n; i++) {
        printf("Entrez l'element %d : ", i + 1);
        scanf("%d", &tab[i]);
    }

    printf("\nLes elements du tableau sont : \n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", tab[i]);
    }

    // Exercice 2
    int max = tab[0];
    for (int i = 0; i < n; i++) {
        if (max < tab[i]) {
            max = tab[i];
        }
    }
    printf("Le plus grand du tableau est %d\n", max);

    // Exercice 3
    int somme = 0;
    for (int i = 0; i < n; i++) {
        somme += tab[i];
    }
    printf("La somme des elements est %d\n", somme);
    printf("La moyenne est %d\n", somme / n);

    // Exercice 4
    printf("Affichage inverse :\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d\n", tab[i]);
    }

    // Exercice 5
    int X, comp = 0;
    printf("Saisir le nombre cherche : ");
    scanf("%d", &X);

    for (int i = 0; i < n; i++) {
        if (X == tab[i]) comp++;
    }
    printf("Le nombre %d existe %d fois\n", X, comp);

    // Exercice 6
    int position = -1;
    for (int i = 0; i < n; i++) {
        if (X == tab[i]) position = i;
    }

    if (position != -1)
        printf("Position = %d\n", position);
    else
        printf("Le nombre n'existe pas\n");

    // Exercice 7
    int M, N;
    printf("Saisir M et N : ");
    scanf("%d %d", &M, &N);

    int Matrice[M][N];

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("M[%d][%d] = ", i, j);
            scanf("%d", &Matrice[i][j]);
        }
    }

    // Exercice 8
    int M1[M][N], M2[M][N], SM[M][N];

    printf("\nRemplir Matrice 1 :\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("M1[%d][%d] = ", i, j);
            scanf("%d", &M1[i][j]);
        }
    }

    printf("\nRemplir Matrice 2 :\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("M2[%d][%d] = ", i, j);
            scanf("%d", &M2[i][j]);
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            SM[i][j] = M1[i][j] + M2[i][j];
        }
    }

    // Exercice 9 : produit matriciel
    int P[M][M];

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            P[i][j] = 0;

            for (int k = 0; k < N; k++) {
                P[i][j] += M1[i][k] * M2[k][j];
            }
        }
     }


    // Exercice 10 : plus grand element matrice
    int M10, N10;
    printf("\nSaisir M et N : ");
    scanf("%d %d", &M10, &N10);

    int Matrice10[M10][N10];

    for (int i = 0; i < M10; i++) {
        for (int j = 0; j < N10; j++) {
            printf("[%d][%d] = ", i, j);
            scanf("%d", &Matrice10[i][j]);
        }
    }

    int maxMatrice = Matrice10[0][0];

    for (int i = 0; i < M10; i++) {
        for (int j = 0; j < N10; j++) {
            if (Matrice10[i][j] > maxMatrice)
                maxMatrice = Matrice10[i][j];
        }
    }

    printf("Max = %d\n", maxMatrice);

    #include <stdio.h>
#include <string.h>// utlise dans les exercices de 14 a  18.
#include <ctype.h>// utlise dans le exercice  20.
#include <stdlib.h>// utlise dans l'exercice 19

int main() {
    int n;
    printf("Entrez le nombre d'elements : ");
    scanf("%d", &n);

    int tab[n];

    for (int i = 0; i < n; i++) {
        printf("Entrez l'element %d : ", i + 1);
        scanf("%d", &tab[i]);
    }

    printf("\nLes elements du tableau sont : \n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", tab[i]);
    }

    // Exercice 2
    int max = tab[0];
    for (int i = 0; i < n; i++) {
        if (max < tab[i]) {
            max = tab[i];
        }
    }
    printf("Le plus grand du tableau est %d\n", max);

    // Exercice 3
    int somme = 0;
    for (int i = 0; i < n; i++) {
        somme += tab[i];
    }
    printf("La somme des elements est %d\n", somme);
    printf("La moyenne est %d\n", somme / n);

    // Exercice 4
    printf("Affichage inverse :\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d\n", tab[i]);
    }

    // Exercice 5
    int X, comp = 0;
    printf("Saisir le nombre cherche : ");
    scanf("%d", &X);

    for (int i = 0; i < n; i++) {
        if (X == tab[i]) comp++;
    }
    printf("Le nombre %d existe %d fois\n", X, comp);

    // Exercice 6
    int position = -1;
    for (int i = 0; i < n; i++) {
        if (X == tab[i]) position = i;
    }

    if (position != -1)
        printf("Position = %d\n", position);
    else
        printf("Le nombre n'existe pas\n");

    // Exercice 7
    int M, N;
    printf("Saisir M et N : ");
    scanf("%d %d", &M, &N);

    int Matrice[M][N];

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("M[%d][%d] = ", i, j);
            scanf("%d", &Matrice[i][j]);
        }
    }

    // Exercice 8
    int M1[M][N], M2[M][N], SM[M][N];

    printf("\nRemplir Matrice 1 :\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("M1[%d][%d] = ", i, j);
            scanf("%d", &M1[i][j]);
        }
    }

    printf("\nRemplir Matrice 2 :\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("M2[%d][%d] = ", i, j);
            scanf("%d", &M2[i][j]);
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            SM[i][j] = M1[i][j] + M2[i][j];
        }
    }

    // Exercice 9 : produit matriciel
    int P[M][M];

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            P[i][j] = 0;

            for (int k = 0; k < N; k++) {
                P[i][j] += M1[i][k] * M2[k][j];
            }
        }
     }


    // Exercice 10 : plus grand element matrice
    int M10, N10;
    printf("\nSaisir M et N : ");
    scanf("%d %d", &M10, &N10);

    int Matrice10[M10][N10];

    for (int i = 0; i < M10; i++) {
        for (int j = 0; j < N10; j++) {
            printf("[%d][%d] = ", i, j);
            scanf("%d", &Matrice10[i][j]);
        }
    }

    int maxMatrice = Matrice10[0][0];

    for (int i = 0; i < M10; i++) {
        for (int j = 0; j < N10; j++) {
            if (Matrice10[i][j] > maxMatrice)
                maxMatrice = Matrice10[i][j];
        }
    }

    printf("Max = %d\n", maxMatrice);

        // Exercice 11 : transposée d'une matrice MxN
    int Transpose[N][M];
    printf("La matrice transposee est :\n");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            Transpose[i][j] = Matrice[j][i];
            printf("%d ", Transpose[i][j]);
        }
        printf("\n");
    }


    // Exercice 12 : vérifier si une matrice carrée est symétrique
    int N12;
    printf("Entrez la taille de la matrice carree : ");
    scanf("%d", &N12);

    int Matrice12[N12][N12];

    printf("Remplir la matrice :\n");
    for (int i = 0; i < N12; i++) {
        for (int j = 0; j < N12; j++) {
            printf("M[%d][%d] = ", i, j);
            scanf("%d", &Matrice12[i][j]);
        }
    }

    int symetrique = 1;

    for (int i = 0; i < N12; i++) {
        for (int j = 0; j < N12; j++) {
            if (Matrice12[i][j] != Matrice12[j][i]) {
                symetrique = 0;
            }
        }
    }

    if (symetrique == 1)
        printf("La matrice est symetrique.\n");
    else
        printf("La matrice n'est pas symetrique.\n");


    // Exercice 13 : afficher la diagonale principale
    printf("Les elements de la diagonale principale sont :\n");

    for (int i = 0; i < N12; i++) {
        printf("%d ", Matrice12[i][i]);
    }
    printf("\n");


    // Exercice 14 : longueur d'une chaine avec strlen

    char chaine14[100];

    printf("Entrez une chaine : ");
    scanf("%s", chaine14);

    printf("La longueur de la chaine est : %lu\n", strlen(chaine14));


    // Exercice 15 : copier une chaine avec strcpy

    char source15[100];
    char destination15[100];

    printf("Entrez la chaine source : ");
    scanf("%s", source15);

    strcpy(destination15, source15);

    printf("La chaine destination est : %s\n", destination15);


    // Exercice 16 : comparer deux chaines avec strcmp

    char chaine16_1[100];
    char chaine16_2[100];

    printf("Entrez la premiere chaine : ");
    scanf("%s", chaine16_1);

    printf("Entrez la deuxieme chaine : ");
    scanf("%s", chaine16_2);

    int comparaison16 = strcmp(chaine16_1, chaine16_2);

    if (comparaison16 == 0)
        printf("Les deux chaines sont egales.\n");
    else if (comparaison16 > 0)
        printf("La premiere chaine est plus grande.\n");
    else
        printf("La premiere chaine est plus petite.\n");


    // Exercice 17 : copier les trois premiers caracteres avec strncpy

    char source17[100];
    char destination17[100];

    printf("Entrez la chaine source : ");
    scanf("%s", source17);

    strncpy(destination17, source17, 3);

    destination17[3] = '\0';

    printf("Les trois premiers caracteres sont : %s\n", destination17);


    // Exercice 18 : concatener les deux premiers caracteres avec strncat

    char source18[100];
    char destination18[100];

    printf("Entrez la chaine destination : ");
    scanf("%s", destination18);

    printf("Entrez la chaine source : ");
    scanf("%s", source18);

    strncat(destination18, source18, 2);

    printf("La chaine finale est : %s\n", destination18);


    // Exercice 19 : convertir une chaine en entier avec atoi

    char chaine19[100];

    printf("Entrez un nombre sous forme de chaine : ");
    scanf("%s", chaine19);

    int nombre19 = atoi(chaine19);

    printf("La valeur entiere est : %d\n", nombre19);


    // Exercice 20 : majuscule ou minuscule avec isupper et islower

    char chaine20[100];

    printf("Entrez une chaine : ");
    scanf("%s", chaine20);

    for (int i = 0; chaine20[i] != '\0'; i++) {

        if (isupper(chaine20[i]))
            printf("%c : majuscule\n", chaine20[i]);

        else if (islower(chaine20[i]))
            printf("%c : minuscule\n", chaine20[i]);

        else
            printf("%c : ni majuscule ni minuscule\n", chaine20[i]);
    }

    return 0;
}