#include "patientenliste.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void init_list (Liste *p_liste)
{
    p_liste->head = NULL;
}

Patient *create_patient (int id, char name [])
{
    Patient *newPatient = malloc(sizeof *newPatient);
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

void append_patient (Liste *p_liste , Patient *p_patient)
{
    if (p_liste->head == NULL)
    {
        p_liste->head = p_patient;
        return;
    }
    
    Patient *iter = p_liste->head;
    while (iter->next != NULL)
    {
        iter = iter->next;
    }
    iter->next = p_patient;
}

void print_liste (Liste *p_liste)
{
    if (p_liste->head == NULL)
    {
        printf("Die Liste ist leer. \n");
        return;
    }
    printf("Patientenliste: \n");

    Patient *iter = p_liste->head;
    while (iter != NULL)
    {
        printf ("Name: %s , ID: %d \n", iter->name, iter->id);
        iter = iter->next;
    }
    
}

void delete_first_person (Liste *p_liste)
{
    if (p_liste->head == NULL)
    {
        printf("Die Liste ist leer.\n");
        return;
    }

    Patient *temp = p_liste->head;
    p_liste->head = p_liste->head->next;
    
    free(temp);

}

void delete_list (Liste *p_liste)
{
    if (p_liste->head == NULL)
    {
        printf("Die Liste ist leer\n");
        return;
    }
    
    while (p_liste->head != NULL)
    {
        delete_first_person(p_liste);

    }
}