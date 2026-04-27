#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sensor
{
    int id;
    double value;
    struct sensor *next;
}sensor;

typedef struct sensorlist
{
    struct sensor *head;
}sensorlist;


void init_list(sensorlist *sensorlist)
{
    sensorlist->head = NULL;

    return;
}

void add_sensor(sensorlist *sensorlist, int id, double value)
{
    sensor *newsensor = malloc(sizeof(*newsensor));
    if (newsensor == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return;
    }

    newsensor->value = value;
    newsensor->id = id;
    newsensor->next = NULL;

    if (sensorlist->head == NULL)
    {
        sensorlist->head = newsensor;
        return;
    }
    
    sensor *iterator = sensorlist->head;

    while (iterator->next != NULL)
    {
        iterator = iterator->next;
    }
    iterator->next = newsensor;

}

void print_sensors(sensorlist *sensorlist)
{
    if (sensorlist->head == NULL)
    {
        printf("Die Liste der Senosren ist leer");
    }

    sensor *temp = sensorlist->head;
    
    while (temp != NULL)
    {
        printf("ID: %d  Value: %.1f \n", temp->id , temp->value);
        temp = temp->next;
        
    }
    return;
}

void delete_first_sensor (sensorlist *sensorlist)
{
    if (sensorlist->head == NULL)
    {
        printf("Die lsite der Sensoren ist leer");
    }
   
    sensor *iterator = sensorlist->head;
    sensorlist->head = sensorlist->head->next;

    free(iterator);
}


void delete_list (sensorlist *sensorlist)
{
    

    while (sensorlist->head != NULL)
    {
        delete_first_sensor(sensorlist);
        
    }
    
}

int main ()
{

    sensorlist list;
    init_list(&list);

    add_sensor(&list, 1, 23.4);
    add_sensor(&list, 2, 18.7);
    add_sensor(&list, 3, 30.1);
    add_sensor(&list, 4, 15.9);

    print_sensors(&list);
    delete_first_sensor(&list);
    printf("\n");
    print_sensors(&list);

    delete_list(&list);


    return 0;
}