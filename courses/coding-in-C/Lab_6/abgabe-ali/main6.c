#include <stdio.h>
#include <stdlib.h>

int main ()
{
    FILE* datei;
    char zeichen[20] = ; 

    datei = fopen("test.txt", "w");

    if (datei == 0)
    {
        printf("Fehler beim Öffnen der Datei");
    }

    fprintf(datei, zeichen)







    return 0;
}