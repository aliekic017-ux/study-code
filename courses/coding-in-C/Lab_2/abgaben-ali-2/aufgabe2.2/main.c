#include <stdio.h>

int main(void)
{
     int Spaltenanzahl = 8;
     char Reihe[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    
    printf(" ");
    for (int file = 0; file < Spaltenanzahl; file++)
    {
        printf("   %c", Reihe [file]);
    }
    printf("\n");

    for (int i = Spaltenanzahl; i > 0; i--)
    {
        
        printf("  +");
        for (int k = 0; k < Spaltenanzahl; k++)
        {
            printf("---+");
        }
        printf("\n");

        
        printf("%d ", i);
        for (int j = 1; j <= Spaltenanzahl; j++)
        {
            
            if (((j + i) % 2) > 0)
            {
                printf("|###");
            }
            else
            {
                printf("|   ");
            }
        }
        
        printf("| %d\n", i);
    }

    
    printf("  +");
    for (int k = 0; k < Spaltenanzahl; k++)
    {
        printf("---+");
    }
    printf("\n");

    
    printf(" ");
    for (int l = 0; l < Spaltenanzahl; l++)
    {
        printf("   %c", Reihe[l]);
    }
    printf("\n");

    return 0;
}
