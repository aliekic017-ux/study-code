#ifndef BROWSER_H
#define BROWSER_H

typedef struct Page
{
    int id;
    int page_number;
    struct Page *next;

}Page;

typedef struct Stack
{
    struct Page *p_top;
}Stack;

void init_stack (Stack *p_stack);
Page *create_page (int id, int page_number);
void push (Stack *p_stack, Page *p_page);
void pop (Stack *p_stack);
void print_stack (Stack *p_stack);

#endif