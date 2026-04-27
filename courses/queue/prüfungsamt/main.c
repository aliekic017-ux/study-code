#include "prüfungsamt.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
    Queue tfe25;
    init_queue(&tfe25);

    FILE *open = fopen("studenten.txt", "r");
    if (open == NULL)
    {
        printf("Fehler biem Öffnen der Datei");
        return 1;
    }
    
    // Zwischenspeichern für das Einlesen der Datei

    char zeile [100]; // speichert erstmal die gesamte Zeile
    int martikelnummer = 0; // Zwischenspeicher von der Martikelnummer aus der Zeile
    char name [50]; // // Zwischenspeicher für den Namen aus der Zeile
    float notenschnitt = 0.0f; // Zwischenspeicher für den Notenschnitt aus der Zeile


     while(fgets (zeile, sizeof zeile, open) != NULL)
     {
        if ()
     }
 

}