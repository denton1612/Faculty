#include <stdio.h>

float patrat(float x)
    /*
     * Calculeaza patratul unui nr real
     * param x: nr real (float)
     * return: patratul nr (float)
     */
{
    return x * x;
}

float putere(float x, int n)
    /*
     * Calculeaza x^n folosind divide et conquer
     * param x: nr real (float)
     * param n: nr natural
     * return: x^n (float)
     */
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    else if (n % 2 == 0)
        return patrat(putere(x, n / 2));
    else
        return patrat(putere(x, n / 2)) * x;
}

int main()
{
    /*
     * Functia main citeste un numar real si un numar natural si afiseaza x^n (cat timp n != -1)
     */
    int n;
    float x, rez;
    printf("Introduceti un numar real: \n");
    scanf("%f", &x);
    printf("Introduceti un exponent natural: \n");
    scanf("%u", &n);
    while (n != -1)
    {
        rez = putere(x, n);
        printf("Rezultatul este: %f \n", rez);
        printf("Introduceti un numar real: \n");
        scanf("%f", &x);
        printf("Introduceti un exponent natural: \n");
        scanf("%u", &n);
    }
    return 0;
}
