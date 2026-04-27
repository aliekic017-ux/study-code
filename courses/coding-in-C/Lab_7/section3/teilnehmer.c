/*
* File: teilnehmer.c
* Description: Programmierung einer verketteten Liste in C für die Verwaltung einer Teilnehmerliste
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct teilnehmer
{
    int student_id;
    int points_zahl;
    struct teilnehmer *next;
}teilnehmer;

typedef struct liste
{
    struct teilnehmer *head;
}liste;


void init_list (liste *kurs)
{
    kurs->head = NULL;
}

int is_empty (liste *kurs)
{
    int is_empty = 1;

    if (kurs->head == NULL)
    {
        is_empty = 1;
    }
    else 
    {
        is_empty = 0;
    }
    
    return is_empty;
}


void append_teilnehmer (liste *kurs, int student_id, int points_zahl)
{
    teilnehmer *neu = malloc(sizeof *neu);
    if (neu == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return;

    }
    neu->student_id = student_id;
    neu->points_zahl = points_zahl;
    neu->next = NULL;

    if (kurs->head == NULL)
    {
        kurs->head = neu;
        return;
    }
    teilnehmer *temp = kurs->head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = neu;
    
}

void prepend_teilnehmer (liste *kurs , int student_id, int points_zahl)
{
    teilnehmer *neu2 = malloc (sizeof *neu2);
    if (neu2 == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return;
    }
    neu2->points_zahl = points_zahl;
    neu2->student_id = student_id;


    teilnehmer *temp = kurs->head;
    neu2->next = temp;

    if (kurs->head == NULL)
    {
        kurs->head = neu2;
    }
    kurs->head = neu2;

    return;
}

void print_list (liste *kurs)
{
    if (kurs->head == NULL)
    {
        printf("Die Liste ist leer");
        return;
    }

    teilnehmer *tmep = kurs->head;
    while (tmep != NULL)
    {
        printf("ID: %d  Punkte: %d \n ", tmep->student_id, tmep->points_zahl);
        tmep = tmep->next;
    }
    return;
}

int main()
{
    liste k2;
    init_list(&k2);

    printf(" Die Liste ist leer = 1 , nicht leer = 0 : %d \n ", is_empty(&k2));
    append_teilnehmer(&k2, 301 , 12);
    append_teilnehmer(&k2, 302 , 18);
    append_teilnehmer(&k2, 303 , 9);
    append_teilnehmer(&k2, 300 , 20);


    print_list(&k2);
    printf("\n Die Liste ist leer = 1 , nicht leer = 0 : %d \n ", is_empty(&k2));
    return 0;
}
