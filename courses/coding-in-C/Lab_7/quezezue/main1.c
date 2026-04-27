/*
* File: main1.c
* Description: Programmierung einer Queue in C zur Verwaltung von Druckaufträgen in einem Computerraum
*/

#include <stdlib.h>
#include <stdio.h>


typedef struct PrintJob
{
    int job_id;
    int pages;
    struct PrintJob *next;
}PrintJob;

typedef struct PrintQueue
{
    struct PrintJob *front;
    struct PrintJob *rear;
}PrintQueue;


void init_queue (PrintQueue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}


int isEmpty (PrintQueue *queue)
{
    int isEmpty = 0;

    if (queue->front == NULL)
    {
        isEmpty = 1; 
    
    }
    
    return isEmpty;
}

void enqueue (PrintQueue *queue , int job_id, int pages)
{
    PrintJob *newAuftrag = malloc (sizeof *newAuftrag);
    if (newAuftrag == NULL)
    {
        printf ("Speicherallokation fehlgeschlagen");
        return; 

    }
    newAuftrag->job_id = job_id;
    newAuftrag->pages = pages; 
    newAuftrag->next = NULL;

    if (queue->front == NULL)
    {
        queue->front = newAuftrag;
        queue->rear = newAuftrag;
    }
    else
    {
        queue->rear->next = newAuftrag;
        queue->rear = newAuftrag;

    }
  
}

int dequeue (PrintQueue *queue)
{
    if (queue->front == NULL)
    {
        printf("Die Liste ist leer");
        return -1;

    }
    
    PrintJob *temp = queue->front;

    int job_id = temp->job_id;
    queue->front = queue->front->next;

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    free (temp);
    return job_id;
}

int peek (PrintQueue *queue)
{
    int job_id; 


    if (queue->front == NULL)
    {
        printf("Die Liste ist leer");
        return -1;
    }
    
    job_id = queue->front->job_id;

    return job_id;

}

void print_queue (PrintQueue *queue)
{
    if (queue->front == NULL && queue == NULL )
    {
        printf("Die Liste ist leer");
        return;
    }

    PrintJob *iterator = queue->front;


    while (iterator != NULL)
    {
        printf("JobID: %d  , Seiten:%d. \n", iterator->job_id, iterator->pages);
        iterator = iterator->next;
    }

    
}

void clear_queue (PrintQueue *queue)
{
  while (queue->front != NULL)
  {
    dequeue(queue);
  }
  
    
    
}

int main(void)
{
    PrintQueue CompRaum;
    init_queue(&CompRaum);

    printf("Leer? %d\n", isEmpty(&CompRaum));

    enqueue(&CompRaum, 101, 5);
    enqueue(&CompRaum, 102, 12);
    enqueue(&CompRaum, 103, 3);

    printf("Queue nach dem Einfuegen:\n");
    print_queue(&CompRaum);

    printf("Erstes Element: %d\n", peek(&CompRaum));

    printf("Entfernt: %d\n", dequeue(&CompRaum));
    printf("Queue nach dem ersten dequeue:\n");
    print_queue(&CompRaum);

    printf("Entfernt: %d\n", dequeue(&CompRaum));
    printf("Entfernt: %d\n", dequeue(&CompRaum));

    printf("Leer? %d\n", isEmpty(&CompRaum));

    clear_queue(&CompRaum);

    printf("Nach clear_queue:\n");
    printf("Leer? %d\n", isEmpty(&CompRaum));
    printf("Erstes Element: %d\n", peek(&CompRaum));
    printf("Entfernt: %d\n", dequeue(&CompRaum));

    return 0;
}
