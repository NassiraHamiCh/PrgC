# 🔷 C - Résumé Détaillé Complet

## 📚 Table des matières
1. [Bases du C](#1-bases-du-c)
2. [Types de données](#2-types-de-données)
3. [Opérateurs](#3-opérateurs)
4. [Structures conditionnelles](#4-structures-conditionnelles)
5. [Boucles](#5-boucles)
6. [Fonctions](#6-fonctions)
7. [Tableaux](#7-tableaux)
8. [Chaînes de caractères](#8-chaînes-de-caractères)
9. [Pointeurs](#9-pointeurs)
10. [Pointeurs et tableaux](#10-pointeurs-et-tableaux)
11. [Pointeurs et chaînes](#11-pointeurs-et-chaînes)
12. [Pointeurs de pointeurs](#12-pointeurs-de-pointeurs)
13. [Allocation dynamique](#13-allocation-dynamique)
14. [Structures (struct)](#14-structures-struct)
15. [Unions](#15-unions)
16. [Énumérations (enum)](#16-énumérations-enum)
17. [typedef](#17-typedef)
18. [Pointeurs de fonctions](#18-pointeurs-de-fonctions)
19. [Fichiers](#19-fichiers)
20. [Préprocesseur](#20-préprocesseur)
21. [Algorithmes de tri](#21-algorithmes-de-tri)

---

## 1. Bases du C

### 1.1 Structure d'un programme
```c
#include <stdio.h>    // Bibliothèque d'entrée/sortie
#include <stdlib.h>   // Bibliothèque standard

int main() {
    printf("Hello World\n");
    return 0;  // Indique succès
}
```

### 1.2 Compilation
```bash
# Compiler
gcc programme.c -o programme

# Exécuter
./programme

# Avec warnings
gcc -Wall -Wextra programme.c -o programme
```

### 1.3 Entrées/Sorties de base
```c
#include <stdio.h>

int main() {
    // Affichage
    printf("Bonjour\n");
    printf("x = %d, y = %f\n", 10, 3.14);
    
    // Saisie
    int age;
    printf("Entrez votre âge : ");
    scanf("%d", &age);  // & = adresse de la variable
    
    // Saisie de chaîne
    char nom[50];
    scanf("%s", nom);   // Pas de & pour les tableaux
    
    return 0;
}
```

### 1.4 Commentaires
```c
// Commentaire sur une ligne

/*
 * Commentaire
 * sur plusieurs
 * lignes
 */
```

---

## 2. Types de données

### 2.1 Types de base
```c
// Entiers
int x = 42;                    // 4 octets, -2147483648 à 2147483647
short s = 100;                 // 2 octets
long l = 1000000L;             // 4 ou 8 octets
long long ll = 9999999999LL;   // 8 octets

// Non signés
unsigned int u = 42;           // Que des positifs
unsigned char uc = 255;        // 0 à 255

// Caractères
char c = 'A';                  // 1 octet, code ASCII

// Décimaux
float f = 3.14f;               // 4 octets, précision ~7 chiffres
double d = 3.14159;            // 8 octets, précision ~15 chiffres

// Booléen (C99+)
#include <stdbool.h>
bool actif = true;
```

### 2.2 Tailles des types
```c
#include <stdio.h>

int main() {
    printf("char      : %zu octets\n", sizeof(char));
    printf("short     : %zu octets\n", sizeof(short));
    printf("int       : %zu octets\n", sizeof(int));
    printf("long      : %zu octets\n", sizeof(long));
    printf("float     : %zu octets\n", sizeof(float));
    printf("double    : %zu octets\n", sizeof(double));
    printf("pointeur  : %zu octets\n", sizeof(int*));
    
    return 0;
}
```

### 2.3 Constantes
```c
#define PI 3.14159       // Macro (préprocesseur)
const int MAX = 100;     // Constante (runtime)

enum { LUNDI = 1, MARDI, MERCREDI };  // Énumération
```

### 2.4 Formatage printf/scanf
```c
// Printf
printf("%d", 42);        // int
printf("%u", 42u);       // unsigned int
printf("%ld", 42L);      // long
printf("%f", 3.14);      // float/double
printf("%.2f", 3.14159); // 2 décimales → 3.14
printf("%c", 'A');       // char
printf("%s", "texte");   // chaîne
printf("%p", ptr);       // adresse (pointeur)
printf("%x", 255);       // hexadécimal → ff

// Scanf
int x;
scanf("%d", &x);         // Lire un entier
```

---

## 3. Opérateurs

### 3.1 Opérateurs arithmétiques
```c
int a = 10, b = 3;

int somme = a + b;           // 13
int diff = a - b;            // 7
int prod = a * b;            // 30
float div = a / (float)b;    // 3.333... (cast important!)
int div_ent = a / b;         // 3 (division entière)
int reste = a % b;           // 1 (modulo)

// Incrémentation
a++;    // Post-incrémentation (utilise puis incrémente)
++a;    // Pré-incrémentation (incrémente puis utilise)
a--;    // Décrémentation
```

### 3.2 Opérateurs de comparaison
```c
a == b   // Égal à
a != b   // Différent de
a < b    // Inférieur
a > b    // Supérieur
a <= b   // Inférieur ou égal
a >= b   // Supérieur ou égal
```

### 3.3 Opérateurs logiques
```c
int a = 1, b = 0;

a && b   // ET logique (AND)
a || b   // OU logique (OR)
!a       // NON logique (NOT)

// Exemple
if (age >= 18 && age < 65) {
    printf("Adulte actif\n");
}
```

### 3.4 Opérateurs bit à bit
```c
int a = 5;   // 0101 en binaire
int b = 3;   // 0011 en binaire

a & b    // ET bit à bit  → 0001 = 1
a | b    // OU bit à bit  → 0111 = 7
a ^ b    // XOR bit à bit → 0110 = 6
~a       // NON bit à bit → 1010 (complément)
a << 1   // Décalage gauche → 1010 = 10
a >> 1   // Décalage droite → 0010 = 2
```

### 3.5 Opérateurs d'affectation
```c
int x = 10;

x += 5;   // x = x + 5
x -= 3;   // x = x - 3
x *= 2;   // x = x * 2
x /= 4;   // x = x / 4
x %= 3;   // x = x % 3
```

---

## 4. Structures conditionnelles

### 4.1 if, else if, else
```c
int age = 20;

if (age < 18) {
    printf("Mineur\n");
} else if (age >= 18 && age < 65) {
    printf("Adulte\n");
} else {
    printf("Senior\n");
}
```

### 4.2 Opérateur ternaire
```c
int age = 20;
char *statut = (age >= 18) ? "Majeur" : "Mineur";
printf("%s\n", statut);
```

### 4.3 switch
```c
int jour = 3;

switch (jour) {
    case 1:
        printf("Lundi\n");
        break;
    case 2:
        printf("Mardi\n");
        break;
    case 3:
        printf("Mercredi\n");
        break;
    default:
        printf("Autre jour\n");
}
```

---

## 5. Boucles

### 5.1 Boucle for
```c
// Boucle classique
for (int i = 0; i < 5; i++) {
    printf("%d ", i);  // 0 1 2 3 4
}

// Boucle avec pas
for (int i = 0; i < 10; i += 2) {
    printf("%d ", i);  // 0 2 4 6 8
}

// Boucle décroissante
for (int i = 5; i > 0; i--) {
    printf("%d ", i);  // 5 4 3 2 1
}

// Boucle infinie
for (;;) {
    // Code
    break;  // Sortie nécessaire
}
```

### 5.2 Boucle while
```c
int i = 0;
while (i < 5) {
    printf("%d ", i);
    i++;
}

// Condition d'arrêt
char reponse;
while (reponse != 'q') {
    printf("Continuer (q pour quitter) ? ");
    scanf(" %c", &reponse);
}
```

### 5.3 Boucle do-while
```c
int i = 0;
do {
    printf("%d ", i);
    i++;
} while (i < 5);  // S'exécute au moins une fois
```

### 5.4 break et continue
```c
// break : sortir de la boucle
for (int i = 0; i < 10; i++) {
    if (i == 5) break;
    printf("%d ", i);  // 0 1 2 3 4
}

// continue : passer à l'itération suivante
for (int i = 0; i < 5; i++) {
    if (i == 2) continue;
    printf("%d ", i);  // 0 1 3 4
}
```

---

## 6. Fonctions

### 6.1 Définition et appel
```c
// Prototype (déclaration)
int addition(int a, int b);

int main() {
    int resultat = addition(5, 3);
    printf("Résultat : %d\n", resultat);
    return 0;
}

// Définition
int addition(int a, int b) {
    return a + b;
}
```

### 6.2 Fonction void
```c
void afficher_message() {
    printf("Bonjour !\n");
    // Pas de return (ou return; sans valeur)
}
```

### 6.3 Passage par valeur vs par référence
```c
// Par valeur (copie)
void incrementer_valeur(int x) {
    x++;  // Ne modifie pas la variable originale
}

// Par référence (pointeur)
void incrementer_reference(int *x) {
    (*x)++;  // Modifie la variable originale
}

int main() {
    int a = 5;
    incrementer_valeur(a);      // a reste 5
    incrementer_reference(&a);  // a devient 6
    return 0;
}
```

### 6.4 Retour multiple via pointeurs
```c
void division(int a, int b, int *quotient, int *reste) {
    *quotient = a / b;
    *reste = a % b;
}

int main() {
    int q, r;
    division(10, 3, &q, &r);
    printf("Quotient: %d, Reste: %d\n", q, r);  // 3, 1
    return 0;
}
```

### 6.5 Récursivité
```c
// Factorielle
int factorielle(int n) {
    if (n <= 1) return 1;
    return n * factorielle(n - 1);
}

// Fibonacci
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

---

## 7. Tableaux

### 7.1 Déclaration et initialisation
```c
// Déclaration
int nombres[5];  // Tableau de 5 entiers

// Initialisation
int tab[5] = {1, 2, 3, 4, 5};
int tab2[] = {1, 2, 3};  // Taille déduite : 3
int tab3[5] = {1, 2};    // Reste initialisé à 0

// Initialisation à zéro
int zeros[100] = {0};
```

### 7.2 Accès aux éléments
```c
int tab[5] = {10, 20, 30, 40, 50};

// Lecture
int premier = tab[0];   // 10
int dernier = tab[4];   // 50

// Modification
tab[2] = 99;  // {10, 20, 99, 40, 50}

// Parcours
for (int i = 0; i < 5; i++) {
    printf("%d ", tab[i]);
}
```

### 7.3 Tableaux multidimensionnels
```c
// Matrice 2D
int matrice[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};

// Accès
int element = matrice[1][2];  // 7

// Parcours
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
        printf("%d ", matrice[i][j]);
    }
    printf("\n");
}

// Tableau 3D
int cube[2][3][4];
```

### 7.4 Taille d'un tableau
```c
int tab[] = {1, 2, 3, 4, 5};
int taille = sizeof(tab) / sizeof(tab[0]);  // 5

printf("Taille : %d\n", taille);
```

### 7.5 Passage de tableaux aux fonctions
```c
// Le tableau est passé par référence (adresse)
void afficher_tableau(int tab[], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

// Équivalent avec pointeur
void afficher_tableau2(int *tab, int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%d ", tab[i]);
    }
}

int main() {
    int nombres[] = {1, 2, 3, 4, 5};
    afficher_tableau(nombres, 5);
    return 0;
}
```

---

## 8. Chaînes de caractères

### 8.1 Déclaration et initialisation
```c
// Tableau de caractères
char nom[50] = "Alice";
char prenom[] = "Bob";  // Taille automatique

// Avec pointeur
char *message = "Bonjour";  // Chaîne constante

// Caractère de fin
char texte[6] = {'H', 'e', 'l', 'l', 'o', '\0'};  // '\0' obligatoire
```

### 8.2 Fonctions de <string.h>
```c
#include <string.h>

char str1[50] = "Bonjour";
char str2[50] = "Monde";

// Longueur
int len = strlen(str1);  // 7

// Copie
strcpy(str1, "Hello");   // str1 = "Hello"
strncpy(str1, "Hi", 2);  // Copie n caractères

// Concaténation
strcat(str1, str2);      // str1 = "HelloMonde"
strncat(str1, str2, 3);  // Ajoute n caractères

// Comparaison
int cmp = strcmp(str1, str2);  // 0 si égal, <0 si str1<str2, >0 si str1>str2

// Recherche
char *pos = strchr(str1, 'o');   // Cherche caractère
char *pos2 = strstr(str1, "Mon"); // Cherche sous-chaîne
```

### 8.3 Saisie et affichage
```c
char nom[50];

// Saisie (sans espaces)
scanf("%s", nom);

// Saisie avec espaces
fgets(nom, 50, stdin);
nom[strcspn(nom, "\n")] = '\0';  // Enlever \n

// Affichage
printf("Nom : %s\n", nom);
puts(nom);  // Ajoute automatiquement \n
```

### 8.4 Manipulation manuelle
```c
// Copie manuelle
void copier_chaine(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

// Longueur manuelle
int longueur_chaine(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Comparaison manuelle
int comparer_chaines(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char*)s1 - *(unsigned char*)s2;
}
```

---

## 9. Pointeurs

### 9.1 Bases des pointeurs
```c
int x = 42;
int *ptr;      // Déclaration d'un pointeur vers int

ptr = &x;      // ptr contient l'adresse de x
int valeur = *ptr;  // Déréférencement : valeur = 42

printf("Valeur de x : %d\n", x);
printf("Adresse de x : %p\n", (void*)&x);
printf("Valeur de ptr : %p\n", (void*)ptr);
printf("Valeur pointée : %d\n", *ptr);

// Modification via pointeur
*ptr = 100;    // x devient 100
```

### 9.2 Pointeurs et types
```c
// Pointeur vers int
int x = 10;
int *p_int = &x;

// Pointeur vers float
float f = 3.14;
float *p_float = &f;

// Pointeur vers char
char c = 'A';
char *p_char = &c;

// Pointeur vers double
double d = 2.718;
double *p_double = &d;

// Affichage
printf("int    : %d à l'adresse %p\n", *p_int, (void*)p_int);
printf("float  : %f à l'adresse %p\n", *p_float, (void*)p_float);
printf("char   : %c à l'adresse %p\n", *p_char, (void*)p_char);
printf("double : %lf à l'adresse %p\n", *p_double, (void*)p_double);
```

### 9.3 Arithmétique des pointeurs
```c
int tab[] = {10, 20, 30, 40, 50};
int *ptr = tab;  // ptr pointe vers tab[0]

printf("%d\n", *ptr);      // 10
printf("%d\n", *(ptr+1));  // 20 (avance de sizeof(int) octets)
printf("%d\n", *(ptr+2));  // 30

// Incrémentation
ptr++;         // Pointe vers tab[1]
printf("%d\n", *ptr);  // 20

// Différence entre pointeurs
int *p1 = &tab[1];
int *p2 = &tab[4];
int diff = p2 - p1;  // 3 (nombre d'éléments)
```

### 9.4 Pointeur NULL
```c
int *ptr = NULL;  // Pointeur ne pointe vers rien

// Vérification
if (ptr == NULL) {
    printf("Pointeur non initialisé\n");
}

// Éviter déréférencement de NULL
if (ptr != NULL) {
    printf("%d\n", *ptr);  // Sûr
}
```

### 9.5 Pointeur constant vs constante pointée
```c
int x = 10, y = 20;

// Pointeur constant (adresse fixe)
int * const ptr1 = &x;
// ptr1 = &y;  // ERREUR
*ptr1 = 15;    // OK

// Valeur constante (via pointeur)
const int *ptr2 = &x;
ptr2 = &y;     // OK
// *ptr2 = 15; // ERREUR

// Les deux constants
const int * const ptr3 = &x;
// ptr3 = &y;  // ERREUR
// *ptr3 = 15; // ERREUR
```

---

## 10. Pointeurs et tableaux

### 10.1 Équivalence tableau/pointeur
```c
int tab[5] = {10, 20, 30, 40, 50};

// Ces deux notations sont équivalentes
int *ptr = tab;        // tab est l'adresse du premier élément
int *ptr2 = &tab[0];   // Même chose

// Accès aux éléments
printf("%d\n", tab[2]);    // 30
printf("%d\n", *(tab+2));  // 30 (équivalent)
printf("%d\n", ptr[2]);    // 30
printf("%d\n", *(ptr+2));  // 30
```

### 10.2 Parcours avec pointeurs
```c
int tab[] = {1, 2, 3, 4, 5};
int taille = 5;

// Méthode 1 : indexation classique
for (int i = 0; i < taille; i++) {
    printf("%d ", tab[i]);
}

// Méthode 2 : arithmétique de pointeurs
for (int *ptr = tab; ptr < tab + taille; ptr++) {
    printf("%d ", *ptr);
}

// Méthode 3 : pointeur avec indexation
int *ptr = tab;
for (int i = 0; i < taille; i++) {
    printf("%d ", ptr[i]);
}
```

### 10.3 Tableau de pointeurs
```c
// Tableau de pointeurs vers int
int a = 10, b = 20, c = 30;
int *tab_ptr[3] = {&a, &b, &c};

// Accès
printf("%d\n", *tab_ptr[0]);  // 10
printf("%d\n", *tab_ptr[1]);  // 20

// Tableau de chaînes
char *jours[] = {
    "Lundi",
    "Mardi",
    "Mercredi",
    "Jeudi",
    "Vendredi"
};

for (int i = 0; i < 5; i++) {
    printf("%s\n", jours[i]);
}
```

### 10.4 Tableaux multidimensionnels et pointeurs
```c
int matrice[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};

// Pointeur vers ligne (tableau de 4 int)
int (*p_ligne)[4] = matrice;

// Accès
printf("%d\n", p_ligne[1][2]);  // 7
printf("%d\n", (*(p_ligne+1))[2]);  // 7

// Parcours avec pointeur
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
        printf("%d ", (*(matrice + i))[j]);
    }
    printf("\n");
}
```

---

## 11. Pointeurs et chaînes

### 11.1 Chaînes avec pointeurs
```c
// Chaîne littérale (constante)
char *str1 = "Bonjour";  // En mémoire read-only
// str1[0] = 'b';  // ERREUR : segmentation fault

// Tableau de caractères (modifiable)
char str2[] = "Bonjour";
str2[0] = 'b';  // OK : "bonjour"

// Différence
printf("sizeof(str1) : %zu\n", sizeof(str1));  // Taille d'un pointeur (8)
printf("sizeof(str2) : %zu\n", sizeof(str2));  // Taille du tableau (8)
```

### 11.2 Parcours de chaînes avec pointeurs
```c
char *texte = "Python";

// Méthode 1
for (int i = 0; texte[i] != '\0'; i++) {
    printf("%c ", texte[i]);
}

// Méthode 2 (avec pointeur)
for (char *p = texte; *p != '\0'; p++) {
    printf("%c ", *p);
}

// Méthode 3 (while)
char *p = texte;
while (*p) {  // *p != '\0'
    printf("%c ", *p);
    p++;
}
```

### 11.3 Fonctions avec chaînes et pointeurs
```c
// Copie de chaîne
void copier(char *dest, const char *src) {
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
}

// Longueur
int longueur(const char *str) {
    int len = 0;
    while (*str++) len++;
    return len;
}

// Concaténation
void concatener(char *dest, const char *src) {
    while (*dest) dest++;  // Aller à la fin
    while ((*dest++ = *src++));  // Copier
}

// Comparaison
int comparer(const char *s1, const char *s2) {
    while (*s1 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
```

### 11.4 Tableau de chaînes avec pointeurs
```c
// Version 1 : Tableau de pointeurs
char *fruits[] = {
    "Pomme",
    "Banane",
    "Orange",
    "Kiwi"
};

int nb_fruits = sizeof(fruits) / sizeof(fruits[0]);

for (int i = 0; i < nb_fruits; i++) {
    printf("%s\n", fruits[i]);
}

// Version 2 : Tableau 2D
char fruits2[][10] = {
    "Pomme",
    "Banane",
    "Orange"
};
```

---

## 12. Pointeurs de pointeurs

### 12.1 Bases
```c
int x = 42;
int *ptr = &x;       // Pointeur vers int
int **pptr = &ptr;   // Pointeur vers pointeur vers int

printf("Valeur de x : %d\n", x);
printf("Via ptr : %d\n", *ptr);
printf("Via pptr : %d\n", **pptr);

// Modification
**pptr = 100;  // x devient 100
```

### 12.2 Tableaux de chaînes
```c
char *mots[] = {"Bonjour", "le", "monde"};
char **p = mots;

// Accès
printf("%s\n", *p);      // "Bonjour"
printf("%s\n", *(p+1));  // "le"
printf("%c\n", **p);     // 'B'
printf("%c\n", *(*p+1)); // 'o'

// Parcours
for (int i = 0; i < 3; i++) {
    printf("%s ", *(p+i));
}
```

### 12.3 Matrices dynamiques
```c
#include <stdlib.h>

int lignes = 3, cols = 4;

// Allocation matrice dynamique
int **matrice = malloc(lignes * sizeof(int*));
for (int i = 0; i < lignes; i++) {
    matrice[i] = malloc(cols * sizeof(int));
}

// Remplissage
for (int i = 0; i < lignes; i++) {
    for (int j = 0; j < cols; j++) {
        matrice[i][j] = i * cols + j;
    }
}

// Libération
for (int i = 0; i < lignes; i++) {
    free(matrice[i]);
}
free(matrice);
```

### 12.4 Fonction modifiant un pointeur
```c
void allouer_memoire(int **ptr, int taille) {
    *ptr = malloc(taille * sizeof(int));
}

int main() {
    int *tableau = NULL;
    allouer_memoire(&tableau, 10);
    
    // Utiliser tableau
    for (int i = 0; i < 10; i++) {
        tableau[i] = i * 2;
    }
    
    free(tableau);
    return 0;
}
```

---

## 13. Allocation dynamique

### 13.1 malloc
```c
#include <stdlib.h>

// Allouer un entier
int *ptr = (int*)malloc(sizeof(int));
if (ptr == NULL) {
    printf("Erreur d'allocation\n");
    return 1;
}
*ptr = 42;

// Allouer un tableau
int *tab = (int*)malloc(10 * sizeof(int));
for (int i = 0; i < 10; i++) {
    tab[i] = i;
}

// Libérer
free(ptr);
free(tab);
```

### 13.2 calloc
```c
// Alloue et initialise à zéro
int *tab = (int*)calloc(10, sizeof(int));  // 10 int à 0

// Équivalent à
int *tab2 = (int*)malloc(10 * sizeof(int));
memset(tab2, 0, 10 * sizeof(int));

free(tab);
free(tab2);
```

### 13.3 realloc
```c
int *tab = (int*)malloc(5 * sizeof(int));

// Remplir
for (int i = 0; i < 5; i++) {
    tab[i] = i;
}

// Redimensionner
tab = (int*)realloc(tab, 10 * sizeof(int));
if (tab == NULL) {
    printf("Erreur de réallocation\n");
    return 1;
}

// Nouveaux éléments
for (int i = 5; i < 10; i++) {
    tab[i] = i;
}

free(tab);
```

### 13.4 Bonnes pratiques
```c
// Toujours vérifier malloc
int *ptr = (int*)malloc(sizeof(int));
if (ptr == NULL) {
    fprintf(stderr, "Erreur d'allocation\n");
    exit(EXIT_FAILURE);
}

// Toujours libérer
free(ptr);
ptr = NULL;  // Éviter les pointeurs pendants

// Ne pas libérer deux fois
// free(ptr);  // ERREUR si déjà libéré

// Vérifier avant realloc
int *temp = realloc(ptr, new_size);
if (temp == NULL) {
    free(ptr);  // Libérer l'ancien
    return 1;
}
ptr = temp;
```

---

## 14. Structures (struct)

### 14.1 Définition et utilisation
```c
// Définition
struct Point {
    int x;
    int y;
};

// Déclaration
struct Point p1;
p1.x = 10;
p1.y = 20;

// Initialisation
struct Point p2 = {5, 15};

// Affichage
printf("Point : (%d, %d)\n", p2.x, p2.y);
```

### 14.2 Structure avec typedef
```c
typedef struct {
    char nom[50];
    int age;
    float note;
} Etudiant;

// Utilisation simplifiée
Etudiant e1;
strcpy(e1.nom, "Alice");
e1.age = 20;
e1.note = 15.5;

// Initialisation
Etudiant e2 = {"Bob", 22, 14.0};
```

### 14.3 Structures imbriquées
```c
typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct {
    char nom[50];
    Date naissance;
    float salaire;
} Employe;

// Utilisation
Employe emp;
strcpy(emp.nom, "Charlie");
emp.naissance.jour = 15;
emp.naissance.mois = 6;
emp.naissance.annee = 1990;
emp.salaire = 3000.0;

printf("%s né le %d/%d/%d\n", 
       emp.nom, 
       emp.naissance.jour, 
       emp.naissance.mois, 
       emp.naissance.annee);
```

### 14.4 Pointeurs vers structures
```c
typedef struct {
    int x;
    int y;
} Point;

Point p = {10, 20};
Point *ptr = &p;

// Accès avec pointeur (deux méthodes)
printf("x = %d\n", (*ptr).x);  // Méthode 1
printf("y = %d\n", ptr->y);    // Méthode 2 (préférée)

// Modification
ptr->x = 30;
ptr->y = 40;
```

### 14.5 Tableaux de structures
```c
typedef struct {
    char nom[50];
    int age;
} Personne;

Personne personnes[3] = {
    {"Alice", 25},
    {"Bob", 30},
    {"Charlie", 28}
};

// Parcours
for (int i = 0; i < 3; i++) {
    printf("%s a %d ans\n", personnes[i].nom, personnes[i].age);
}
```

### 14.6 Structures auto-référencées
```c
// Liste chaînée
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *creer_node(int valeur) {
    Node *nouveau = (Node*)malloc(sizeof(Node));
    nouveau->data = valeur;
    nouveau->next = NULL;
    return nouveau;
}

// Utilisation
Node *tete = creer_node(10);
tete->next = creer_node(20);
tete->next->next = creer_node(30);
```

### 14.7 Fonctions avec structures
```c
typedef struct {
    int x;
    int y;
} Point;

// Passage par valeur (copie)
void afficher_point(Point p) {
    printf("(%d, %d)\n", p.x, p.y);
}

// Passage par référence (pointeur)
void deplacer_point(Point *p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}

// Retour de structure
Point creer_point(int x, int y) {
    Point p = {x, y};
    return p;
}

int main() {
    Point p1 = {10, 20};
    afficher_point(p1);
    deplacer_point(&p1, 5, 10);
    afficher_point(p1);  // (15, 30)
    return 0;
}
```

---

## 15. Unions

### 15.1 Définition et utilisation
```c
// Union : partage la même mémoire
union Data {
    int i;
    float f;
    char c;
};

union Data d;

// Un seul membre actif à la fois
d.i = 10;
printf("i = %d\n", d.i);

d.f = 3.14;
printf("f = %f\n", d.f);
// d.i n'est plus valide maintenant

d.c = 'A';
printf("c = %c\n", d.c);
```

### 15.2 Taille d'une union
```c
union Data {
    int i;       // 4 octets
    float f;     // 4 octets
    double d;    // 8 octets
    char c;      // 1 octet
};

// Taille = taille du plus grand membre
printf("Taille : %zu octets\n", sizeof(union Data));  // 8
```

### 15.3 Union avec typedef
```c
typedef union {
    int entier;
    float reel;
    char caractere;
} Valeur;

Valeur v;
v.entier = 42;
v.reel = 3.14;  // écrase v.entier
```

### 15.4 Union avec structure (type tag)
```c
typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR
} TypeDonnee;

typedef struct {
    TypeDonnee type;
    union {
        int i;
        float f;
        char c;
    } valeur;
} Variable;

void afficher_variable(Variable v) {
    switch (v.type) {
        case TYPE_INT:
            printf("int: %d\n", v.valeur.i);
            break;
        case TYPE_FLOAT:
            printf("float: %f\n", v.valeur.f);
            break;
        case TYPE_CHAR:
            printf("char: %c\n", v.valeur.c);
            break;
    }
}

int main() {
    Variable v1 = {TYPE_INT, .valeur.i = 42};
    Variable v2 = {TYPE_FLOAT, .valeur.f = 3.14};
    
    afficher_variable(v1);
    afficher_variable(v2);
    
    return 0;
}
```

---

## 16. Énumérations (enum)

### 16.1 Définition
```c
// Définition simple
enum Jour {
    LUNDI,      // 0
    MARDI,      // 1
    MERCREDI,   // 2
    JEUDI,      // 3
    VENDREDI,   // 4
    SAMEDI,     // 5
    DIMANCHE    // 6
};

enum Jour aujourd_hui = LUNDI;

// Avec valeurs personnalisées
enum Mois {
    JANVIER = 1,
    FEVRIER,    // 2
    MARS,       // 3
    AVRIL,      // 4
    MAI,        // 5
    JUIN,       // 6
    JUILLET,    // 7
    AOUT,       // 8
    SEPTEMBRE,  // 9
    OCTOBRE,    // 10
    NOVEMBRE,   // 11
    DECEMBRE    // 12
};
```

### 16.2 Enum avec typedef
```c
typedef enum {
    ROUGE,
    VERT,
    BLEU
} Couleur;

Couleur c = ROUGE;

// Utilisation dans switch
switch (c) {
    case ROUGE:
        printf("Rouge\n");
        break;
    case VERT:
        printf("Vert\n");
        break;
    case BLEU:
        printf("Bleu\n");
        break;
}
```

### 16.3 Enum comme flags
```c
typedef enum {
    LECTURE   = 1,    // 0001
    ECRITURE  = 2,    // 0010
    EXECUTION = 4     // 0100
} Permission;

// Combinaison avec OR bit à bit
int droits = LECTURE | ECRITURE;  // 0011 = 3

// Vérification avec AND
if (droits & LECTURE) {
    printf("Lecture autorisée\n");
}

if (droits & ECRITURE) {
    printf("Écriture autorisée\n");
}

if (!(droits & EXECUTION)) {
    printf("Exécution non autorisée\n");
}
```

---

## 17. typedef

### 17.1 Alias de types de base
```c
typedef unsigned int uint;
typedef unsigned char byte;
typedef long long int64;

uint x = 42;
byte b = 255;
int64 grand_nombre = 9999999999LL;
```

### 17.2 Typedef avec pointeurs
```c
typedef int* IntPtr;

IntPtr p1, p2;  // Les deux sont des int*

// Sans typedef
int *p3, p4;    // p3 est int*, p4 est int
```

### 17.3 Typedef avec tableaux
```c
typedef int Tableau10[10];

Tableau10 tab;  // int tab[10]
tab[0] = 42;
```

### 17.4 Typedef avec fonctions
```c
// Type fonction : int(int, int)
typedef int (*Operation)(int, int);

int addition(int a, int b) { return a + b; }
int multiplication(int a, int b) { return a * b; }

int main() {
    Operation op;
    
    op = addition;
    printf("5 + 3 = %d\n", op(5, 3));
    
    op = multiplication;
    printf("5 * 3 = %d\n", op(5, 3));
    
    return 0;
}
```

### 17.5 Typedef avec structures
```c
// Ancien style
typedef struct Point {
    int x;
    int y;
} Point;

// Style moderne (anonyme)
typedef struct {
    int x;
    int y;
} Point;

Point p = {10, 20};
```

---

## 18. Pointeurs de fonctions

### 18.1 Déclaration et utilisation
```c
// Fonction simple
int addition(int a, int b) {
    return a + b;
}

int main() {
    // Déclaration pointeur de fonction
    int (*ptr_func)(int, int);
    
    // Affectation
    ptr_func = addition;
    
    // Appel
    int resultat = ptr_func(5, 3);  // 8
    printf("Résultat : %d\n", resultat);
    
    // Appel alternatif
    resultat = (*ptr_func)(5, 3);
    
    return 0;
}
```

### 18.2 Tableau de pointeurs de fonctions
```c
int addition(int a, int b) { return a + b; }
int soustraction(int a, int b) { return a - b; }
int multiplication(int a, int b) { return a * b; }
int division(int a, int b) { return b != 0 ? a / b : 0; }

int main() {
    // Tableau de pointeurs de fonctions
    int (*operations[4])(int, int) = {
        addition,
        soustraction,
        multiplication,
        division
    };
    
    char *symboles[] = {"+", "-", "*", "/"};
    
    for (int i = 0; i < 4; i++) {
        printf("10 %s 5 = %d\n", symboles[i], operations[i](10, 5));
    }
    
    return 0;
}
```

### 18.3 Callback (fonction de rappel)
```c
typedef int (*Comparateur)(int, int);

int croissant(int a, int b) { return a - b; }
int decroissant(int a, int b) { return b - a; }

void trier(int tab[], int taille, Comparateur cmp) {
    for (int i = 0; i < taille - 1; i++) {
        for (int j = 0; j < taille - i - 1; j++) {
            if (cmp(tab[j], tab[j + 1]) > 0) {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

int main() {
    int nombres[] = {5, 2, 8, 1, 9};
    int taille = 5;
    
    trier(nombres, taille, croissant);
    // nombres = {1, 2, 5, 8, 9}
    
    trier(nombres, taille, decroissant);
    // nombres = {9, 8, 5, 2, 1}
    
    return 0;
}
```

### 18.4 Pointeurs de fonctions en argument
```c
void appliquer(int tab[], int taille, int (*func)(int)) {
    for (int i = 0; i < taille; i++) {
        tab[i] = func(tab[i]);
    }
}

int carre(int x) { return x * x; }
int double_valeur(int x) { return x * 2; }

int main() {
    int nombres[] = {1, 2, 3, 4, 5};
    
    appliquer(nombres, 5, carre);
    // nombres = {1, 4, 9, 16, 25}
    
    appliquer(nombres, 5, double_valeur);
    // nombres = {2, 8, 18, 32, 50}
    
    return 0;
}
```

---

## 19. Fichiers

### 19.1 Ouverture et fermeture
```c
#include <stdio.h>

FILE *fichier;

// Modes d'ouverture
fichier = fopen("data.txt", "r");   // Lecture
fichier = fopen("data.txt", "w");   // Écriture (écrase)
fichier = fopen("data.txt", "a");   // Ajout
fichier = fopen("data.txt", "r+");  // Lecture + écriture
fichier = fopen("data.txt", "w+");  // Écriture + lecture
fichier = fopen("data.txt", "a+");  // Ajout + lecture

// Vérifier ouverture
if (fichier == NULL) {
    perror("Erreur d'ouverture");
    return 1;
}

// Fermeture
fclose(fichier);
```

### 19.2 Lecture
```c
FILE *f = fopen("nombres.txt", "r");

// Lire caractère par caractère
int c;
while ((c = fgetc(f)) != EOF) {
    printf("%c", c);
}

// Lire ligne par ligne
char ligne[100];
while (fgets(ligne, 100, f) != NULL) {
    printf("%s", ligne);
}

// Lire formaté
int x, y;
fscanf(f, "%d %d", &x, &y);

fclose(f);
```

### 19.3 Écriture
```c
FILE *f = fopen("resultat.txt", "w");

// Écrire caractère
fputc('A', f);

// Écrire chaîne
fputs("Bonjour\n", f);

// Écrire formaté
int x = 42;
float y = 3.14;
fprintf(f, "x = %d, y = %.2f\n", x, y);

fclose(f);
```

### 19.4 Lecture/Écriture binaire
```c
// Écriture binaire
int nombres[] = {1, 2, 3, 4, 5};
FILE *f = fopen("data.bin", "wb");
fwrite(nombres, sizeof(int), 5, f);
fclose(f);

// Lecture binaire
int tab[5];
f = fopen("data.bin", "rb");
fread(tab, sizeof(int), 5, f);
fclose(f);
```

### 19.5 Position dans le fichier
```c
FILE *f = fopen("data.txt", "r");

// Position actuelle
long pos = ftell(f);

// Aller au début
rewind(f);

// Aller à une position
fseek(f, 10, SEEK_SET);  // 10 octets depuis le début
fseek(f, -5, SEEK_CUR);  // 5 octets en arrière
fseek(f, 0, SEEK_END);   // Fin du fichier

fclose(f);
```

---

## 20. Préprocesseur

### 20.1 Directives #define
```c
// Constantes
#define PI 3.14159
#define MAX 100

// Macros simples
#define CARRE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
    printf("PI = %f\n", PI);
    printf("Carré de 5 = %d\n", CARRE(5));
    printf("Max(10, 20) = %d\n", MAX(10, 20));
    return 0;
}
```

### 20.2 Inclusion conditionnelle
```c
// Éviter inclusion multiple
#ifndef MON_HEADER_H
#define MON_HEADER_H

// Code du header

#endif

// Ou avec pragma once (moderne)
#pragma once
```

### 20.3 Compilation conditionnelle
```c
#define DEBUG 1

#ifdef DEBUG
    printf("Mode debug activé\n");
#endif

#ifndef PRODUCTION
    printf("Pas en production\n");
#endif

#if DEBUG == 1
    printf("Debug niveau 1\n");
#elif DEBUG == 2
    printf("Debug niveau 2\n");
#else
    printf("Pas de debug\n");
#endif
```

### 20.4 Macros prédéfinies
```c
printf("Fichier : %s\n", __FILE__);
printf("Ligne : %d\n", __LINE__);
printf("Date : %s\n", __DATE__);
printf("Heure : %s\n", __TIME__);
printf("Fonction : %s\n", __func__);
```

---

## 21. Algorithmes de tri

### 21.1 Tri à bulles (Bubble Sort)
```c
void tri_bulles(int tab[], int taille) {
    for (int i = 0; i < taille - 1; i++) {
        for (int j = 0; j < taille - i - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                // Échanger
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

// Utilisation
int nombres[] = {64, 34, 25, 12, 22, 11, 90};
tri_bulles(nombres, 7);
```

### 21.2 Tri par sélection (Selection Sort)
```c
void tri_selection(int tab[], int taille) {
    for (int i = 0; i < taille - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < taille; j++) {
            if (tab[j] < tab[min_idx]) {
                min_idx = j;
            }
        }
        // Échanger
        if (min_idx != i) {
            int temp = tab[i];
            tab[i] = tab[min_idx];
            tab[min_idx] = temp;
        }
    }
}
```

### 21.3 Tri par insertion (Insertion Sort)
```c
void tri_insertion(int tab[], int taille) {
    for (int i = 1; i < taille; i++) {
        int cle = tab[i];
        int j = i - 1;
        
        while (j >= 0 && tab[j] > cle) {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = cle;
    }
}
```

### 21.4 Tri rapide (Quick Sort)
```c
void echanger(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int tab[], int bas, int haut) {
    int pivot = tab[haut];
    int i = bas - 1;
    
    for (int j = bas; j < haut; j++) {
        if (tab[j] < pivot) {
            i++;
            echanger(&tab[i], &tab[j]);
        }
    }
    echanger(&tab[i + 1], &tab[haut]);
    return i + 1;
}

void tri_rapide(int tab[], int bas, int haut) {
    if (bas < haut) {
        int pi = partition(tab, bas, haut);
        tri_rapide(tab, bas, pi - 1);
        tri_rapide(tab, pi + 1, haut);
    }
}

// Utilisation
int nombres[] = {10, 7, 8, 9, 1, 5};
tri_rapide(nombres, 0, 5);
```

### 21.5 Tri fusion (Merge Sort)
```c
void fusionner(int tab[], int gauche, int milieu, int droite) {
    int n1 = milieu - gauche + 1;
    int n2 = droite - milieu;
    
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; i++)
        L[i] = tab[gauche + i];
    for (int j = 0; j < n2; j++)
        R[j] = tab[milieu + 1 + j];
    
    int i = 0, j = 0, k = gauche;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            tab[k++] = L[i++];
        } else {
            tab[k++] = R[j++];
        }
    }
    
    while (i < n1) tab[k++] = L[i++];
    while (j < n2) tab[k++] = R[j++];
    
    free(L);
    free(R);
}

void tri_fusion(int tab[], int gauche, int droite) {
    if (gauche < droite) {
        int milieu = gauche + (droite - gauche) / 2;
        tri_fusion(tab, gauche, milieu);
        tri_fusion(tab, milieu + 1, droite);
        fusionner(tab, gauche, milieu, droite);
    }
}

// Utilisation
int nombres[] = {38, 27, 43, 3, 9, 82, 10};
tri_fusion(nombres, 0, 6);
```

### 21.6 Tri avec qsort (bibliothèque)
```c
#include <stdlib.h>

int comparer(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int nombres[] = {5, 2, 8, 1, 9};
    int taille = sizeof(nombres) / sizeof(nombres[0]);
    
    qsort(nombres, taille, sizeof(int), comparer);
    
    // Pour ordre décroissant
    qsort(nombres, taille, sizeof(int), 
          (int(*)(const void*, const void*))
          [](const void *a, const void *b) {
              return *(int*)b - *(int*)a;
          });
    
    return 0;
}
```

### 21.7 Comparaison des tris

| Algorithme | Complexité moyenne | Complexité pire cas | Espace | Stable |
|------------|-------------------|---------------------|--------|--------|
| Tri à bulles | O(n²) | O(n²) | O(1) | Oui |
| Tri par sélection | O(n²) | O(n²) | O(1) | Non |
| Tri par insertion | O(n²) | O(n²) | O(1) | Oui |
| Tri rapide | O(n log n) | O(n²) | O(log n) | Non |
| Tri fusion | O(n log n) | O(n log n) | O(n) | Oui |
| qsort | O(n log n) | O(n log n) | O(log n) | Non |

---

## 📌 Bonnes pratiques en C

### Conventions de nommage
```c
#define MAX_SIZE 100        // Constantes : MAJUSCULES

int nombre_etudiants;       // Variables : snake_case
float moyenne_classe;

void calculer_moyenne();    // Fonctions : snake_case

typedef struct {            // Structures : PascalCase
    int id;
    char nom[50];
} Etudiant;
```

### Gestion des erreurs
```c
#include <errno.h>
#include <string.h>

FILE *f = fopen("data.txt", "r");
if (f == NULL) {
    fprintf(stderr, "Erreur : %s\n", strerror(errno));
    return EXIT_FAILURE;
}

int *ptr = (int*)malloc(100 * sizeof(int));
if (ptr == NULL) {
    fprintf(stderr, "Erreur d'allocation mémoire\n");
    return EXIT_FAILURE;
}

free(ptr);
fclose(f);
```

### Protection contre les fuites mémoire
```c
void traiter_donnees() {
    int *data = (int*)malloc(100 * sizeof(int));
    if (data == NULL) return;
    
    // Traitement
    
    // TOUJOURS libérer
    free(data);
    data = NULL;
}

// Avec plusieurs allocations
void fonction() {
    int *a = malloc(10 * sizeof(int));
    int *b = malloc(20 * sizeof(int));
    
    if (a == NULL || b == NULL) {
        free(a);  // Libérer ce qui a été alloué
        free(b);
        return;
    }
    
    // Traitement
    
    free(a);
    free(b);
}
```

### Headers guards
```c
// mon_header.h
#ifndef MON_HEADER_H
#define MON_HEADER_H

// Déclarations

#endif

// Ou (C99+)
#pragma once
```

---

## 🎯 Exercices recommandés

**Niveau débutant :**
1. Calculatrice avec switch
2. Manipulation de tableaux
3. Recherche dans un tableau

**Niveau intermédiaire :**
1. Gestion de chaînes (copie, comparaison)
2. Structures pour gérer des contacts
3. Listes chaînées simples

**Niveau avancé :**
1. Implémentation de tous les tris
2. Arbres binaires avec structures
3. Gestionnaire de mémoire personnalisé

---

## 📚 Ressources

- Documentation C : https://en.cppreference.com/w/c
- Cours C : https://www.learn-c.org/
- Exercices : https://www.hackerrank.com/domains/c

---

**🔷 Bon apprentissage du C !**
