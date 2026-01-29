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

    // Exercice 9 : produit terme à terme
    int P[M][N];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            P[i][j] = M1[i][j] * M2[i][j];
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

    return 0;
}