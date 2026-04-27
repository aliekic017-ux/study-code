#ifndef UNDO_H
#define UNDO_H

typedef struct Action
{
    int id;
    struct Action *next;
}Action;


typedef struct Stack 
{
    struct Action *top;
}Stack;

void init_stack (Stack *stack);
Action *create_action (int id);
void pop (Stack *stack);
void push (Stack *stack , Action *p_action);
void print_stack (Stack *stack);

#endif 