#include "werkzeuge.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*void init_list (ToolList *p_list)
{
    p_list->p_head = NULL;
}

Tool *create_tool (int id, const char *bezeichnung, const char *zustand)
{
    Tool *new_Tool = malloc (sizeof *new_Tool);
    if (new_Tool == NULL)
    {
        printf("Speicherallokation fehlgeschlagen\n");
        return NULL;
    }
    new_Tool->bezeichnung = malloc(strlen(bezeichnung)+1);
    if (new_Tool->bezeichnung == NULL)
    {
        printf("Speicherallokation fehlgeschlagen\n");
        free(new_Tool);
        return NULL;
    }
    new_Tool->zustand = malloc(strlen(zustand)+1);
    if (new_Tool->zustand == NULL)
    {
        printf("Speicherallokation fehlgeschlagen\n");
        free(new_Tool->bezeichnung);
        free(new_Tool);
        return NULL;
    }
    
    strcpy(new_Tool->bezeichnung, bezeichnung);
    strcpy(new_Tool->zustand, zustand);
    new_Tool->id = id;
    new_Tool->p_next = NULL;

    return new_Tool;
}

void append_tool (ToolList *p_list, Tool *p_tool)
{
    if (p_tool == NULL)
    {
        return;
    }
    if (p_list->p_head == NULL)
    {
        p_list->p_head = p_tool;
        return;
    }

    Tool *iterator = p_list->p_head;
    while (iterator->p_next != NULL)
    {
        iterator = iterator->p_next;
    }
    iterator->p_next = p_tool;
    
}

void print_list (ToolList *p_list)
{
    if (p_list->p_head == NULL)
    {
        printf("Die Liste ist leer.\n");
        return;
    }
    
    Tool *iterator = p_list->p_head;
    while (iterator != NULL)
    {
        printf("ID: %d, Bezeichnung: %s, Zustand: %s\n", iterator->id, iterator->bezeichnung, iterator->zustand);
        iterator = iterator->p_next;
    }
    
}

Tool *find_by_id (ToolList *p_list, int id)
{
    if (p_list->p_head == NULL)
    {
        printf("Die Liste ist leer.\n");
        return NULL;
    }
    Tool *find_id = p_list->p_head;
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

void delete_first_tool (ToolList *p_list)
{
    if (p_list->p_head == NULL)
    {
        printf("DIe Liste ist leer.\n");
        return;
    }
    
    Tool *temp = p_list->p_head;
    p_list->p_head = p_list->p_head->p_next;
    free(temp->zustand);
    free(temp->bezeichnung);
    free(temp);
}

int count_tools (ToolList *p_list)
{
    int counter = 0;
    if (p_list->p_head == NULL)
    {
        return 0;
    }

    Tool *iterator = p_list->p_head;
    while (iterator != NULL)
    {
        counter = counter + 1;
        iterator = iterator->p_next;
    }
    
    return counter;
}

void delete_list (ToolList *p_list)
{
    if (p_list->p_head == NULL)
    {
        printf("Die Liste ist leer.\n");
        return;
    }
    
    while (p_list->p_head != NULL)
    {
        delete_first_tool(p_list);
    }
    
}
*/




void init_list (ToolList *p_list)
{
    p_list->p_head = NULL;
}

Tool *create_tool(int id, const char *bezeichnung, const char *zustand)
{
    Tool *newTool = malloc (sizeof *newTool);
    if (newTool == NULL)
    {
        printf("Speicherallokation fehlgeschlagen.\n");
        return NULL;
    }

    newTool->bezeichnung = malloc (strlen(bezeichnung)+1);
    newTool->zustand = malloc (strlen(zustand)+1);

    if (newTool->bezeichnung == NULL || newTool->zustand == NULL)
    {
        printf("Speicherallokation fehlgeschlagen.\n");
        free(newTool->bezeichnung);
        free(newTool->zustand);
        free(newTool);
        return NULL;
    }
    strcpy(newTool->bezeichnung, bezeichnung);
    strcpy(newTool->zustand, zustand);
    newTool->id = id;
    newTool->p_next = NULL;
    

    return newTool;
}

void append_tool (ToolList *p_list, Tool *p_tool)
{
    if (p_tool == NULL)
    {
        return;
    }
    if (p_list->p_head == NULL)
    {
        p_list->p_head = p_tool;
        return;
    }

    Tool *iterator = p_list->p_head;
    while (iterator->p_next != NULL)
    {
        iterator = iterator->p_next;
    }
    iterator->p_next = p_tool;
}

void print_list (ToolList *p_list)
{
    if (p_list->p_head == NULL)
    {
        printf("Die liste ist leer.\n");
        return;
    }
    
    Tool *iterator = p_list->p_head;
    while (iterator != NULL)
    {
        printf("ID: %d, Bezeichnung: %s, Zustand: %s\n", iterator->id, iterator->bezeichnung, iterator->zustand);
        iterator = iterator->p_next;
    }
    
}

Tool *find_by_id (ToolList *p_list, int id)
{
    if (p_list->p_head == NULL)
    {
        printf("DIe Liste ist leer.\n");
        return NULL;
    }
    
    Tool *find_id = p_list->p_head;
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

void delete_first_tool (ToolList *p_list)
{
    if (p_list->p_head == NULL)
    {
        printf("Die Liste ist leer.\n");
        return;
    }
    
    Tool *temp = p_list->p_head;
    p_list->p_head = p_list->p_head->p_next;
    free(temp->bezeichnung);
    free(temp->zustand);
    free(temp);
}