#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct book
{
    int id;
    char *title;
    char *author;
    struct book *next;

}book;

typedef struct booklist
{
    struct book *head;
}booklist;

void init_list(booklist *booklist)
{
    booklist->head = NULL;
}

void add_book (booklist *booklist , int id, char *title, char *author)
{
    book *newBook = malloc(sizeof(*newBook));
    if (newBook == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return;
    }
    
    newBook->title = malloc(strlen(title)+1);
    newBook->author = malloc(strlen(author)+1);
    
    if(newBook->author == NULL || newBook->title == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        free(newBook);
        free(newBook->author);
        free(newBook->title);
        return;
    }
    newBook->id = id;
    newBook->next = NULL;
    strcpy(newBook->author, author);
    strcpy(newBook->title, title);

    if (booklist->head == NULL)
    {
        booklist->head = newBook;
        return;
    }
    book *iterator = booklist->head;

    while (iterator->next != NULL)
    {
        iterator = iterator->next;
    
    }
    iterator->next = newBook;

}

void print_books(booklist *booklist)
{
    book *temp = booklist->head;

    while (temp != NULL)
    {
        printf("ID: %d  Author: %s  Title: %s\n", temp->id, temp->author, temp->title);
        temp = temp->next;

    }
    
}

void delete_first_book (booklist *booklist)
{
    if (booklist->head == NULL)
    {
        printf("Die Bücherliste ist leer");
        return;
    }

    book *temp = booklist->head;
    booklist->head = booklist->head->next;
    free(temp->author); // Speicherfreigabe nicht vergessen
    free(temp->title); // Speicherfreigabe nicht vergessen 
    free(temp);
}

void delete_list(booklist *booklist)
{
    

    while(booklist->head != NULL)
    {
        delete_first_book(booklist);
        
    }
}


int main ()
{
    booklist schule;
    init_list(&schule);

    add_book(&schule, 1, "C Programming", "Dennis Ritchie");
    add_book(&schule, 2, "Algorithms", "Robert Sedgewick");
    add_book(&schule, 3, "Clean Code", "Robert MAritn");
    printf("\n");
    print_books(&schule);
    delete_first_book(&schule);

    print_books(&schule);
    printf("\n");

    delete_list(&schule);
    print_books(&schule);

    return 0;
}

