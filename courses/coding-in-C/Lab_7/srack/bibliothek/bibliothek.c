 #include "bibliothek.h"
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>



 void init_stack (Stack *p_stack)
 {
    p_stack->p_top = NULL;
 }


 book *create_newbook (int isbn, char *title, char *author)
 {
    book *newbook = malloc (sizeof *newbook);
    if (newbook == NULL)
    {
        printf("Speicherallokation fehlgeschlage");
        return NULL;
    }
    newbook->title = malloc (strlen(title)+1);

    if (newbook->title == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        free(newbook->title);
        free(newbook);
        return NULL;
    }
    
    newbook->author = malloc (strlen(author)+1);

    if (newbook->author == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        free(newbook->title);
        free(newbook->author);
        free(newbook);
        return NULL;
    }
    newbook->isbn = isbn;
    strcpy(newbook->author, author);
    strcpy (newbook->title, title);
    newbook->next = NULL;

    return newbook;    
 }

void push (Stack *p_stack, book *p_book)
{
    if (p_stack == NULL || p_book == NULL)
    {
        return;
    }
    
    p_book->next= p_stack->p_top;
    p_stack->p_top = p_book;
}

void pop (Stack *p_stack)
{
    if (p_stack == NULL || p_stack->p_top == NULL)
    {
        return;
    }

    book *temp = p_stack->p_top;
    p_stack->p_top = p_stack->p_top->next;

    free (temp->title);
    free (temp->author);
    free (temp);

}

void print_stack (Stack *p_stack)
{
    if (p_stack->p_top == NULL)
    {
        printf("Die Liste ist leer");
        return;
    }

    book *iterator = p_stack->p_top;
    while (iterator != NULL)
    {
        printf("ISBN: %d  ;  AUTHOR: %s , TITLE: %s \n", iterator->isbn, iterator->author, iterator->title);
        iterator = iterator->next;
    }
    
    
}

void peek_top (Stack *p_stack)
{
    if ( p_stack == NULL ||p_stack->p_top == NULL)
    {
        printf("Der Stack ist leer.\n");
        return;
    }
    
    book *temp = p_stack->p_top;

    printf("Das oberste Bucht ist: TITLE: %s  , AUTHOR: %s  , ISBN: %d\n", temp->title, temp->author, temp->isbn );
    
}

int count_books (Stack *p_stack)
{
    int counter = 0;

    if (p_stack->p_top == NULL)
    {
        return 0;
    }
    
    book *iterator = p_stack->p_top;
    while (iterator != NULL)
    {
        counter = counter + 1;
        iterator = iterator->next;
    }
    
    return counter;
}


book *find_book_by_isbn (Stack *p_stack , int isbn)
{
    if (p_stack->p_top == NULL)
    {
        printf("Die Liste ist leer");
        return NULL;
    }
    
    book *iter = p_stack->p_top;
    while (iter != NULL)
    {
        if (iter->isbn == isbn)
        {
            return iter;
        }
        iter = iter->next;
    }
    return NULL;
}

book *find_book_by_title (Stack *p_stack , char *title)
{
    if (p_stack->p_top == NULL)
    {
        printf("Die Liste ist leer");
        return NULL;
    }

    book *iter = p_stack->p_top;
    while (iter != NULL)
    {
        if (strcmp(iter->title, title) == 0)
        {
            return iter;
        }
        iter = iter->next;
    }
    return NULL;
}

void delete_stack (Stack *p_stack)
{
    if (p_stack->p_top == NULL)
    {
        return;
    }

    while (p_stack->p_top != NULL)
    {
        pop(p_stack);
    }
    
    
}