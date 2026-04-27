#ifndef BIBLIOTHEK_H
#define BIBLIOTHEK_H



typedef struct book
{
    int isbn;
    char *title;
    char *author;
    struct book *next;
}book;


typedef struct Stack
{
    struct book *p_top;
}Stack;


void init_stack (Stack *p_stack);
book *create_newbook (int isbn, char *title , char *author);
void push (Stack *p_stack, book *p_book);
void pop (Stack *p_stack);
void print_stack (Stack *p_stack);
void peek_top (Stack *p_stack);
int count_books (Stack *p_stack);
book *find_book_by_isbn (Stack *p_stack , int isbn);
book *find_book_by_title (Stack *p_stack , char *title);
void delete_Stack (Stack *p_stack);



#endif