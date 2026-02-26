#include <stdio.h>
#include <stdlib.h>

int main ()
{
    FILE* datei;
    int zeichen = 'A'; 

    datei = fopen("test.txt", "w");

    if (datei == 0)
    {
        printf("Fehler beim Öffnen der Datei");
    }

    fputc(zeichen, datei);







    return 0;
}