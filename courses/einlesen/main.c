#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    FILE *open = fopen("eingabe.txt", "r");
    FILE *ausgabe = fopen("ausgabe.txt", "w");

    if (open == NULL)
    {
        printf("Fehler beim Öffnen der Eingabedatei");
        return 1;
    }

    if (ausgabe == NULL)
    {
        printf("Fehler beim Öffnen der Ausgabedatei");
        fclose(open);
        return 1;
    }
    



    char info[100];

    while (fgets(info, sizeof info, open) != NULL)
    {
        printf("%s", info);
        fputs(info, ausgabe);
    }

    fclose(open);
    fclose(ausgabe);

    return 0;

}