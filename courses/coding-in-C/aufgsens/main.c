#include "sensor.h"
#include <stdio.h>
#include <stdlib.h>


int main ()
{
    Liste sens_daten;
    init_list (&sens_daten);

    FILE *open = fopen("sensordaten.txt", "r");
    if (open == NULL)
    {
        printf("Fehler beim Öffnen der Datei.\n");
        return 1;
    }
    

   double wert;
   double zeit;

   while (fscanf(open, "%lf %lf", &zeit, &wert) == 2)
   {
       Messung *neu = create_messung(zeit, wert);
       if (neu != NULL)
       {
        append_messung(&sens_daten, neu);
       }
       
   }

   fclose (open);

   print_liste(&sens_daten);
   printf("Die Anzahl der Messungen betraegt: %d\n", count_messungen(&sens_daten));


   printf("\n");

   Messung *max = find_max_wert(&sens_daten);
   if (max != NULL)
   {
     printf("\nDIe Messung mit dem größten Wert ist Zeit: %lf , Wert: %lf\n", max->zeit, max->wert);
   }

   delete_first_messung(&sens_daten);
   print_liste(&sens_daten);

   delete_liste(&sens_daten);
   print_liste(&sens_daten);

   return 0;
}