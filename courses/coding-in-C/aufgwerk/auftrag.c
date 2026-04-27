#include "auftrag.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void init_queue (Queue *p_queue)
{
    p_queue->rear = NULL;
    p_queue->front = NULL;
}

Order *create_new_Order (int id, char *title , int dauer_minuten)
{
    Order *newOrder = malloc(sizeof *newOrder);
    if (newOrder == NULL)
    {
        printf("Speicherallokation fehlgeschlagen.\n");
        return NULL;
    }
    newOrder->titel = malloc (strlen(title)+1);
    if (newOrder->titel == NULL)
    {
        printf("Speicherallokation fehlgeschlagen.\n");
        free(newOrder);
        return NULL;
    }
    
    strcpy(newOrder->titel, title);
    newOrder->id = id;
    newOrder->dauer_minuten = dauer_minuten;
    newOrder->next = NULL;

    return newOrder;
}


void enqueue (Queue *p_queue, Order *p_order)
{
    if (p_queue->front == NULL && p_queue->rear == NULL)
    {
        p_queue->front = p_order;
        p_queue->rear = p_order;
        return;
    }

    p_queue->rear->next = p_order;
    p_queue->rear = p_order;
}

void dequeue (Queue *p_queue)
{
    if (p_queue->front == NULL && p_queue->rear == NULL)
    {
        printf("Die Liste ist leer.\n");
        return;
    }
    
    Order *temp = p_queue->front;
    p_queue->front = p_queue->front->next;

    if (p_queue->front == NULL)
    {
        p_queue->rear = NULL;
    }
    
    free(temp->titel);
    free (temp);
}


void print_queue (Queue *p_queue)
{
    if (p_queue->front == NULL && p_queue->rear == NULL)
    {
        printf("Die Liste ist leer.");
        return;
    }
    
    Order *iterator = p_queue->front;
    while (iterator != NULL)
    {
        printf("ID: %d, Titel: %s, Dauer (in min): %d\n", iterator->id, iterator->titel, iterator->dauer_minuten);
        iterator = iterator->next;
    }
    
}

void free_queue (Queue *p_queue)
{
    if (p_queue->front == NULL && p_queue->rear == NULL)
    {
        printf("Die Liste ist leer.\n");
        return;
    }
    
    while (p_queue->front != NULL)
    {
        dequeue(p_queue);
    }
    
}

void load_orders_from_file (Queue *p_queue, char *filename)
{
    FILE *open = fopen(filename, "r");
    if (open == NULL)
    {
        printf("Fehler beim Öffnen der Datei.");
        return;
    }
    int id = 0;
    char titel[100];
    int dauer_minuten = 0;

    while(fscanf(open, "%d %99s %d", &id , titel, &dauer_minuten) == 3)
    {
        Order *newOrder = create_new_Order(id, titel, dauer_minuten);
        if (newOrder == NULL)
        {
            printf("Fehler beim Erstellen eines Auftrags.");
            fclose(open);
            return;
        }
        enqueue(p_queue, newOrder);
    }
    fclose(open);
}


void save_queue_to_file(Queue *p_queue, char *filename)
{
     FILE *save = fopen (filename ,"w");
    if (save == NULL)
    {
        printf("Fehler beim Öffnen der Datei.");
        return;
    }
    
    Order *iterator = p_queue->front;
    while (iterator != NULL)
    {
        fprintf(save, "ID: %d, Titel: %s, Dauer(in min): %d\n", iterator->id, iterator->titel, iterator->dauer_minuten);
        iterator = iterator->next;
    }
    fclose(save);
}

