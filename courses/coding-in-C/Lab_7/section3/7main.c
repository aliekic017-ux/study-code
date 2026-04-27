#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct measurement
{
    double temperature;
    struct measurement *next;
}measurement;

typedef struct messwerte
{
    struct measurement *head;
}messwerte;

void add_measurement_front(messwerte *messwerte, double temperature)
{
    measurement *new = malloc(sizeof (*new));
    if (new == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return ;

    }
    new->temperature = temperature;
    new->next = messwerte->head;
    messwerte->head = new;


}


void print_measurement (messwerte *temp2)
{
    measurement *temp = temp2->head;

    while (temp != NULL)
    {
        printf("Temperature: %.1f\n", temp->temperature);
        temp = temp->next;
    }

}

int count_measurement (messwerte *messwerte)
{
    measurement *temp = messwerte->head;
    
    int count = 0;

    while (temp != NULL)
    {
        count = count + 1;
        temp = temp->next;
        
    }
    return count;
}

double average_temperature (messwerte *messwerte)
{
    int count = 0;
    double average = 0.0; 
    measurement *temp = messwerte->head;

    while (temp != NULL)
    {
        average = temp->temperature + average;
        count = count + 1; 
        temp = temp->next;

    }
    return average/count;
    
}

double find_max_temperature(messwerte *messwerte)
{
    measurement *temp = messwerte->head;
    double max = 0.0;

    while (temp != NULL)
    {
        if (temp->temperature > max)
        {
            max = temp->temperature;
        }
        temp = temp->next;

    }
    return max;
}

void delete_list (messwerte *messwerte)
{
    measurement *temp;
    while (messwerte->head != NULL)
    {
        temp = messwerte->head;
        messwerte->head = messwerte->head->next;
        free(temp);

    }

}

int main ()
{
    messwerte liste;
    liste.head = NULL;

    add_measurement_front(&liste, 20.1);
    add_measurement_front(&liste, 19.8);
    add_measurement_front(&liste, 21.0);
    add_measurement_front(&liste, 18.5);

    print_measurement(&liste);

    printf("Count: %d \n", count_measurement(&liste));
    printf("Average: %.2f \n", average_temperature(&liste));
    printf("Max_temp: %.2f \n", find_max_temperature(&liste));

    return 0;
}