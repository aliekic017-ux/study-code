#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct Node 
{
    int zahl;
    struct Node *next;
}Node;

Node *createNode (int value)
{
    Node *newNode = malloc(sizeof *newNode);
    if (newNode == NULL)
    {
        printf("Speicherallokation fehlgeschlagen!!\n");
        return NULL;
    }
    newNode->zahl = value;
    newNode->next = NULL;

    return newNode;
}

int main()
{


    Node *head = NULL;
    Node *current = NULL;

    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        Node *newNode = createNode(rand());

        if (newNode == NULL)
        {
            printf("Fehlgeschlagen");
            return 1;

        }
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
    int array[11];

    for (int i = 0; i < 10; i++)
    {
        array[i] = rand();
    }

    int neuerWert = rand();

    for (int i = 10; i > 4; i--)
    {
        array[i] = array[i-1];
    }
    array[4] = neuerWert;

    Node *newNode = createNode(neuerWert);
    Node *temp = head;

    for (int i = 0; i < 3; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode; 

    printf("Array: \n");
    for (int i = 0; i < 11; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\nLinked Lists: \n");
    Node *iterator = head;
    while (iterator != NULL)
    {
        printf("%d ", iterator->zahl);
        iterator = iterator->next;
    }

    Node *tmp;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    
    return 0;
}