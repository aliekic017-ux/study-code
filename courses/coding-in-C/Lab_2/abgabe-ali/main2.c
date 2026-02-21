#include <stdio.h>

int main ()

{
    int groesse = 8;
    char felder [] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    // Buchstaben oberhalb des Schachbretts 
    printf("   ");
    for (int b = 0; b < groesse; b++)
    {
        printf (" %c  ", felder[b]);
    }
    printf("\n");

    
    for (int l = groesse; l > 0 ;l--)
    {
        printf("  ");
    
        for (int i = groesse; i > 0; i--)
        {
        printf("+---");
        }
        printf("+\n");
       
        
        printf("%d ", l);
        for (int k = 0; k < groesse; k++)
        {

            {   
        
                
                if ( ((k+ l ) % 2) == 0)
                {
                
                printf("|###");
                }
                else
                printf("|   " );
            
            
                
            }
        
        }
    
        printf("| %d\n", l);
        
        
        

    }
    printf ("  ");
    for (int c = 0; c < groesse ; c++)
    {
        printf("");
        printf("+---");
    }
    printf("+\n");
    
    printf(" ");
    for (int iu = 0; iu < groesse; iu++)
        {
            printf("   %c", felder[iu]);
        }

return 0;
}