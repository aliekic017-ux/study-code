#ifndef SYMBOL_H
#define SYMBOL_H

typedef struct Symbol
{
    int id;
    char symbol;
    struct Symbol *next;

}Symbol;

typedef struct Stack
{
    struct Symbol *p_top;

}Stack;

void init_stack(Stack *p_stack);
Symbol *create_symbol (int id, char symbol);
void push (Stack *p_stack, Symbol *p_symbol);
void pop (Stack *p_stack);
void print_stack (Stack *p_stack);


#endif