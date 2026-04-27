#include "meldung.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (void)
{
    Stack meldungen;
    init_stack (&meldungen);

    FILE *open = fopen("meldungen.txt", "r");
    if (open == NULL)
    {
        printf("Fehler beim Öffnen der Datei.");
        return 1;
    }
    
    int schleifendurchlauf = 10;
    int id = 0;
    char text [50];
    int priorität = 0;

    for (int i = 0; i < schleifendurchlauf; i++)
    {
        if (fscanf(open, "%d %49s %d", &id, text, &priorität) != 3)
        {
            printf("Fehler beim Einlesen der Datei in Zeile: %d\n\n", i+1);
            fclose(open);
            free_stack(&meldungen);
            return 1;
        }

        Message *new = create_message(id, text, priorität);

        if (new == NULL)
        {
            printf("Fehler beim Erzeugen einer Message.");
            fclose(open);
            free_stack(&meldungen);
            return 1;
        }
        
        push(&meldungen, new);
        
    }
    fclose (open);

    print_stack(&meldungen);

    printf("\nDie Anzahl de Meldungen betraegt: %d\n\n", count_stack(&meldungen));

    for (int i = 0; i < 3; i++)
    {
        pop(&meldungen);
    }
    
    print_stack(&meldungen);

    FILE *schreiben = fopen("backup.txt", "w");
    if (schreiben == NULL)
    {
        printf("Fehler beim Öffnen der Backup-Datei");
        free_stack(&meldungen);
        return 1;
    }

    Message *iterator = meldungen.p_top;

    while (iterator != NULL)
    {
        fprintf(schreiben, "ID: %d, Text: %s, Priotität: %d\n", iterator->id, iterator->text, iterator->priorität);
        iterator = iterator->p_next;
    }

    fclose(schreiben);    
    free_stack(&meldungen);

    return 0;
    
}