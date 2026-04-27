#include "krankenhaus.h"
#include <stdio.h>
#include <stdlib.h>


int main (void)
{
    Queue krankenhaus;
    init_queue(&krankenhaus);

    // Patienten anlegen
    patient *ali = create_patient (120, "Ali", "Zahnschmerzen");
    patient *ezgi = create_patient (123, "Ezgi", "Bauschnmerzen");
    patient *ece = create_patient (21, "Ece", "Ohrschmerzen");
    patient *kaan = create_patient (62, "Kaan", "Zahnschmerzen");

    enqueue(&krankenhaus, ali);
    enqueue(&krankenhaus, ezgi);
    enqueue(&krankenhaus, ece);
    enqueue(&krankenhaus, kaan);

    print_queue(&krankenhaus);

    find_patient_by_id(&krankenhaus, 62);

    find_patient_by_name(&krankenhaus, "Ezgi");

    peek_front (&krankenhaus);

    dequeue(&krankenhaus);
    dequeue(&krankenhaus);

    print_queue(&krankenhaus);
 


    return 0;
} 

