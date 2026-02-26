#include <stdio.h>
#include <stdlib.h>

int main ()
{
    FILE* datei;
    char satz[150];

    datei = fopen("test.txt", "r");

    if(datei == NULL)
    {
        printf("Feler beim Öffnen der Datei");
        return 1; 

    }

    while(fgets(satz, sizeof(satz),datei) != NULL)
    {
        printf("%s", satz);
    
    }

    fclose("")


















   /* FILE* datei;
    char satz [150];

    datei = fopen("test.txt", "r");

    if (datei == NULL)
    {
        printf("Fehler beim Öffnen der Datei");
        return 1;
    }

    while (fgets(satz, sizeof(satz), datei) != NULL)
    {
        printf("%s", satz);

    }
 
    if*/




    return 0;
}