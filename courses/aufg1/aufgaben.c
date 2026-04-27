#include "aufgaben.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void init_list (List *liste)
{
    liste->head = NULL;
}

void add_task (List *liste, int id, int priority, char *text)
{
    task *newTask = malloc (sizeof *newTask);
    if (newTask == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return;
    }

    newTask->text = malloc(strlen(text)+1);

    if (newTask->text == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        free(newTask);
        return;
    }
    
    strcpy(newTask->text, text);
    newTask->id = id;
    newTask->priority = priority;
    newTask->next = NULL;


    if (liste->head == NULL)
    {
        liste->head = newTask;
        return;
    }

    task *iter = liste->head;
    while (iter->next != NULL)
    {
        iter = iter->next;
    }
    iter->next = newTask;

    
}

void remove_task (List *liste)
{
    if (liste->head == NULL)
    {
        printf ("Die Liste ist leer.\n");
        return;
    }
    
    task *temp = liste->head;
    liste->head = liste->head->next;
    free(temp->text);
    free(temp);
}

void print_list (List *liste)
{
    if (liste->head == NULL)
    {
        printf("Die Liste ist leer");
        return;
    }
    task *iterator = liste->head;
    while (iterator != NULL)
    {
        printf("ID: %d , Priority: %d , Text: %s\n", iterator->id, iterator->priority, iterator->text);
        iterator = iterator->next;
    }
    
}

void read_file (List *liste, char *filename)
{
    FILE *open = fopen(filename, "r");
    if (open == NULL)
    {
        printf("Fehler beim Öffnen der Datei");
        return;
    }

    char zeile[200];
    int id = 0;
    int priority = 0;
    char text [100];

    while (fgets(zeile, sizeof zeile, open) != NULL)
    {
        if (sscanf(zeile, "%d;%d;%99s", &id, &priority, text) == 3)
        {
            add_task(liste, id, priority, text);
        }
    }
    fclose (open);

}

void write_file (List *liste , char *filename)
{
    FILE *open = fopen(filename, "w");
    if (open == NULL)
    {
        printf("Fehler beim Öffnen der Datei");
        return;
    }
    task *iter = liste->head;
    while (iter != NULL)
    {
        fputs(iter->text, open);
        fputs("\n", open);
        iter = iter->next;
    }
    
    fclose (open);
}