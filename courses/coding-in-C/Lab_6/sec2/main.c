#include <stdlib.h>
#include <stdio.h>





    struct car
    {
        float fuel_level;       // aktueller Tankfüllstand
        float max_fuel_level;   // maximaler Tankinhalt
        char Modell [25];       // Automodell 
    };
    
    float refuel(struct car *car, float fuellen)
    {
        car->fuel_level = car->fuel_level + fuellen;

        if (car->fuel_level > car->max_fuel_level)
        {
            car->fuel_level = car->max_fuel_level;
        }
        
        return car->fuel_level;

    }

    int main ()
{
    struct car auto1 = {10.0, 25.0, "Cla"};

     float aktuell = refuel(&auto1, 10);
     printf("akuteller Tankstand: %f", aktuell);

    


    return 0;

}    
    


