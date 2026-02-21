#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main ()
{
    char c_palindrom [100];
    int i_AnzahlCharkette;
    int i;
    int i_istPalindrom= 1;

    printf("Enter a word (max. 100 characters): \t");
    fgets (c_palindrom, sizeof(c_palindrom), stdin);
    c_palindrom[strcspn(c_palindrom, "\n")] = '\0';

    i_AnzahlCharkette = strlen(c_palindrom);

    for ( i = 0; i < i_AnzahlCharkette/2; i++)
    {
        if (tolower(c_palindrom[i]) != tolower(c_palindrom[i_AnzahlCharkette-1-i]) )
        {
            i_istPalindrom =0;
            break;   
        }    
    }
    
    if (i_istPalindrom ==1 )
    {
        printf ("Your provided word %s is a palindrom", c_palindrom);
    }
    else
    {
       printf("Your provided word %s is not a palindrom", c_palindrom);
    }
    
    return 0;
}