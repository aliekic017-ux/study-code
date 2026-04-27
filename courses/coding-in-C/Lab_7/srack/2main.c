#include <string.h>
#include <stdio.h>
#include <stdlib.h>



typedef struct Node
{
    int value;
    struct Node *next;
}Node;


typedef struct Stack
{
    struct Node *top;
}Stack;


void init_stack (Stack *stack)
{
    stack->top = NULL;
} 

// Element oben auf den Stapel hinzufügen

void push (Stack *stack , int value)
{
    Node *newElement = malloc(sizeof(*newElement));
    
    if (newElement == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return ;
    }
    newElement->value = value;
    newElement->next = stack->top;
    stack->top = newElement;
}

// Element oben aus dem Stapel entnehmen, Wert des Eleements übergeben 

int pop ( Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("Das Stack ist leer");
        return -1;
    }

    Node *temp = stack->top;
    int value = temp->value;


    stack->top = stack->top->next;
    free(temp);
    
    return value;
    
    
}


void print_stack (Stack *stack)
{
    Node *temp = stack->top;

    while (temp != NULL)
    {
        printf("%d", temp->value);
        temp = temp->next;
    }

    
}

int count_stack (Stack *stack)
{
    Node *iterator = stack->top;
    int count = 0;

    while (iterator != NULL)
    {
        iterator = iterator->next;
        count = count + 1;
    }
    return count;

}

int sum_stack (Stack *stack)
{
    Node *iterator = stack->top;
    int sum = 0;

    while (iterator != NULL)
    {
        sum = iterator->value + sum;
        iterator = iterator->next;
    }
    return sum;
}

int find_max (Stack *stack)
{
    Node *iterator = stack->top;
    int max = 0;

    while (iterator != 0)
    {
        if (iterator->value > max)
        {
            max = iterator->value;
        }
        iterator = iterator->next;
        
    }
    return max;
}

int main ()
{

    Stack beispiel;

    init_stack(&beispiel);

    push(&beispiel, 2);
    push(&beispiel, 8);
    push(&beispiel, 5);
    push(&beispiel, 3);

    printf("Stack vorher: \n");
    print_stack(&beispiel);

    
    printf("\nAnzahl der Elemente: %d\n", count_stack(&beispiel));
    printf("Summe der Elemente: %d\n", sum_stack(&beispiel));
    printf("Maximum: %d\n", find_max(&beispiel));

    pop(&beispiel);

    printf("\nStack danach nach pop: \n");
    print_stack(&beispiel);
  
  
    return 0;
}
