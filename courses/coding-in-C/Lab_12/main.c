#include <stdio.h>
#include <string.h>
#include <assert.h>

void function_copy_line (char *quelldatei, char *zieldatei)

{
    FILE *daten = fopen (quelldatei, "r");
    FILE *ziel = fopen(zieldatei, "w");

    assert(daten != NULL);
    assert(ziel != NULL);

    char string [100];

    if (fgets(string, sizeof string, daten) != NULL)
    {
        int result = fputs(string, ziel);

        assert(result != EOF);
    }
    
    fclose (daten);
    fclose(ziel);

    
}