#include "krankenhaus.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_queue (Queue *p_queue)
{
    p_queue->front = NULL;
    p_queue->rear = NULL;

}


patient *create_patient (int patient_id, char *name, char *symptom)
{
    patient *new_patient = malloc (sizeof *new_patient);
    if (new_patient == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return NULL;
    }
    new_patient->symptom = malloc (strlen(symptom)+1);
    new_patient->name = malloc (strlen(name)+1);

    if (new_patient->name == NULL || new_patient->symptom == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        free(new_patient->name);
        free(new_patient->symptom);
        free(new_patient);
        return NULL;
    }
     new_patient->patient_id = patient_id;
     strcpy(new_patient->symptom, symptom);
     strcpy(new_patient->name, name);
     new_patient->next = NULL;

     return new_patient;
}


// hinten ein neues Element hinzufügen
void enqueue (Queue *p_queue, patient *p_patient)
{
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
    if (p_queue->front == NULL && p_queue->rear == NULL)
    {
        printf("Die Liste ist leer \n- es gibt nichts zu löschen - ");
        return;
    }

    patient *temp = p_queue->front;
    p_queue->front = p_queue->front->next;

    if (p_queue->front == NULL)
    {
        p_queue->rear = NULL;
    }
    

    free(temp->name);
    free(temp->symptom);
    free(temp);
}

void print_queue (Queue *p_queue)
{
    if (p_queue->front == NULL && p_queue->rear == NULL)
    {
        printf("Die Liste ist leer\n");
        return;
    }
    
    printf(" PAtienten in der Warteschlange: \n");
    patient *iterator = p_queue->front;
    while (iterator != NULL)
    {
        printf("ID: %d  Name: %s  Symptome: %s \n ", iterator->patient_id, iterator->name, iterator->symptom);
        iterator = iterator->next;
    }
    
}

void delete_queue (Queue *p_queue)
{
    if (p_queue->rear == NULL && p_queue->front == NULL)
    {
        printf("Die Liste ist leer!!\n");
    }
    
    while (p_queue->front != NULL)
    {
        dequeue(p_queue);
    }
    
}

void peek_front (Queue *p_queue)
{
    if (p_queue->front == NULL && p_queue->rear == NULL)
    {
        printf("Die Liste ist leer\n - Es kann kein Element angezeigt werden - ");
        return;
    }

    patient *temp = p_queue->front;
    printf ("Der erste Patient ist: ID: %d , Name:  %s , Symptom: %s", temp->patient_id, temp->name, temp->symptom);
    

}

patient *find_patient_by_id (Queue *p_queue, int patient_id)
{
    if (p_queue == NULL || p_queue->front == NULL)
    {
        return NULL;
    }
    
    patient *iterator = p_queue->front;
    while (iterator != NULL)
    {
        if (iterator->patient_id == patient_id)
        {
            printf("Der Patient mit der ID: %d hat den Namen: %s und das Symptom: %s \n",iterator->patient_id, iterator->name, iterator->symptom);
            return iterator;
        }
        iterator = iterator->next;
    }
    return NULL;
}


patient *find_patient_by_name (Queue *p_queue, char *name)
{
    if (p_queue == NULL || p_queue->front == NULL)
    {
        return NULL;
    }
    
    patient *iterator = p_queue->front;
    while (iterator != NULL)
    {
        if (strcmp(iterator->name, name) == 0)
        {
            printf("Der Patient mit dem Namen: %s hat die ID: %d und die Symptome: %s \n", iterator->name, iterator->patient_id, iterator->symptom);
            return iterator;
        }
        iterator = iterator->next;
    }
    return NULL;
}



patient *find_patient_by_symptom (Queue *p_queue, char *symptom)
{
    if (p_queue == NULL || p_queue->front == NULL)
    {
        return NULL;
    }

    patient *iterator = p_queue->front;
    while (iterator != NULL)
    {
        if (strcmp(iterator->symptom, symptom) == 0)
        {
            return iterator;
        }
        iterator = iterator->next;
    }
    return NULL;
    
}