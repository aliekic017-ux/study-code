#include "undo.h"
#include <stdio.h>
#include <stdlib.h>

void init_stack (Stack *stack)
{
    stack->top = NULL;
}

Action *create_action (int id)
{
    Action *newAction = malloc(sizeof *newAction);
    if (newAction == NULL)
    {
        printf("Speicherallokation fehlgeschlagen.\n");
        return NULL;
    }
    newAction->id = id;
    newAction->next = NULL;

    return newAction;
}

void push (Stack *stack , Action *p_action)
{
    if (p_action == NULL)
    {
        return;
    }
    p_action->next = stack->top;
    stack->top = p_action;
}


void pop (Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("Die Liste ist leer - es gibt kein Element zu entfernen.\n");
        return;
    }
    Action *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
}


void print_stack (Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("Die Liste ist leer.\n");
        return;
    }
    Action *iterator = stack->top;
    while (iterator != NULL)
    {
        printf("ID: %d\n", iterator->id);
        iterator = iterator->next;
    }
    
}