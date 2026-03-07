#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int wert;
    struct Node *next;
}Node;


int main()
{
    Node *head = NULL;
    Node *current = NULL;

    for (int i = 0; i < 5; i++)
    {
       Node *newNode = malloc(sizeof(Node));
       newNode->wert = (i + 1 )*10;
       newNode->next = NULL;

       if (head == NULL)
       {
            head = newNode;
            current = head;        
       }
       else
       {
            current->next = newNode;
            current = newNode;  
       }
    }

    Node *temp2 = head;
    for (int i = 0; i < 1; i++)
    {
        temp2 = temp2->next;
    }
    Node *newNode = malloc(sizeof(Node));
    newNode->wert = 99; // einfügen der 99 an 3.stelle
    newNode->next = temp2->next;
    temp2->next = newNode;
    

    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->wert);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}