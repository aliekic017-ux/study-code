#include <stdio.h>
#include <stdlib.h>

int main ()

{
    FILE* datei;
    char zeichen;

    datei = fopen("test.txt", "r");
    if (datei == 0)
    {
        printf("Fehler beim Öffnen der Datei\n");
        return 1;
    }

    while (fscanf(datei, "%c", &zeichen) != EOF)
    {
         printf("%c", zeichen);
    }


    return 0;
}