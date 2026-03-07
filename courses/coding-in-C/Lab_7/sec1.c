#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int *Eingabe = malloc(sizeof (*Eingabe));
    if (Eingabe == NULL)
    {
        printf("Speicherallokation fehlgeschlagen \n");
        return 1;
    }
    //free(Eingabe);

    printf("Geben Sie eine Zahl ein ");
    if (scanf("%d", Eingabe) != 1)
    {
        printf("Fehler bei dem Einlesen der Eingabe");
        return -1;

    }

    int *Speicher = calloc(*Eingabe, sizeof(*Speicher));
    if (Speicher == NULL)
    {
        printf("Speicherallokation fehlgeschlagen \n");
        return 1;
    }
    
    for (int i = 0; i < *Eingabe; i++)
    {
        Speicher[i] = i * i;
    }
    int *temp = realloc (Speicher, 2 * (*Eingabe) *sizeof(*temp));
    if (temp == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return 1;
    }
    
    Speicher = temp;

    for (int i = *Speicher; i < 2* *Speicher; i++)
    {
        Speicher[i] = i * i;
    }
    

    for (int i = 0; i < 2* *Eingabe; i++)
    {
        printf("%d", Speicher[i]);

    }
    

    
    
    free(Eingabe);
    free(Speicher); 

    

}