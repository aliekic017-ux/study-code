#include "sensor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void init_list (Liste *list)
{
    list->head = NULL;
}

Messung *create_messung(double zeit, double wert)
{
    Messung *neuerMesswert = malloc(sizeof *neuerMesswert);
    if (neuerMesswert == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return NULL;
    }
    neuerMesswert->zeit = zeit;
    neuerMesswert->wert = wert;
    neuerMesswert->next = NULL;

    return neuerMesswert;
    
}

void append_messung (Liste *list, Messung *pMessung)
{
    if (list->head == NULL)
    {
        list->head = pMessung;
        return;
    }
    
    Messung *iterator = list->head;
    while (iterator->next != NULL)
    {
        iterator = iterator->next;
    }
    iterator->next = pMessung;
}


void print_liste (Liste *list)
{
    if (list->head == NULL)
    {
        printf("Die Liste ist leer.");
        return;
    }
    Messung *iter = list->head;
    while (iter != NULL)
    {
        printf("Zeit: %lf, Wert: %lf\n", iter->zeit, iter->wert);
        iter = iter->next;
    }
    
}

void delete_first_messung (Liste *list)
{
    if (list->head == NULL)
    {
        printf("Die Liste ist leer.\n");
        return;
    }
    Messung *temp = list->head;
    list->head = list->head->next;
    free(temp);
    
}


void delete_liste (Liste *list)
{
    if (list->head == NULL)
    {
        printf("Die Liste ist leer.");
        return;
    }
    
    while (list->head != NULL)
    {
        delete_first_messung(list);
    }
    
}


int count_messungen (Liste *list)
{
    int counter = 0;

    if (list->head == NULL)
    {
        return counter;
    }
    Messung *iterator = list->head;
    while (iterator != NULL)
    {
        counter = counter + 1;
        iterator = iterator->next;
    }

    return counter;
}

Messung *find_max_wert (Liste *list)
{
   
    if (list->head == NULL)
    {
        printf("Die Liste ist leer");
        return NULL;
    }
    
    Messung *max = list->head;
    Messung *iterator = list->head;
    while (iterator != NULL)
    {
        if (iterator->wert > max->wert)
        {
            max = iterator;
        }
        iterator = iterator->next;
    }
    return max;
}

