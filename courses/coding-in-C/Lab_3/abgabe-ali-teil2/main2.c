#include <stdio.h>
#include <stdlib.h>

int addieren (int a , int b) 
{
    return a + b;
}
int subtrahiere (int a , int b)
{
    return a - b;
}
int multipliziere (int a , int b)
{
    return a * b;
}
int dividiere (int a , int b)
{
    return a / b; 
}

int main ()

{
    int ergebnis;
    float zahl1 = 0.0;
    float zahl2 = 0.0;
    char operation;


    printf("Bitte geben Sie die erste Zahl der mathematischen Operation ein: \n");
    if (scanf("%f", &zahl1) != 1)
    {
        printf("Ungültige Eingabe\n");
        return 1;
    }

    printf("Bitte geben Sie die zweite Zahl der mathematischen Operation ein: \n");
    if (scanf("%f", &zahl2) != 1)
    {
        printf("Ungültige Eingabe \n");
        return 1;
    }

    printf("Wählen Sie eine der 4 mathematischen Operationen aus ( + ; - ; * ; /): \n");
    scanf(" %c", &operation);

    switch (operation)
    {
        case '+':
        ergebnis = addieren (zahl1 , zahl2);
        break;

        case '-':
        ergebnis = subtrahiere (zahl1 , zahl2);
        break;

        case '*':
        ergebnis = multipliziere (zahl1 , zahl2);
        break;

        case '/':
        ergebnis = dividiere (zahl1 , zahl2);
        break;

        default:
        break;
    }
    printf("Das Ergebnis der Berechnung ist: %d", ergebnis);

    return 0; 

}
