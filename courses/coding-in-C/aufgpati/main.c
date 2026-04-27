#include "patient.h"
#include <stdlib.h>
#include <stdio.h>


int main ()
{
    Queue Praxis;
    init_queue(&Praxis);

    FILE *open = fopen("patienten.txt", "r");
    if (open == NULL)
    {
        printf("Fehler beim Öffnen der Datei.\n");
        return 1;
    }

    FILE *schreiben = fopen("backup.txt", "w");
    if (schreiben == NULL)
    {
        printf("Fehler beim Öffnen der Datei.");
        fclose(open);
        return 1;
    }
    

    int id = 0;
    char name [50];
    // 49 nicht vergessen beim %s
    while (fscanf(open, "%d %49s", &id , name) == 2) // Solange in der Datei im Formnat %d %s Daten sind werden neue Patienten angelegt und der Queue hinzugefügt
    {
        Patient *neu = create_patient(id, name);
        enqueue(&Praxis, neu);
        fprintf(schreiben, "%d %49s\n",id, name);

    }
    fclose(open);
    fclose(schreiben);

    print_queue (&Praxis);
    printf("Die Anzahl der Patienten beträgt: %d\n", count_patient(&Praxis));

    peek_front(&Praxis);
    printf("\n");

    Patient *find_id = find_patient_by_id(&Praxis, 208);
    if (find_id != NULL)
    {
        printf("Gefunden: ID: %d , Name: %s\n", find_id->id , find_id->name);
    }
    else
    {
        printf("Keine Person mit dieser ID konnte gefunden werden.\n");
    }


    dequeue(&Praxis);
    print_queue (&Praxis);

    delete_queue(&Praxis);
    print_queue(&Praxis);

    return 0;
    

}