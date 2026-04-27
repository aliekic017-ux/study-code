#include "patientenliste.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
    Liste arzt;
    init_list(&arzt);

    FILE *open = fopen ("./namen.txt", "r");
    char info [100];
    int id = 1;


    if (open == NULL)
    {
        printf("Fehler bei Öfnen der Datei");
        return 1;
    }

   while (fgets (info, sizeof info , open) != NULL)
   {
        info[strcspn(info, "\n")] = '\0';

        Patient *neu = create_patient(id, info);
        append_patient(&arzt, neu);
        id++;
   }

   fclose (open);
   print_liste(&arzt);

   FILE *write_file = fopen ("./ausgaben.txt", "w");
   if (write_file == NULL)
   {
    printf("Fehler beim Öffnen der AUsgabendatei");
    delete_list(&arzt);
    return 1;
   }
   
   Patient *iter = arzt.head;
   while (iter != NULL)
   {
        for (int i = 0; iter->name[i] != '\0' ; i++)
        {
            fputc(iter->name[i], write_file);
        }
        
        fputc('\n', write_file);
        iter = iter->next; 
   }
   
fclose (write_file);
   return 0;

}