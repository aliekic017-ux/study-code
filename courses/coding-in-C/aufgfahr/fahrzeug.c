#include "fahrzeug.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void init_list (List *p_liste)
{
    p_liste->head = NULL;
}

Order *create_order (int id, char *fahrzeug, int dauer_minuten)
{
    Order *newOrder = malloc (sizeof *newOrder);
    if (newOrder == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return NULL;
    }
    
    newOrder->fahrzeug = malloc(strlen(fahrzeug)+1);
    if (newOrder->fahrzeug == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        free(newOrder);
        return NULL;
    }
    strcpy(newOrder->fahrzeug, fahrzeug);
    newOrder->id = id;
    newOrder->dauer_minuten = dauer_minuten;
    newOrder->next = NULL;

    return newOrder; 
}

void append_order (List *p_liste, Order *p_order)
{
    if (p_liste->head == NULL)
    {
        p_liste->head = p_order;
        return;
    }
    
    Order *iterator = p_liste->head;
    while (iterator->next != NULL)
    {
        iterator = iterator->next;
    }
    iterator->next = p_order;
}

void print_list (List *p_list)
{
    if (p_list->head == NULL)
    {
        printf("Die Liste ist leer.\n");
        return;
    }
    
    Order *iteraotr = p_list->head;
    while (iteraotr != NULL)
    {
     printf("ID: %d, Fahrzeugmodell: %s, Dauer (in min): %d\n", iteraotr->id, iteraotr->fahrzeug, iteraotr->dauer_minuten);
     iteraotr = iteraotr->next;
    }
    
}


Order *find_order_by_id (List *p_list, int id)
{
    if (p_list->head == NULL)
    {
        printf("Die Liste ist leer.");
        return NULL;
    }
    
    Order *iterator = p_list->head;
    while (iterator != NULL)
    {
        if (iterator->id == id)
        {
            return iterator;
        }
        iterator = iterator->next;
    }
    return NULL;
}

void delete_first_order (List *p_liste)
{
    if (p_liste->head == NULL)
    {
        printf("DIe Liste ist leer.");
        return;
    }

    Order *temp = p_liste->head;
    p_liste->head = p_liste->head->next;
    free(temp->fahrzeug);
    free(temp);
}

int count_orders (List *p_liste)
{
    int counter = 0;

    if (p_liste->head == 0)
    {
        printf("Die Liste ist leer");
        return counter;
    }
    
    Order *iterator = p_liste->head;
    while (iterator != NULL)
    {
        counter = counter + 1; 
        iterator = iterator->next;

    }

    return counter;   
}

void free_liste (List *p_liste)
{
    if (p_liste->head == NULL)
    {
        printf("Die Liste ist leer.");
        return;
    }
    
    while (p_liste->head != NULL)
    {
        delete_first_order(p_liste);
    }
    
}