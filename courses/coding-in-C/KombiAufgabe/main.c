#include "werkzeuge.h"
#include <stdio.h>
#include <stdlib.h>


int main (void)
{
    ToolList home;
    init_list(&home);

    FILE *open = fopen ("werkzeuge.txt", "r");
    if (open == NULL)
    {
        printf("Fehler beim Öffnen der Datei.\n");
        return 1;
    }
    
    int id = 0;
    char bezeichnung[50];
    char zustand [20];


    while (fscanf(open, "%d %49s %19s", &id, bezeichnung, zustand) == 3)
    {
        Tool *new = create_tool(id, bezeichnung, zustand);
        if (new == NULL)
        {
            printf("Fehler beim Lesen der Datei");
            fclose(open);
            delete_list(&home);
            return 1;
        }
        
        append_tool(&home, new);

    }
    fclose(open);

    printf("\nVollständige Liste aller Werkzeuge:\n");
    print_list(&home);

    printf("\nDie Anzahl der Werkzeuge in der Liste betraegt zu dem jetzigen Zeitpunkt: %d\n", count_tools(&home));

    Tool *search = find_by_id(&home, 103);
    if (search != NULL)
    {
        printf("\nWerkzeug gefunden: ID: %d, Bezeichnung: %s, Zustand: %s\n", search->id, search->bezeichnung, search->zustand);
    }
    else
    {
        printf("\nEs konnte kein Werkzeug mit der ID gefunden werden.\n");
    }

    printf("\nDie Liste nach dem Löschen von einem Werkzeug:\n");
    delete_first_tool(&home);
    print_list(&home);

    Tool *new1 = create_tool (121, "Bohrmaschine", "Sehr gut");
    Tool *new2 = create_tool (122, "Heckenschere", "Sehr gut");

    append_tool(&home, new1);
    append_tool(&home, new2);

    FILE *schrieben = fopen("backup.txt", "w");
    if (schrieben == NULL)
    {
        printf("Fehler beim Öffnen der Datei.\n");
        delete_list(&home); // Speicher freigebee, wenn Datei für Backup nicht geöffnet werden konnte.
        return 1;
    }
    
    Tool *iterator = home.p_head;
    while (iterator != NULL)
    {
        if(fprintf(schrieben, "ID: %d, Bezeichnng: %s, Zustand: %s", iterator->id, iterator->bezeichnung, iterator->zustand) < 0)
        {
            printf("Fehler beim Schrieben der Datei.\n");
            fclose(schrieben);
            delete_list(&home);
            return 1;
        }
        iterator = iterator->p_next;

    }
    fclose(schrieben);
    delete_list(&home);

    return 0;
}
