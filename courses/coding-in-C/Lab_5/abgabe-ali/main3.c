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

    int temporär [10] = {0};     // Definition eines weiteren (temporären) pointers
    int *p_temporär = temporär;

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
        *(p_temporär+j) = 0;
    }
    
    // Suchen der 1 im aktuellen Pointer
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

            if (neuePos < 0)
            {
                neuePos = 0;
            }
            if (neuePos > 9)
            {
                neuePos = 9;
            }
            
            
           if (temporär[neuePos]== 0)
           {
             temporär[neuePos] = 1;
                
           }
           else
           {
            temporär[neuePos] =0;
            printf("Collision on index %d\n", neuePos);
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