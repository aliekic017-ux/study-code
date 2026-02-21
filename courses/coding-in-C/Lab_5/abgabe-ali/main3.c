#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main ()

{
    srand(time(NULL));
    int variablen [10] = {0};
    

    int *p_variablen = variablen;   // Pointer p_variablen auf das erste Element des Arrays variablen

    *(p_variablen + 2) = 1;
    *(p_variablen + 4) = 1;
    *(p_variablen + 6) = 1;

    int temporär [10] = {0};     // Definition eines weiteren (temporären) Arrays
    int *p_temporär = temporär;  // Pointer auf den temporären Arrays mit Datentyp int

        printf("The time 0: ");  // Ausgabe der time0: 0 0 1 0 1 0 1 0 0 0 
    for (int i = 0; i < 10; i++)
    {
        printf(" %d ", *(p_variablen + i));
    }
    printf("\n");

    int steps = 10 ;

for (int t = 0; t < steps; t++)
{

    for (int j = 0; j < 10; j++)     // temporäre Pointer auf 0 auf jedem einzelnen Element resetten
    {
        *(p_temporär+j) = 0;        // sonst mit Werten behaftet aufgrund des Schleifendurchgangs
    } 
    
    // Suchen der 1 im aktuellen Pointer p_variablen
    for (int k = 0; k < 10; k++)
    {
        if (*(p_variablen + k ) == 1)
        {
            int richtung = rand () %2;  // entweder 1 oder 0 ; bei 0 Bewegung nach links bei 1 Bewegung nach rechts
            int neuePos; 

            if (richtung == 1)    // neue Position 
            {
                neuePos = k + 1;
                
            }
            else {

                neuePos = k - 1;
                
            }

            // Grenzen definieren 0 - 9 --> das kein Wert out of range springen kann 
            if (neuePos < 0)
            {
                neuePos = 0;
            }
            if (neuePos > 9)
            {
                neuePos = 9;
            }
            
            
           if (temporär[neuePos]== 0) // Wenn an der neuen Stelle, eine 0 ist dann füge eine 1 ein wenn da schon eine 1 ist dann schreibe 0 --> Kollision erkannt
           {
             temporär[neuePos] = 1; // an neuer Stelle war keine ,,1" --> 1 wird reingeschrieben 
                
           }
           else
           {
            temporär[neuePos] =0; // an der neuen Stellen war schon eine ,,1" --> 0 wird reingeschrieben
            printf("Collision on place %d \n", neuePos); // --> Ausgabe: an der Stelle wurde eine Kollision erkannt
           }
           
            
        }
        
    }
    for (int b = 0; b < 10; b++)    // Initialisierung des Pointers mit den Werten des temp. Pointers
    {
        variablen[b] = temporär [b];
    }
    printf("Time %d: ", t + 1);  // print der einzelnen time zeilen mit den Zahlenfolgen
    for (int i = 0; i < 10; i++) {
        printf("%d ", variablen[i]);
    }
    printf("\n");
    
}

    return 0;
}