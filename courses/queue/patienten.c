#include "patienten.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_queue (Queue *p_queue)
{
    p_queue->front = NULL;
    p_queue->rear = NULL;
}

Patient *create_patient(int id, char *name)
{
    Patient *newPatient = malloc(sizeof *newPatient);
    if (newPatient == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return NULL;
    }
    
    newPatient->name = malloc(strlen(name)+1);
    if (newPatient->name == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return NULL;
    }
    newPatient->id = id;
    strcpy(newPatient->name, name);
    newPatient->next = NULL;

    return newPatient;
}

void enqueue (Queue *p_queue, Patient *p_patient)
{
    if (p_queue == NULL || p_patient == NULL)
    {
        return;
    }
    
    if (p_queue->front == NULL && p_queue->rear == NULL)
    {
        p_queue->front = p_patient;
        p_queue->rear = p_patient;
        return;  
    }
    p_queue->rear->next = p_patient;
    p_queue->rear = p_patient;
    
}

void dequeue (Queue *p_queue)
{
    if (p_queue == NULL || p_queue->front == NULL)
    {
        printf("Die Liste ist leer");
        return;
    }
    Patient *temp = p_queue->front;
    p_queue->front = p_queue->front->next;

    if (p_queue->front == NULL)
    {
        p_queue->rear = NULL;
    }
    
    
    free (temp->name);
    free(temp);
}

void print_queue (Queue *p_queue)
{
    if (p_queue->front == NULL || p_queue == NULL)
    {
        return;
    }
    
    Patient *iterator = p_queue->front;
    while (iterator != NULL)
    {
        printf("ID: %d  Name: %s\n", iterator->id, iterator->name);
    }
    

}