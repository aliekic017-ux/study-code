#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main ()

{
    int zufall [10] = {0};
    int *p_zufall = zufall;
    int max = 0;
    srand(time(NULL));
    

    printf("Die Zufallszahlen lauten: \n ");

    for (int i = 0; i < 10; i++)
    {
         int zahl = rand () % 50;
         *(p_zufall + i) = zahl;


         printf("%d \n", *(p_zufall+i));


         
    
         if (*(p_zufall + i) > max)
         {
            max = *(p_zufall + i);
         }


        
    }

    printf("Die groesste Zahl ist: %d  ", max);
    


    return 0; 
}