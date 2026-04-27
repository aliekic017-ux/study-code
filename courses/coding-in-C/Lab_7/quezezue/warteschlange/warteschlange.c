#include "warteschlange.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_queue (Queue *p_queue)
{
    p_queue->front = NULL;
    p_queue->rear = NULL;

}

customer *create_customer (int id, char *name)
{
    customer *newCustomer = malloc (sizeof *newCustomer);
    if (newCustomer == NULL)
    {
        printf("Speicherallokation fehlgeschlagen. \n");
        return NULL;
    }
    
    //dynamische Speiucherreservierung für den Namen 

    newCustomer->name = malloc (strlen(name)+1);
    if (newCustomer->name == NULL)
    {
        printf("Speicherallaktion fehlgeschlagen");
        free(newCustomer);

        return NULL;
    }
    newCustomer->id =id;
    strcpy (newCustomer->name, name);
    newCustomer->next = NULL;


    return newCustomer;
}

// hinten ein neues Element hinzufügen
void enqueue (Queue *p_queue , customer *p_customer)
{
    if (p_queue->front == NULL && p_queue->rear == NULL)
    {
        p_queue->front = p_customer;
        p_queue->rear = p_customer;
        return ;
    }

    p_queue->rear->next = p_customer;
    p_queue->rear = p_customer;

}

// erstes Element löschen
void dequeue (Queue *p_queue)
{
    if (p_queue->front == NULL && p_queue->rear == NULL)
    {
        printf("Die Liste ist leer");
        return;
    }

    customer *p_temp = p_queue->front;
    p_queue->front = p_queue->front->next;

    // ABFRAGE MACHEN OB NACH DEM ENTFERNEN NOCH ELEMENTE IN DER QUEUE LIEGEN SONST ZEIGEN DIE ZEIGER IRGENDWO HIN

    if (p_queue->front == NULL)
    {
        p_queue->rear = NULL;
        printf("Die Liste ist leer");
        return;
    }

    free(p_temp->name);
    free(p_temp);

}

void print_queue (Queue *p_queue)
{
    if (p_queue->front == NULL && p_queue->rear == NULL)
    {
        printf("Die Queue ist leer");
        return;

    }

    customer *iterator = p_queue->front;
    while (iterator != NULL)
    {
        printf("ID: %d  Name: %s \n ", iterator->id, iterator->name);
        iterator = iterator->next;
    }
    
}

void delete_queue (Queue *p_queue)
{
    if (p_queue->front == NULL && p_queue->rear == NULL)
    {
        printf("Die Liste ist leer\n");

    }
    
    while (p_queue->front != NULL)
    {
        dequeue(p_queue); 
    }
    
}