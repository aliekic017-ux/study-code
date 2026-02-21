#include <stdio.h>
#include <string.h>

int main()
{
    float zahl1;
    float zahl2;
    char operator;
    float ergebnis;
    
    printf("Bitte gebe die erste Zahl ein:   ");
     if (scanf(" %f", &zahl1) !=1)
        {
            printf("Ungültige Eingabe");
            return 1;
        }

    printf ("Bitte gebe die zweite Zahl ein:    ");
    if (scanf(" %f", &zahl2)!= 1)
    {
        printf("Ungültige Eingabe");
        return 1;
    }

    printf ("Bitte wähle eine der vier arithmetischen Operationen ('+', '-', '*', '/') aus:     ");
    if (scanf(" %c", &operator)!=1)
    {
        printf("Ungültige Eingabe");
        return 1;

    }

    if (operator == '+') 
    {
        ergebnis = zahl1 + zahl2;
    }
    else if (operator == '-')
    {
        ergebnis = zahl1 - zahl2;
    }
    else if (operator == '*')
    {
        ergebnis = zahl1 * zahl2;
    }
    else
    {
        if (zahl2 == 0)
        {
            printf (" Division durch 0 nicht möglich. Bitte führe die Berechnung erneut durch");
            return 1;
        }
    
        ergebnis = zahl1 / zahl2;
    }


printf("Das Ergebnis der mathematischen Berechnung betraegt:    %.2f", ergebnis);




return 0;
}