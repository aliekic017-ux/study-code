#ifndef MELDUNG_H
#define MELDUNG_H

typedef struct Message 
{
    int id;
    char *text;
    int priorität;
    struct Message *p_next;
}Message;


typedef struct Stack
{
    struct Message *p_top;
}Stack;

void init_stack (Stack *p_stack);
Message *create_message (int id, char *text, int priorität);
void push (Stack *p_stack, Message *p_message);
void pop (Stack *p_stack);
void print_stack (Stack *p_stack);
int count_stack (Stack *p_stack);
void free_stack (Stack *p_stack);


#endif 