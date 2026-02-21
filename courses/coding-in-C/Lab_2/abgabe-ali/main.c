#include <stdio.h> 
#include <string.h>


int main ()
{


    int groesse = 8;
    char reihen [] = {'A', 'B', 'C', 'D', 'E', 'F','G', 'H'};



    for (int i = groesse; i > 0; i--)
    {
        {
            for (int j = 0; j <= groesse ; j++)
            {
                printf("%d %c", i, reihen[j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    

    return 0;

}