/*
*
* File: 5main.c 
*
* Description: Programmierung eines Stacks mit der Ablage des eingegeben Worts
*
*/
#include <stdio.h>
#include <stdlib.h>


typedef struct node 
{
    char data; 
    struct node *next;
}node;

typedef struct stack
{
    struct node *top;
}stack;


void init_stack (stack *Stack)
{
    Stack->top = NULL;

}

void push (stack *Stack, char data)
{
    node *newElement = malloc (sizeof(*newElement));
    if (newElement == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return;
    }
    newElement->data = data;
    newElement->next = Stack->top;
    Stack->top = newElement;

}

char pop(stack *Stack)
{
    if (Stack->top == NULL)
    {
        printf("Die Liste ist leer");
        return '\0';
    }
    

    node *temp = Stack->top;

    char data = temp->data;
    Stack->top = Stack->top->next;

    free(temp);

    return data;
}

int isEmpty (stack *Stack)
{
    int isEmpty;

    if (Stack->top == NULL)
    {
        printf("Die Liste ist leer");
        return 1;
    }
    else 
    {
        isEmpty = 0; 
        return 0;
    }

    return isEmpty;
}

void free_stack (stack *Stack)
{
    node *temp;
     while (Stack->top != NULL)
     {
        temp = Stack->top;
        Stack->top = Stack->top->next;

        free (temp);
     }

       
}

void print_stack (stack *Stack)
{
    node *temp = Stack->top;

    while (temp != NULL)
    {
        printf("%c", temp->data);
        temp = temp->next;

    }
    
}



int main ()
{
    stack Stack;
    init_stack(&Stack);

    char Eingabe [100];
    printf("Gebe ein Wort ein (max. 100 Zeichen: ");
    if (scanf("%99s", Eingabe) != 1)
    {
        printf("Fehler bei der Eingabe");
        return 1;

    }
    int i = 0;

    while (Eingabe[i] != '\0')
    {
        push(&Stack, Eingabe[i]);
        i++;
    }

    print_stack(&Stack);


    return 1;   
    
}