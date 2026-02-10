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


    do{
    
    
    printf ("Gebe die erste Zahl ein: \n"); // Eingabe der ersten Zahl
     if (scanf(" %f", &zahl1) !=1) {

        printf("UNGÜLTIGE EINGBABE!! \n\n"); 
     }

    printf ("Gebe die zweite Zahl: \n"); // Eingabe der zweiten Zahl 
     if (scanf (" %f", &zahl2) !=1) { // Abfrage der Eingabe einer Zahlc

        printf("UNGÜLTIGE EINGABE!!\n\n"); // Error, wenn keine Zahl eingegeben wird
     }
    
     printf ("Gebe eines der 4 (+,-,*,/ ) erlaubten Rechenoperatoren ein: \n");
     scanf (" %c", &op);

     switch (op)
     {
     case '+':
        ergebis = zahl1 + zahl2; 
        printf ("Das Ergebnis von %.2f + %.2f betraegt: %.2f\n", zahl1, zahl2, ergebis);
        break;

     case '-':
        ergebis = zahl1 - zahl2;
        printf ("Das Ergebnis von %.2f - %.2f betraegt: %.2f\n", zahl1, zahl2, ergebis);
        break;

    case '*':
        ergebis = zahl1 * zahl2;
        printf ("Das Ergebnis von %.2f * %.2f betraegt: %.2f\n", zahl1, zahl2, ergebis);
        break;

    case '/':
      if (zahl2 == 0)
      {
         printf(" !!ERROR!! Division durch 0 nicht möglich.");
         return 1;

      }
      
        ergebis = zahl1 / zahl2;
        printf ("Das Ergebnis von %.2f / %.2f betraegt: %.2f\n", zahl1, zahl2, ergebis);
        

        break;
     default:
        printf ("!!ERROR!! Üngültiger Operator."); // Programmabbruch ; falscher Operator. 
        return 1;   


     }


    printf ("Soll eine neue Berechnung durchgeführt werden (ja / nein ) ? \n");  // ja --> erneute Berechnung möglich ; nein --> keine weitere neue Berechnung
    scanf (" %9s", weiter); 
    
} while (strcmp(weiter, "ja") == 0);  // String-Compare strcmp









    return 0;
}