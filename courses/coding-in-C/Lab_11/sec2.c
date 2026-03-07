#include <stdlib.h>
#include <stdio.h>
#include <time.h>


typedef struct Node
{
    double Wert;
    struct Node *next;
}Node;

Node *addElement(double wert)
{
    Node *newNode = malloc(sizeof(*newNode));
    if (newNode == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return NULL;

    }
    newNode->Wert = wert;
    newNode->next = NULL;
    return newNode;
}

int main ()
{
    Node *head = NULL;
    Node *help = NULL;

    srand(time(NULL));

    for (int i = 0; i < 50; i++)
    {
        Node *newNode = addElement(rand());
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

    int array[51];
    for (int i = 0; i < 5; i++)
    {
        array[i] = rand();
    }

    int neuerWert = rand();

    for (int i = 50; i < 3; i++)
    {
        array[i] = array[i-1];
    }
    array[3] = neuerWert;

    Node *temp = head;
    for (int i = 0; i < 2; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;

    //printf fehlt



    return 0;
}