#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node
{
    int value;
    struct Node *next;

}Node;

typedef struct Stack
{
    Node *top;
}Stack;



void init_stack(Stack *stack)
{
    stack->top = NULL;
}


// ein neues Element oben auf den Stapel draufmachen 

void push (Stack *Stack , int value)
{
    Node *newNode = malloc (sizeof(*newNode));

    if (newNode == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return ;
    }
    newNode->value = value;
    newNode->next = Stack->top;   // neues Element ist nun neues top, da das jetzt das oberste element ist 
    Stack->top = newNode;

}

// entfernen des obersten Elements; -->Wert des gelöschten Elements wird zurückgegeben

int pop (Stack *Stack)
{
    if (Stack->top == NULL)
    {
        printf("Das Stack ist leer.");
        return -1;
    }

    Node *temp = Stack->top;
    int value = temp->value;

    Stack->top = Stack->top->next;

    free(temp);
    return value;
}


void print_stack (Stack *Stack)
{
    Node *temp = Stack->top;
    
    while (temp != NULL)
    {
        printf("%d\n", temp->value);
        temp = temp->next;
    }
    
}

int main ()
{
    Stack Stack;

    init_stack(&Stack);

    push(&Stack, 10);
    push(&Stack, 20);
    push(&Stack, 30);

    printf("Stack: \n");
    print_stack(&Stack);

    printf("Pop: %d \n", pop(&Stack));

    printf("Stack danach: \n");
    print_stack(&Stack);

    return 0;

}