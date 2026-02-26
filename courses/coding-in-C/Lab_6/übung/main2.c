#include <stdio.h>
#include <stdlib.h>

struct Sensor
{
    float current_temp;
    float max_temp;
    char name[25];
};

float updateTemp(struct Sensor *Sensor, float erhoehung)
{
     Sensor->current_temp =  Sensor->current_temp + erhoehung;

    if (Sensor->current_temp > Sensor->max_temp)
    {
        Sensor->current_temp = Sensor->max_temp;
    }
    return Sensor->current_temp; // Rückgabe dieses Wertes der Funktions
}

int main ()
{
    struct Sensor ifmSens = {20.0 , 150.0, "Balluff Lichttaster"};
    
    

    float ergebnis = updateTemp(&ifmSens, 15);
    printf("Die aktuelle Temperatur betraegt: %.2f", ergebnis);


    return 0;
}