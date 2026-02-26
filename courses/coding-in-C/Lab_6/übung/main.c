#include <stdio.h>
#include <stdlib.h>


struct battery 
{
    float charge_level;   //aktueller Ladezustand
    float max_charge; 
    char name [25];
};

void chargeBattery (struct battery *battery, float lademenge)
{
    battery->charge_level = battery->charge_level + lademenge;
    
    if (battery->charge_level > battery->max_charge)
    {
        battery->charge_level = battery->max_charge;
    }
}

int main()
{

    struct battery Akku2 = {60.0, 100.0, "Alis"};
    
    chargeBattery(&Akku2, 30); 
    

    printf("Der neue Ladezustand der Batterie betraegt: %.2f", Akku2.charge_level);




    return 0;
}