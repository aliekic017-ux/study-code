#include <stdio.h>
#include <stdlib.h>


typedef struct ListElement 
{
    int key;
    struct ListElement *next;

}ListElement;

typedef struct List
{
   ListElement *first;
    
}List;

void insert_Element(ListElement *newElement, List *list)
{
    ListElement *temp;
    temp = list->first;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newElement;
}

void delete_Element(ListElement *delElement, List *list)
{
    ListElement * temp;
    ListElement *del;
    temp = list->first;

    if (temp == delElement)
    {
        list->first = temp->next;
        free (temp);
        return;
    }
    while (temp != NULL)
    {
        if (temp->next == delElement)
        {
            del = temp->next;
            temp->next = del->next;
            free(del);
        }
        temp = temp->next;
    }
}
void print_list(List *list)
{
    ListElement *temp;
    temp = list->first;
    while (temp != NULL)
    {
        printf("\n%d\n", temp->key);
        temp = temp->next;
    }
    printf("---------------");
}
int main ()
{
    List list;
    ListElement *a;

    a = malloc (sizeof(ListElement));
    a->key=10;
    a->next = NULL;
    list.first = a;

    ListElement *b;
    b = malloc (sizeof(ListElement));
    b->key=15;
    b->next = NULL;

    print_list(&list);

    insert_Element(b, &list);
    print_list(&list);

    delete_Element(b, &list);
    print_list(&list);





    return 0;
}