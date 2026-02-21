#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main ()

{
    int Variablen[10];
    srand(time(NULL));
    int gerade_zahl;

    printf("Die Zufallszahlen sind: \n");

    for (int i = 0; i < 10; i++)
    {
        int zahl = rand() % 101;
        Variablen[i] = zahl;
        printf(" %d: ", Variablen[i]);
        

        if (zahl % 2 == 0)
        {
            printf("die Variable [%d] ist eine gerade Zahl\n", Variablen[i]);
            gerade_zahl += 1;
        }
        else 
        {
            printf("die Variable [%d] ist eine ungerade Zahl\n", Variablen[i]);
        }
        

    }
    printf(" Die Anzahl der geraden Zahlen betraegt: %d", gerade_zahl);
    

    return 0; 
    



}