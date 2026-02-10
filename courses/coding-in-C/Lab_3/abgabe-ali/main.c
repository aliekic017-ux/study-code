#include <stdio.h> 
#include <string.h>


int main ()
{
    float zahl1;
    float zahl2;
    float ergebis;
    char op;
    char Operatoren [4] = {'+', '-', '*', '/'};
    char weiter [10];

    do {
    printf("Geben Sie die erste Zahl ein!! \n");
     if (scanf(" %f", &zahl1) !=1) {

        printf("Ungültige Eingabe.\n");
     }


    printf("Geben Sie die zweite Zahl ein!! \n");
     if (scanf(" %f", &zahl2) !=1){

        printf("Ungültige Eingabe. \n");
     }

    printf("Wählen Sie den gewünschten Operator aus \n");
    scanf(" %c", &op);
    /*{
        printf ("Ungueltige Eingabe \n");
    }; */
    

    if (op == '+') {  // Abgleich und Durchführung der 4. Operatoren

        ergebis = zahl1 + zahl2;
        printf ("Das Ergebnis von %.2f + %.2f betraegt: %.2f\n", zahl1, zahl2, ergebis);
    }
    else if (op == '-') {

        ergebis = zahl1 - zahl2;
        printf ("Das Ergebnis von %.2f - %.2f betraegt: %.2f\n", zahl1, zahl2, ergebis);
    }
    else if (op == '*')
    {
        ergebis = zahl1 * zahl2;
        printf ("Das Ergebnis von %.2f * %.2f betraegt: %.2f\n", zahl1, zahl2, ergebis);
    }
    else if (op == '/')
    { 
        if (zahl2 == 0) // Abfrage ob die Zahl 2 = 0 ist bei der Division.

        {
            printf("Division durch 0 nicht möglich.\n"); // Fehlermeldung wenn Zahl2 = 0 ist. Dass Division nicht möglich ist
                                                                //scanf(" %f", &zahl2); // Eingabe neuer 2.Zahl. Um Operation durchführen zu können.
            return 1;
        }
        
        
        ergebis = zahl1 / zahl2;
        printf ("Das Ergbnis von %.2f / %.2f betraegt: %.2f\n", zahl1, zahl2 ,ergebis);
    }
    else {
        printf("!!ERROR!! \t\tUnerlaubte Zahl bzw. Operator. \n ");
        //scanf(" %c", &op);
    
    
    }

    printf ("Soll eine neue Berechnung durchgeführt werden (ja / nein ) ? \n");
    scanf (" %9s", weiter); 
    
} while (strcmp(weiter, "ja") == 0);

    return 0;


}  

