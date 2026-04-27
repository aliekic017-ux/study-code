/*
* File: centerservice.c
* Description: Programmierung einer Queue in C für die Kundenverwaltung im Service-Center
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Node
{
    int customer_id;
    int service_time;
    struct Node *next;
}Node;


typedef struct queue
{
    struct Node *front;
    struct Node *rear;   
}queue;


void init_playlist (queue *liste)
{
    liste->front = NULL;
    liste->rear = NULL;
}

int is_empty (queue *liste)
{
    int is_empty = 1;

    if (liste->front == NULL)
    {
        printf("Die Liste ist leer.");
        is_empty = 1;
    }
    else
    {
        is_empty = 0;
    }
    return is_empty;
}

void enqueue (queue *liste, int customer_id, int service_time)
{
    Node *new_customer = malloc(sizeof *new_customer);
    if (new_customer == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return;
    }
    new_customer->customer_id = customer_id;
    new_customer->service_time = service_time;
    new_customer->next = NULL;

    if (liste->front == NULL)
    {
        liste->front = new_customer;
        liste->rear = new_customer;
    }
    else
    {
        liste->rear->next = new_customer;
        liste->rear = new_customer;
    }   
}


int dequeue (queue *liste)
{
    if(liste->front == NULL)
    {
        printf("Die Liste ist leer");
        return -1;
    }

    int customer_id = 0;

    customer_id  = liste->front->customer_id;
    Node *temp = liste->front;
    liste->front = liste->front->next;

    if (liste->front == NULL)
    {
        liste->rear = NULL;
    }
    

    free(temp);
    return customer_id;
    
}


int peek (queue *liste)
{
    if (liste->front == NULL)
    {
        printf("Die Liste ist leer");
        return -1;
    }
    
    int customer_id = liste->front->customer_id;

    return customer_id;
}

void print_queue (queue *liste)
{
    if (liste->front == NULL)
    {
        printf("Die Liste ist leer");
        return; 
    }
    Node *tmp = liste->front;

    while (tmp != NULL)
    {
        printf("Kunde: %d, Zeit: %d\n", tmp->customer_id, tmp->service_time);
        tmp = tmp->next;
    }
    
}


void clear_queue (queue *liste)
{
    while (liste->front != NULL)
    {
        dequeue(liste);
    }
    
}

int total_service_time (queue *liste)
{
    int total_service_time = 0;
    Node *temp = liste->front;

    while (temp != NULL)
    {
       total_service_time = temp->service_time + total_service_time;
       temp = temp->next;
    }
    return total_service_time;
    
}


int main ()
{
    queue bkk;
    init_playlist(&bkk);

    printf("Leer? %d\n", is_empty(&bkk));
    enqueue(&bkk, 201, 10);
    enqueue(&bkk, 202, 5);
    enqueue(&bkk, 203, 8);

    print_queue(&bkk);
    printf("Die gesamte Wartezeit betraegt: %d\n", total_service_time(&bkk));
    printf("Erster Kunde: %d\n", peek(&bkk));
    printf("Entfernt: %d\n", dequeue(&bkk));
    print_queue(&bkk);

    printf("Die gesamte Wartezeit betraegt: %d\n", total_service_time(&bkk));

    printf("Entfernt: %d\n", dequeue(&bkk));
    printf("Entfernt: %d\n", dequeue(&bkk));

    printf("Leer? %d \n", is_empty(&bkk));
    printf("Erster Kunde: %d\n", peek(&bkk));
    printf("Entfernt: %d\n", dequeue(&bkk));
    clear_queue(&bkk);

    return 0;
}