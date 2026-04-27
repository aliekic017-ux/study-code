#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct measurement
{
    double temperature;
    struct measurement *next;
}measurement;

void add_measurement_front(measurement **head, double temperature)
{
    measurement *new = malloc(sizeof (*new));
    if (new == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return ;

    }
    new->temperature = temperature;
    new->next = *head;

    *head = new;
}


void print_measurement (measurement *head)
{
    measurement *temp = head;
    while (temp != NULL)
    {
        printf("Temperature: %.1f\n", temp->temperature);
        temp = temp->next;
    }

}

int count_measurement (measurement *head)
{
    measurement *temp = head; 
    int count = 0;

    while (temp != NULL)
    {
        count = count + 1;
        temp = temp->next;
        
    }
    return count;
}

double average_temperature (measurement *head)
{
    int count = 0;
    double average = 0.0; 
    measurement *temp = head;

    while (temp != NULL)
    {
        average = temp->temperature + average;
        count = count + 1; 
        temp = temp->next;

    }
    return average/count;
    
}

double find_max_temperature(measurement *head)
{
    measurement *temp = head;
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

void delete_list (measurement **head)
{
    measurement *temp;
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);

    }

}

int main ()
{
    measurement *head = NULL;

    add_measurement_front(&head, 20.1);
    add_measurement_front(&head, 19.8);
    add_measurement_front(&head, 21.0);
    add_measurement_front(&head, 18.5);

    print_measurement(head);

    printf("Count: %d \n", count_measurement(head));
    printf("Average: %.2f \n", average_temperature(head));
    printf("Max_temp: %.2f \n", find_max_temperature(head));

    return 0;
}