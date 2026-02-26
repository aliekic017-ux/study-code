#include <stdio.h>
#include <stdlib.h>

int main ()
{
    FILE* datei;
    int zeichen;

    datei = fopen("test.txt", "r");

    if (datei == 0)
    {
        printf("Fehler beim Öffnen der Datei");
        return 1;
    }

   while ((zeichen = fgetc(datei)) !=EOF)
   {
    printf("%c", zeichen);
   }


    return 0;
}