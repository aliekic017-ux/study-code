#include <stdio.h>
#include <stdlib.h>
#include "browser.h"

void init_stack(Stack *p_stack)
{
    p_stack->p_top = NULL;

}

Page *create_page(int id, int page_number)
{
    Page *p_newPage = malloc (sizeof *p_newPage);
    if (p_newPage == NULL)
    {
        printf("Speicherallokation fehlgeschlagen.\n");
        return NULL;
    }
    p_newPage->page_number = page_number;
    p_newPage->id = id;
    p_newPage->next = NULL;

    return p_newPage;
}

void push (Stack *p_stack, Page *p_page)
{
    if (p_stack == NULL || p_page == NULL)
    {
        return;
    }
    p_page->next = p_stack->p_top;
    p_stack->p_top = p_page;

}

void pop (Stack *p_stack)
{
    if (p_stack == NULL || p_stack->p_top == NULL)
    {
        return;
    }
    
    Page *temp = p_stack->p_top;
    p_stack->p_top = p_stack->p_top->next;

    free (temp);

}

void print_stack(Stack *p_stack)
{
    if (p_stack == NULL || p_stack->p_top == NULL)
    {
        printf("Die Liste ist leer\n");
        return;
    }
    
    Page *temp = p_stack->p_top;

    printf("Aktuelle Browserliste: \n");
    while (temp != NULL)
    {
        printf("ID: %d  Page_Number: %d\n", temp->id, temp->page_number);
        temp = temp->next;
    }
    
}
