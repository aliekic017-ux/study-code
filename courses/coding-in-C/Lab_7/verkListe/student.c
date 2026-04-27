#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void init_liste(liste *p_liste)
{
    p_liste->head = NULL;
}

student *create_student (int martikelnummer, char name [], float notenschnitt)
{
    student *new_student = malloc (sizeof *new_student);
    if (new_student == NULL)
    {
        printf("Speicheralloaktion fehlgeschlagen");
        return NULL;
    }
    new_student->martikelnummer = martikelnummer;
    strcpy(new_student->name, name);
    new_student->notenschnitt = notenschnitt;
    new_student->next = NULL;

    return new_student;
}


void append_student (liste *p_liste , student *p_student)
{
    if (p_liste == NULL || p_student == NULL)
    {
        return;
    }
    if (p_liste->head == NULL)
    {
        p_liste->head = p_student;
        return;
    }
    
    student *iterator = p_liste->head;
    while (iterator->next != NULL)
    {
        iterator = iterator->next;
    }
    iterator->next = p_student;
}


void print_list (liste *p_liste)
{
    if (p_liste->head == NULL)
    {
        printf("Die Liste ist leer");
        return;
    }

    student *iterator = p_liste->head;
    while(iterator != NULL)
    {
        printf("Martikelnummer: %d,  Name: %s,  Notenschnitt: %f\n", iterator->martikelnummer, iterator->name, iterator->notenschnitt);
        iterator = iterator->next;
    }

}

void delete_first_student (liste *p_liste)
{
    if (p_liste->head == NULL)
    {
        printf("Die Liste ist leer");
        return;
    }
    student *temp = p_liste->head;
    p_liste->head = p_liste->head->next;

    free(temp);
}

void delete_list (liste *p_liste)
{
    if (p_liste->head == NULL)
    {
        printf("Die Liste ist leer");
        return;
    }

    while (p_liste->head != NULL)
    {
        delete_first_student(p_liste);
    }
    
}