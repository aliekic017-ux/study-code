#include "fahrzeug.h"
#include <stdio.h>
#include <stdlib.h>


int main (void)
{
    List werkstatt;
    init_list(&werkstatt);

    FILE *open = fopen("auftraege.txt", "r");
    if (open == NULL)
    {
        printf("Fehler beim Öffnen der Datei.");
        return -1;
    }
    
    int id = 0;
    int dauer_minuten = 0;
    char fahrzeug[50];

    while (fscanf(open, "%d %49s %d", &id, fahrzeug, &dauer_minuten) == 3)
    {
        Order *new = create_order(id, fahrzeug, dauer_minuten);
        append_order(&werkstatt,new);
    }
    fclose(open);

    print_list(&werkstatt);

    printf("\n\n Die Anzahl der Aufträge betraegt: %d\n", count_orders(&werkstatt));
    
    Order *search = find_order_by_id(&werkstatt, 103);
    if (search != NULL)
    {
        printf("\nDer Auftrag mit angegeben ID wurde gefunden. ID: %d, Fahrzeug: %s, Dauer (in min): %d\n", search->id, search->fahrzeug, search->dauer_minuten);

    }
    else
    {
        printf("Es wurde kein Auftrag gefunden, was der ingegeben ID entspricht.\n");
    }

    printf("Die Liste nach dem Entfernen von einem Auftrag:\n");
    delete_first_order(&werkstatt);
    print_list(&werkstatt);

    Order *einf = create_order(201, "AMG_GT", 90);
    Order *einf2 = create_order(202, "V_Klasse", 50);

    append_order(&werkstatt, einf);
    append_order(&werkstatt, einf2);

    printf("Die Liste nachdem 2 weitere Aufträge hinzugefügt wurden: \n");
    print_list(&werkstatt);


    FILE *schreiben = fopen ("backup.txt", "w");
    if (schreiben == NULL)
    {
        printf("Fehler beim Öffnen der Datei.");
        return -1;
    }
    
    Order *iterator = werkstatt.head;
    while(iterator != NULL)
    {
        fprintf(schreiben, "ID: %d, Fahrzeug: %s, Dauer (in min): %d\n", iterator->id, iterator->fahrzeug, iterator->dauer_minuten);
        iterator =iterator->next;
    }

    fclose(schreiben);
    free_liste(&werkstatt);
    return 0;
    
}