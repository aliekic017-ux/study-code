#include "meldung.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void init_stack (Stack *p_stack)
{
    p_stack->p_top = NULL;
}

Message *create_message (int id, char *text, int priorität)
{
    Message *newMessage = malloc (sizeof *newMessage);
    if (newMessage == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return NULL;
    }
    newMessage->text = malloc(strlen(text)+1);
    if (newMessage->text == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        free(newMessage);
        return NULL;
    }
    newMessage->id = id;
    strcpy(newMessage->text, text);
    newMessage->priorität = priorität;
    newMessage->p_next = NULL;

    return newMessage;
}

void push (Stack *p_stack, Message *p_message)
{
    if (p_message == NULL)
    {
        return;
    }
    
    if (p_stack->p_top == NULL)
    {
        p_stack->p_top = p_message;
        return;
    }
    p_message->p_next = p_stack->p_top;
    p_stack->p_top = p_message;
}

void pop (Stack *p_stack)
{
    if (p_stack->p_top == NULL)
    {
        printf("Die Liste ist leer.\n");
        return;
    }
    
    Message *temp = p_stack->p_top;
    p_stack->p_top = p_stack->p_top->p_next;
    free(temp->text);
    free(temp);
}

void print_stack (Stack *p_stack)
{
    if (p_stack->p_top == NULL)
    {
        printf("Die Liste ist leer.");
        return;
    }
    Message *iterator = p_stack->p_top;
    while (iterator != NULL)
    {
        printf("ID: %d, Text: %s, Priorität: %d\n", iterator->id, iterator->text, iterator->priorität);
        iterator = iterator->p_next;
    }
    
}

int count_stack (Stack *p_stack)
{
    int counter = 0;
    if (p_stack->p_top == NULL)
    {
        printf("Die Liste ist leer.\n");
        return 0;
    }
    
    Message *iterator = p_stack->p_top;
    while (iterator != NULL)
    {
        counter = counter + 1;
        iterator = iterator->p_next;
    }
    return counter;

}

void free_stack (Stack *p_stack)
{
    if (p_stack->p_top == NULL)
    {
        printf("Die Liste ist leer.\n");
        return;
    }
    while (p_stack->p_top != NULL)
    {
        pop(p_stack);
    }
    
}
