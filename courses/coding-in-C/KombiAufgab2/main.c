#include "notizen.h"
#include <stdlib.h>
#include <stdio.h>


int main (void)
{
    NoteList ToDO;
    init_list(&ToDO);

    FILE* open = fopen ("notizen.txt", "r");
    if (open == NULL)
    {
        printf("Fehler beim Öffnen der Datei");
        return 1;
    }
    
    int id = 0;
    char zeile [100];

    while (fscanf(open, "%d %99s", &id, zeile) == 2)
    {
        {
            Note *new = create_note(id, zeile);
            if (new == NULL)
            {
                printf("Fehler beim Erzeugen eines neune Knoten");
                fclose (open);
                return 1;
            }

            append_note(&ToDO, new);
            
        }
        
    }
    fclose (open);

    printf("Die kompleete Liste:\n");
    print_list(&ToDO);

    printf("\nDIe Anzahl der Notizen liegt zu dem Zeitpunkt bei: %d\n", count_notes(&ToDO));

    Note *search = find_note_by_id(&ToDO, 103);
    if (search != NULL)
    {
        printf("\nDas ELement mit der gesuchten ID ist --> ID: %d, Text: %s\n", search->id, search->text);
    }
    else
    {
        printf("\nDer Eintrag mit der gesuchten ID wurde in der Liste der Notizen nicht gefunden.\n");
    }

    delete_first_note(&ToDO);

    printf("Liste nach dem Löschen der ersten Notiz:\n\n");
    print_list(&ToDO);


    Note *einfg1 = create_note(12, "Schlafen");
    append_note(&ToDO, einfg1);

    Note *einfg2 = create_note (14, "Trinken");
    append_note(&ToDO, einfg2);

    printf("\n\nListe nach dem Einfügen von 2 neuen Notizen.");
    print_list(&ToDO);

    FILE *schrieben = fopen("backup.txt", "w");
    if (schrieben == NULL)
    {
        printf("Fehler beim Öffnen der Datei.");
        return 1;
    }

    Note *iterator = ToDO.head;
    while (iterator != NULL)
    {
        if(fprintf(schrieben, "ID: %d, Text: %s\n", iterator->id, iterator->text) < 0)
        {
            printf("Fehler beim Schrieben ");
            fclose(schrieben);
            delete_list(&ToDO);
            return 1;
        }
        iterator = iterator->p_next;
    }
        
    fclose(schrieben);
    delete_list(&ToDO);
    return 0;
    
}