#include "patient.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void init_queue (Queue *p_queue)
{
    p_queue->front = NULL;
    p_queue->rear = NULL;
}

Patient *create_patient (int id, char name[])
{
    Patient *newPatient = malloc (sizeof *newPatient);
    if (newPatient == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return NULL;
    }
    newPatient->id = id;
    strcpy(newPatient->name, name);
    newPatient->next = NULL;

    return newPatient;
}


void enqueue (Queue *p_queue , Patient *p_patient)
{
    if (p_queue->front == NULL && p_queue->rear == NULL)
    {
        p_queue->front = p_patient;
        p_queue->rear = p_patient;
    }
    p_queue->rear->next = p_patient;
    p_queue->rear = p_patient;
}


void dequeue (Queue *p_queue)
{
    if (p_queue == NULL)
    {
        printf("Die Liste ist leer.\n");
        return;
    }
    
    Patient *temp = p_queue->front;
    p_queue->front = p_queue->front->next;

    if (p_queue->front == NULL)
    {
        p_queue->rear = NULL;  // p_queue.rear = 0 setzen, nachdem ein element gelöscht wurde und die liste danach leer ist. 
    }
    
    free (temp);
}

void print_queue (Queue *p_queue)
{
    if (p_queue->front == NULL && p_queue->rear == NULL)
    {
        printf("Die Liste ist leer.\n");
        return;
    }
    
    Patient *iter = p_queue->front;
    while (iter != NULL)
    {
        printf("ID: %d  , Name: %s\n", iter->id, iter->name);
        iter = iter->next;
    }
    
}


void delete_queue (Queue *p_queue)
{
    if (p_queue->front == NULL && p_queue->rear == NULL)
    {
        printf("Die Liste ist leer.\n");
    }
    
    while (p_queue->rear != NULL)
    {
        dequeue(p_queue);
    }
    
}

int count_patient (Queue *p_queue)
{
    int count = 0;

    if (p_queue == NULL || p_queue->front == NULL)
    {
        printf("Die Liste ist leer.\n");
        return 0;
    }

    Patient *iterator = p_queue->front;
    while (iterator != NULL)
    {
        count = count + 1;
        iterator = iterator->next;
    }
    return count;

}

Patient *find_patient_by_id (Queue *p_queue , int id)
{
    if (p_queue->front == NULL && p_queue->rear == NULL)
    {
        printf("Die Liste ist leer.");
        return NULL;
    }
    
    Patient *iterator = p_queue->front;
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


void peek_front (Queue *p_queue)
{
    if (p_queue->front == NULL)
    {
        printf("Die Liste ist leer.\n");
        return;
    }
    
    printf("Der erst Patient ist:  ID: %d , Name: %s", p_queue->front->id, p_queue->front->name);

}