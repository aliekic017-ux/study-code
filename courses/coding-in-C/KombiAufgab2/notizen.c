#include "notizen.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void init_list (NoteList *p_list)
{
    p_list->head = NULL;
}

Note *create_note (int id, const char *text)
{
    Note *newElement = malloc(sizeof *newElement);
    if (newElement == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return NULL;
    }

    newElement->text = malloc(strlen(text)+1);
    if (newElement->text == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        free(newElement);
        return NULL;
    }
    
    strcpy(newElement->text, text);
    newElement->id = id;
    newElement->p_next = NULL;

    return newElement;
}

void append_note (NoteList *p_list, Note *p_note)
{
    if (p_note == NULL)
    {
        return;
    }
    if (p_list->head == NULL)
    {
        p_list->head = p_note;
        return;
    }
    
    Note *iterator = p_list->head;
    while (iterator->p_next != NULL)
    {
        iterator = iterator->p_next;
    }
    iterator->p_next = p_note;
    
}

void print_list (NoteList *p_list)
{
    if (p_list->head == NULL)
    {
        printf("Die Liste ist leer.\n");
        return;
    }
    Note *iterator = p_list->head;
    while (iterator != NULL)
    {
        printf("ID: %d, Text: %s\n", iterator->id, iterator->text);
        iterator = iterator->p_next;
    }
}

Note *find_note_by_id (NoteList *p_list, int id)
{
    if (p_list->head == NULL)
    {
        printf("Die Liste ist leer.\n");
        return NULL;
    }
    
    Note *find_id = p_list->head;
    while (find_id != NULL)
    {
        if (find_id->id == id)
        {
            return find_id;
        }
        find_id = find_id->p_next;
    }
    return NULL;
}


void delete_first_note (NoteList *p_list)
{
    if (p_list->head == NULL)
    {
        printf("Die Liste ist leer.\n");
        return;
    }
    Note *temp = p_list->head;
    p_list->head = p_list->head->p_next;
    free(temp->text);
    free(temp);
}

int count_notes (NoteList *p_list)
{
    int counter = 0;
    if (p_list->head == NULL)
    {
        printf("Die Liste ist leer");
        return 0;
    }
    
    Note *iterator = p_list->head;
    while (iterator != NULL)
    {
        counter = counter + 1;
        iterator = iterator->p_next;
    }

    return counter;
}

void delete_list (NoteList *p_list)
{
    if (p_list->head == NULL)
    {
        return;
    }
    while (p_list->head != NULL)
    {
        delete_first_note(p_list);
    }
    
}

