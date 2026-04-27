#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct node 
{
    int data;
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
    
void push(stack *Stack, int data)
{
    node *newElement = malloc(sizeof(*newElement));
    if (newElement == NULL)
    {
        printf("Speucherallokation fehlgeschlagen");
        return ;
    }
    newElement->data = data;
    newElement->next = Stack->top;
    Stack->top = newElement;
    
}

int pop (stack *Stack)
{
    if (Stack->top == NULL)
    {
        printf("Die Liste ihr leer");
        return -1;
    }
    
    node *temp = Stack->top;

    int data = temp->data;

    Stack->top = Stack->top->next;
    free(temp);

    return data;
    
}

int peek (stack *Stack)
{
    if (Stack->top == NULL)
    {
        printf("Die Liste ist leer");
        return -1;
    }
    
    node *temp = Stack->top;

    int data = temp->data;

    return data;
}

int isEmpty (stack *Stack)
{
    int isEmpty;

    if (Stack->top == NULL)
    {
        printf("Die Liste ist leer");
        isEmpty = 1;
    }
    else
    {
        isEmpty = 0;
    }
    printf(" Die Liste ist (leer = 1 / sonst = 0): %d", isEmpty);

    return isEmpty;
}

void print_stack (stack *Stack)
{
    node *temp = Stack->top;

    while (temp != NULL)
    {
        printf("Stack: %d \n", temp->data);
        temp = temp->next;
    }
    
}

void free_stack (stack *Stack)
{
    node *temp;

    while (Stack->top != NULL)
    {
        temp = Stack->top;
        Stack->top = Stack->top->next;
        free(temp);
    
    }
    
}

int main ()
{

    stack Stack;
    init_stack(&Stack);

    int weiter = 1;
    int value;
    

    while (weiter == 1)
    {
    
        printf("Bitte geben Sie eine Ganzzahl ein:  ");
        if (scanf("%d", &value) != 1)
        {
            printf("Fehler bei der Eingabe des Wertes");
            return -1;

        }
       

        printf("Noch eine Zahl auf den Stack ablegen (ja = 1 / nein = 0): ");
        if (scanf ("%d", &weiter) != 1)
        {
            printf("Ungültige Eingabe");
            return -1;
        }

        push(&Stack, value);
        printf("Stack vorher: \n");
        print_stack(&Stack);

    }
    


    //push(&Stack, value);
    //push(&Stack, value);
    //push(&Stack, value);
    //push(&Stack, value);

    //printf("Stack vorher: \n");
    //print_stack(&Stack);

    

    pop(&Stack);
    
    printf("Stack nachher: \n");
    print_stack(&Stack);


    isEmpty(&Stack);

    free_stack(&Stack);

    return 0;

}
