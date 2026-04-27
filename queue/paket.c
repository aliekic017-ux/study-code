#include "paket.h"
#include <stdio.h>
#include <stdlib.h>


void init_queue (Queue *p_queue)
{
    p_queue->p_front = NULL;
    p_queue->p_rear = NULL;
}

Paket *create_node (int id, float gewicht)
{
    Paket *newElement = malloc (sizeof *newElement);
    if (newElement == NULL)
    {
        printf("Speicherallokation fehlgeschlagen.\n");
        return NULL;
    }
    newElement->gewicht = gewicht;
    newElement->id = id;
    newElement->p_next = NULL;

    return newElement;
}

void enqueue (Queue *p_queue, Paket *p_paket)
{
    if (p_paket == NULL)
    {
        return;
    }
    if (p_queue->p_front == NULL && p_queue->p_rear == NULL)
    {
        p_queue->p_front = p_paket;
        p_queue->p_rear = p_paket;
        return;
    }
    
    p_queue->p_rear->p_next = p_paket;
    p_queue->p_rear = p_paket;
}

void dequeue (Queue *p_queue)
{
    if (p_queue->p_front == NULL && p_queue->p_rear == NULL)
    {
        printf("Die Liste ist leer.\n");
        return;
    }

    Paket *temp = p_queue->p_front;
    p_queue->p_front = p_queue->p_front->p_next;

    if (p_queue->p_front == NULL)
    {
        p_queue->p_rear = NULL;
    }
    free(temp);
    
}

void print_queue (Queue *p_queue)
{
    if (p_queue->p_front == NULL && p_queue->p_rear == NULL)
    {
        return;

    }
    
    Paket *iterator = p_queue->p_front;
    while (iterator != NULL)
    {
        printf("Gewicht: %.2f , ID: %d\n", iterator->gewicht, iterator->id);
        iterator = iterator->p_next;
    }
    
}

void free_queue (Queue *p_queue)
{
    if (p_queue->p_front == NULL)
    {
        printf("Die Liste ist leer.\n");
        return;
    }

    while (p_queue->p_front != NULL)
    {
        dequeue(p_queue);
    }
    
}