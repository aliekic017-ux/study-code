#include <stdio.h>
#include <stdlib.h>

int main ()
{
    FILE* datei;
    char zeichen[120] = "ich habe keine Idee";  // schreibt das direkt in die Datei rein

    datei = fopen("test.txt", "w");

    if (datei == 0)
    {
        printf("Fehler beim Öffnen der Datei");
    }

    fputs(zeichen, datei);







    return 0;
}