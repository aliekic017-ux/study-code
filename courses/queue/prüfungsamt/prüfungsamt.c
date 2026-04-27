#include "prüfungsamt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void init_queue (Queue *p_queue)
{
    p_queue->front = NULL;
    p_queue->rear = NULL;
}

Student *create_student (int martikelnummer, char name[], float notenschnitt)
{
    Student *new_Student = malloc (sizeof *new_Student);
    if (new_Student == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return NULL;
    }
    new_Student->martikelnummer = martikelnummer;
    new_Student->notenschnitt = notenschnitt;
    strcpy(new_Student->name, name);
    new_Student->next = NULL;

    return new_Student;

}

void enqueue(Queue *p_queue, Student *p_student)
{
    if (p_queue == NULL || p_student == NULL )
    {
        return;
    }

    if (p_queue->front == NULL && p_queue->rear == NULL)
    {
        p_queue->front = p_student;
        p_queue->rear = p_student;
        return;
    }
    
    p_queue->rear->next = p_student;
    p_queue->rear = p_student;

}

void dequeue (Queue *p_queue)
{
    if (p_queue->front == NULL)
    {
        printf("Die Liste ist leer.\n");
        return;
    }
    Student *tmep = p_queue->front;
    p_queue->front = p_queue->front->next;
    
    if (p_queue->front == NULL)
    {
        p_queue->rear = NULL;
    }
    free(tmep);
}

void print_queue (Queue *p_queue)
{   
    if (p_queue->front == NULL)
    {
        printf("Die Liste ist leer.\n");
        return;
    }

    printf("Studentenliste: \n");


    Student *iterator = p_queue->front;
    while (iterator != NULL)
    {
        printf(" Martikelnummer: %d , Name: %s , Notenschnitt: %.2f\n", iterator->martikelnummer, iterator->name, iterator->notenschnitt);
        iterator = iterator->next;
    }
    

}

void delete_queue (Queue *p_queue)
{
    if (p_queue->front == NULL)
    {
        printf("Die Liste ist leer\n");
        return;
    }
    
    while (p_queue->front != NULL)
    {
        dequeue(p_queue);
    }
    
}

Student *find_student_by_martikelnummer (Queue *p_queue, int martikelnummer)
{
    if ( p_queue == NULL || p_queue->front == NULL)
    {
        printf("Die Liste ist leer");
        return NULL;
    }
    
    Student *temp = p_queue->front;
    while (temp != NULL)
    {
        if (temp->martikelnummer == martikelnummer)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
     
}

int count_students (Queue *p_queue)
{
    if (p_queue == NULL)
    {
        printf("Die Liste ist leer\n");
        return -1;
    }
    
    int counter = 0;
    Student *iterator = p_queue->front;
    while (iterator != NULL)
    {
        counter = counter + 1;
        iterator = iterator->next;
    }
    
    return counter;
}

void peek_front (Queue *p_queue)
{
    if (p_queue == NULL || p_queue->front == NULL)
    {
        printf("Die Liste ist leer");
        return;
    }
    printf("Martikelnummer: %d , Name: %s , Notenschnitt: %.2f\n", p_queue->front->martikelnummer, p_queue->front->name, p_queue->front->notenschnitt);


}