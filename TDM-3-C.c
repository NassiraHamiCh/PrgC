#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ===============================
// Exercice 6 : copier un tableau (méthode 1)
// ===============================
void copyArray(int *src, int *dest, int size) {
    // On copie chaque élément du tableau source vers le tableau destination
    for(int i = 0; i < size; i++) {
        *(dest + i) = *(src + i);  // équivalent à dest[i] = src[i]
    }
}

// ===============================
// Exercice 6 : copier un tableau (méthode 2)
// ===============================
void FunCpy(int *p1, int *p2, int taille){
    for(int i=0;i < taille ;i++){
        *p2 = *p1;  // copier la valeur pointée par p1 vers p2
        p1++;       // avancer au prochain élément
        p2++;
    }
}

// ===============================
// Exercice 8 : remplacer chaque lettre par la suivante
// ===============================
void replaceNextChar(char *str) {
    for(; *str != '\0'; str++) {
        if(*str >= 'a' && *str <= 'y') *str = *str + 1;  // lettres minuscules
        else if(*str == 'z') *str = 'a';                 // z devient a
        else if(*str >= 'A' && *str <= 'Y') *str = *str + 1; // lettres majuscules
        else if(*str == 'Z') *str = 'A';                // Z devient A
    }
}

// ===============================
// Exercice 9 : comparer deux chaînes sans strcmp
// ===============================
int compareStrings(char *s1, char *s2) {
    while(*s1 && *s2) {           // tant que ni l'une ni l'autre chaîne n'est finie
        if(*s1 != *s2) return 0;  // si un caractère diffère, elles ne sont pas égales
        s1++; s2++;
    }
    return (*s1 == *s2);          // retourne 1 si fin des 2 chaînes, sinon 0
}

// ===============================
// Exercice 11 : somme d'un tableau 2D
// ===============================
int sum2D(int rows, int cols, int (*T)[cols]) {
    int sum = 0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            sum += *(*(T+i)+j);  // équivalent à sum += T[i][j]
        }
    }
    return sum;
}

// ===============================
// Exercice 12 : échanger deux lignes d'un tableau 2D
// ===============================
void swapRows(int rows, int cols, int T[rows][cols], int r1, int r2) {
    for(int j=0; j<cols; j++){
        int temp = T[r1][j];
        T[r1][j] = T[r2][j];
        T[r2][j] = temp;
    }
}

// ===============================
// Exercice 14 : trier tableau de chaînes
// ===============================
void sortStrings(char *arr[], int n) {
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(strcmp(arr[i], arr[j]) > 0){  // si arr[i] > arr[j]
                char *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;               // échange des pointeurs
            }
        }
    }
}

// ===============================
// Exercice 15 : concaténer plusieurs chaînes
// ===============================
void concatStrings(char *arr[], int n, char *result) {
    result[0] = '\0';           // initialiser la chaîne résultat
    for(int i=0; i<n; i++){
        strcat(result, arr[i]); // ajouter chaque chaîne
    }
}

// ===============================
// Exercice 19 : swap de deux entiers
// ===============================
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ===============================
// Exercice 20 : maximum d'un tableau
// ===============================
int maxArray(int *arr, int size) {
    int max = arr[0];
    for(int i=1; i<size; i++){
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

// ===============================
// Fonction principale
// ===============================
int main() {

    // --- Exercice 1 : pointeur simple ---
    int n1 = 10;
    int *p1 = &n1;
    printf("Ex1 : Valeur = %d, Adresse = %p\n", *p1, (void*)p1);

    // --- Exercice 3 : pointeur non initialisé (attention : erreur possible) ---
    int *ptr;
    // printf("Ex2 : Valeur via pp = %d, Adresse de p = %p\n", *ptr); // Ne pas exécuter, undefined behavior

    // --- Exercice 2 : double pointeur ---
    int n2 = 20;
    int *p2 = &n2;
    int **pp2 = &p2;
    printf("Ex2 : Valeur via pp = %d, Adresse de p = %p\n", **pp2, (void*)pp2);

    // --- Exercice 4 : parcourir tableau avec pointeur ---
    int T1[5] = {1,2,3,4,5};
    int *pt;
    printf("Ex4 : ");
    for(pt = T1; pt < T1+5; pt++) printf("%d ", *pt);
    printf("\n");

    // --- Exercice 5 : doubler les valeurs du tableau ---
    for(pt = T1; pt < T1+5; pt++) *pt *= 2;
    printf("Ex5 : ");
    for(pt = T1; pt < T1+5; pt++) printf("%d ", *pt);
    printf("\n");

    // --- Exercice 6 : copier tableau ---
    int T2[5];
    copyArray(T1, T2, 5);
    printf("Ex6 : Copie = ");
    for(int i=0; i<5; i++) printf("%d ", T2[i]);
    printf("\n");

    // --- Exercice 7 : compter caractères ---
    char msg7[] = "hello world";
    int count = 0;
    for(char *p=msg7; *p != '\0'; p++) count++;
    printf("Ex7 : Nombre de caractères = %d\n", count);

    // --- Exercice 8 : remplacer lettres ---
    char msg8[] = "abcXYZ";
    replaceNextChar(msg8);
    printf("Ex8 : %s\n", msg8);

    // --- Exercice 9 : comparer chaînes ---
    char s1[] = "hello";
    char s2[] = "hello";
    printf("Ex9 : Comparaison = %d\n", compareStrings(s1,s2));

    // --- Exercice 10 : afficher tableau 2D ---
    int T3[2][3] = {{1,2,3},{4,5,6}};
    printf("Ex10 : ");
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            printf("%d ", *(*(T3+i)+j));
        }
    }
    printf("\n");

    // --- Exercice 11 : somme tableau 2D ---
    printf("Ex11 : Somme = %d\n", sum2D(2,3,T3));

    // --- Exercice 12 : échanger lignes ---
    int T4[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    swapRows(3,3,T4,0,2);
    printf("Ex12 : \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) printf("%d ",T4[i][j]);
        printf("\n");
    }

    // --- Exercice 13 : tableau de chaînes ---
    char *tabStr[] = {"hello", "world", "C"};
    printf("Ex13 : ");
    for(int i=0;i<3;i++) printf("%s ", tabStr[i]);
    printf("\n");

    // --- Exercice 14 : trier chaînes ---
    sortStrings(tabStr, 3);
    printf("Ex14 : ");
    for(int i=0;i<3;i++) printf("%s ", tabStr[i]);
    printf("\n");

    // --- Exercice 15 : concaténer chaînes ---
    char result[100];
    concatStrings(tabStr,3,result);
    printf("Ex15 : %s\n", result);

    // --- Exercice 16 : allocation dynamique 1D ---
    int n16 = 5;
    int *arr16 = (int*)malloc(n16 * sizeof(int));
    for(int i=0;i<n16;i++) arr16[i] = i+1;
    printf("Ex16 : ");
    for(int i=0;i<n16;i++) printf("%d ", arr16[i]);
    printf("\n");
    free(arr16);  // libérer la mémoire

    // --- Exercice 17 : allocation dynamique 2D ---
    int rows17=2, cols17=3;
    int **T17 = (int**)malloc(rows17*sizeof(int*));
    for(int i=0;i<rows17;i++){
        T17[i] = (int*)malloc(cols17*sizeof(int));
        for(int j=0;j<cols17;j++) T17[i][j] = i+j;
    }
    printf("Ex17 : \n");
    for(int i=0;i<rows17;i++){
        for(int j=0;j<cols17;j++) printf("%d ", T17[i][j]);
        printf("\n");
    }
    for(int i=0;i<rows17;i++) free(T17[i]);
    free(T17);

    // --- Exercice 18 : allocation dynamique pour chaîne ---
    char *s18 = (char*)malloc(20*sizeof(char));
    strcpy(s18,"hello malloc");
    printf("Ex18 : %s\n", s18);
    free(s18);

    // --- Exercice 19 : swap de valeurs ---
    int a=5,b=10;
    swap(&a,&b);
    printf("Ex19 : a=%d b=%d\n",a,b);

    // --- Exercice 20 : maximum d'un tableau ---
    int T20[5] = {3,7,1,9,5};
    printf("Ex20 : Max = %d\n", maxArray(T20,5));

    return 0;
}