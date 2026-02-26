#include <stdio.h>
#include <stdlib.h>


struct SensorData
{
    float time;                  // Zeitpunkt der Messung in sek.
    double probability;         // gemessenes Signal zw. 0 - 1
};

struct Sensor
{
    int id;                  // Sensor-ID
    double threshold;       // Schwellenwert ( Grenzwert zur Erkennung)
    struct SensorData data[3000];
    int object_detection[3000];
};


void zzeit_objerkennung (struct Sensor *sensor) // Zeitintervall für Sensorzeiten für die Detektion
{
    float timestart;
    int active;

    for (int z = 0; z < 3000 ; z++)
    {
        if (active == 0 && sensor->object_detection[z] == 1)
        {
            timestart = sensor->data[z].time;
            active = 1; 
        }
        if (active == 1 && sensor->object_detection[z] == 0)
        {
            active = 0;
            float timeend = sensor->data[z-1].time;
            
            printf("Start: %.2f   and End: %.2f \n ", timestart, timeend);
        }       
    }
}

void fusion (struct Sensor *sensor , struct Sensor *sensor2) // Zeiterkenneung Fusion, beide Sensoren aktiv 
{
    float timestart_fusion;
    float timeend_endfusion;
    int active_fusion = 0;

    for (int g = 0; g < 3000; g++)
    {
        if(active_fusion == 0 && sensor->object_detection[g] == 1 && sensor2->object_detection[g] == 1 )
        {
            timestart_fusion = sensor->data[g].time;
            active_fusion =1;
        
        }
        if (active_fusion == 1 && !(sensor->object_detection[g] == 1  && sensor2->object_detection[g] == 1))
        {
            active_fusion = 0;
            timeend_endfusion = sensor->data[g-1].time;

            printf(" Fusion Start: %.2f   Fusion End %.2f", timestart_fusion, timeend_endfusion);
            
        }
    }
}



int main ()
{
    // Initialisierung von zwei verschiedenen Sensoren
    struct Sensor Typ1 = {1234, 0.8};
    struct Sensor Typ2 = {7675, 0.7};

    

    // Öffnen der beiden Dateien und Einlesen mithilfe des fscanf-Befehls
    FILE* datei;

    datei = fopen ("sensor1.txt", "r");

    if (datei == NULL)
    {
        printf("Fehler beim Öffnen der 1.Datei");
        return 1;
    }

    FILE* datei2;

    datei2 = fopen ("sensor2.txt", "r");

    if (datei2 == NULL)
    {
        printf("Fehler beim Öffnen der 2.Datei");
        return 1;
    }

    for (int i = 0; i < 3000; i++)
    {
        if(fscanf(datei, "%f %lf", &Typ1.data[i].time, &Typ1.data[i].probability) != 2) 
        {
            printf("Fehler beim Lesen der 1.Datei");
            return 1;
        }
        else
        {
            if (Typ1.data[i].probability > Typ1.threshold)
            {
                Typ1.object_detection[i] = 1;
            }
            else
            {
                Typ1.object_detection[i] = 0;
            }
            
        }

    }

    for (int k = 0; k < 3000; k++)
    {
        if(fscanf(datei2, "%f %lf", &Typ2.data[k].time, &Typ2.data[k].probability) != 2)
        {
            printf("Fehler beim Lesen der 2.Datei");
            return 1;
        }
        else
        {
            if (Typ2.data[k].probability > Typ2.threshold)
            {
                Typ2.object_detection[k] = 1;
            }
            else
            {
                Typ2.object_detection[k] = 0;
            }

        }
        
    }
// Schließen der geöffneten Dateien && ABfrage, dass Dateien sicher geschlossen wurden 
if (fclose(datei) == -1)
{
    printf("Fehler beim Schließen der Datei: sensor1.txt");
    return 1;
}

if (fclose(datei2) == -1)
{
    printf("Fehler beim Schließen der Datei: sensor2.txt");
    return 1;
}


// Ausgabe der Sensoren mit ihren Detektion-Zeiten && Fusion 
printf("\nSensor 1 detections:\n");
zzeit_objerkennung(&Typ1);

printf("\nSensor 2 detections:\n");
zzeit_objerkennung(&Typ2);

printf("Fusion detection:");
fusion(&Typ1,&Typ2);

return 0;
}


