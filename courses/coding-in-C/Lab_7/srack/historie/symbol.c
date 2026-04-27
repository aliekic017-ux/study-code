#include "symbol.h"
#include <stdio.h>
#include <stdlib.h>

void init_stack (Stack *p_stack)
{
    p_stack->p_top = NULL;
}

Symbol *create_symbol (int id, char symbol)
{
    Symbol *newElement = malloc (sizeof *newElement);
    if (newElement == NULL)
    {
        printf("Speicherallokation fehlgeschlagen\n");
        return NULL;
    }
    newElement->id = id;
    newElement->symbol = symbol;
    newElement->next = NULL;

    return newElement;
}

void push (Stack *p_stack, Symbol *p_symbol)
{
    if (p_stack == NULL || p_symbol == NULL)
    {
        return;
    }
    
    p_symbol->next = p_stack->p_top;
    p_stack->p_top = p_symbol;

}

void pop (Stack *p_stack)
{
    if (p_stack == NULL || p_stack->p_top == NULL)
    {
        printf("Die Liste ist leer");
        return;
    }
    Symbol *p_temp = p_stack->p_top;
    p_stack->p_top = p_stack->p_top->next;

    free (p_temp);
    
}

void print_stack (Stack *p_stack)
{
    if (p_stack == NULL || p_stack->p_top == NULL)
    {
        printf("Die Liste ist leer");
        return;
    }
    
    printf("Die Liste hat folgenden Inhalt: \n");
    Symbol *iterator = p_stack->p_top;
    while (iterator != NULL)
    {
        printf("ID: %d Symbol: %c\n", iterator->id, iterator->symbol);
        iterator = iterator->next;
    }
    
}