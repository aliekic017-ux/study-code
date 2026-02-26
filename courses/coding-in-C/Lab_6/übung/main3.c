#include <stdio.h>
#include <stdlib.h>

struct Motor
{
    int akt_drehzahl;
    int max_drehzahl;
    char motortyp [67];
};

int increaseRPM(struct Motor *Motor, int erhoehung)
{
    Motor->akt_drehzahl = Motor->akt_drehzahl + erhoehung;

    if(Motor->akt_drehzahl == Motor->max_drehzahl)
    {
        printf("Motor läuft bereits auf Maximum\n\n");
        Motor->akt_drehzahl = Motor->max_drehzahl;
        
        return Motor->akt_drehzahl;
    }

    return Motor->akt_drehzahl;
}


int main()

{
    struct Motor meinMotor = {3000, 6000, "Benning"};
    
    int ergebnis = increaseRPM(&meinMotor, 4000);

    printf("Die Motordrehzahl betraegt: %d", ergebnis);




    return 0;
}