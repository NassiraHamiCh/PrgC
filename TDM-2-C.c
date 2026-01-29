#include <stdio.h>

// Exercice 1 : le carre d’un entier
int carre(int n) {
    return n * n;
}

// Exercice 2 : maxi de deux nombres
int max2(int a, int b) {
    //return (a > b) ? a : b;
    if a>b
         return  a
    else 
     return b
}

// Exercice 3 : pair/impair
int estPair(int n) {
    return (n % 2 == 0) ? 1 : 0;
}

// Exercice 4 : somme de deux nombres
int somme(int a, int b) {
    return a + b;
}

// Exercice 5 : table de multiplication
void table(int n) {
    for (int i = 1; i <= 10; i++)
        printf("%d x %d = %d\n", n, i, n * i);
}

// Exercice 6 : n!
int factorielle(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++)
        f *= i;
    return f;
}

// Exercice 7 : nombre premier
int estPremier(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= n/2; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

// Exercice 8 : somme des n premiers entiers
int sommeN(int n) {
    int s = 0;
    for (int i = 1; i <= n; i++)
        s += i;
    return s;
}

// Exercice 9 : puissance a^b
int puissance(int a, int b) {
    int res = 1;
    for (int i = 0; i < b; i++)
        res *= a;
    return res;
}

// Exercice 10 : suite de Fibonacci
void fibonacci(int n) {
    int a = 0, b = 1, c;
    for (int i = 1; i <= n; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}

// Exercice 11 : max de trois nombres
int max3(int a, int b, int c) {
    int m = a;
    if (b > m) m = b;
    if (c > m) m = c;
    return m;
}
// Exercice 12 : classification d'une note
void classification(float note) {
    if (note < 10)
        printf("Echec\n");
    else if (note < 12)
        printf("Passable\n");
    else if (note < 14)
        printf("Bien\n");
    else
        printf("Tres bien\n");
}

// Exercice 13 : moyenne de trois notes
float moyenne(float a, float b, float c) {
    return (a + b + c) / 3.0;
}

// Exercice 14 : Celsius → Fahrenheit
float toFahrenheit(float C) {
    return C * 9.0/5.0 + 32;
}

// Exercice 15 : nombre parfait
int estParfait(int n) {
    int somme = 0;
    for (int i = 1; i <= n/2; i++)
        if (n % i == 0)
            somme += i;

    return (somme == n);
}

int main() {
    printf("Carre(5) = %d\n", carre(5));
    printf("Max2(10, 7) = %d\n", max2(10,7));
    printf("Pair(4) = %d\n", estPair(4));
    printf("Somme(3,7) = %d\n", somme(3,7));

    printf("\nTable de 5:\n");
    table(5);

    printf("\nFactorielle(5) = %d\n", factorielle(5));
    printf("Premier(11) = %d\n", estPremier(11));
    printf("Somme 1..10 = %d\n", sommeN(10));
    printf("Puissance(2,5) = %d\n", puissance(2,5));

    printf("\nFibonacci(10) : ");
    fibonacci(10);

    printf("\nMax3(5, 9, 3) = %d\n", max3(5,9,3));

    printf("\nClassification de 13 : ");
    classification(13);

    printf("Moyenne(12, 14, 16) = %.2f\n", moyenne(12,14,16));
    printf("25C = %.2fF\n", toFahrenheit(25));
    printf("6 parfait ? %d\n", estParfait(6));

    return 0;
}