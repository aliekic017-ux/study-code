#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 


typedef struct Node
{
    double value;
    struct Node *next;
}Node;


Node *add_element(double value)
{
    Node *newElement = malloc(sizeof *newElement);
    if (newElement == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return 0;
    }
    newElement->value = value;
    newElement->next  = NULL;

    return newElement;

}




int main()
{
    Node *head = NULL;
    Node *iterator = NULL;
    srand(time(NULL));
    

    for (int i = 0; i < 51; i++)
    {
        Node *newElement = add_element(rand());
        
        if (newElement == NULL)
        {
            printf("Stop program - Speicherallokation fehlgeschlagen");
            return 1;
        }

        if (head == NULL)
        {
            head = newElement;
            iterator = head;

        }
        else
        {
           iterator->next = newElement;
           iterator = newElement;
        }

        
    }
    
    int array[51];
    for (int i = 0; i < 50; i++)
    {
        array[i] = rand();
    }
    
    int newNumber = rand();

    for (int i = 50; i > 3; i--)
    { 
        array[i] = array[i-1];
    }
    array[3] = newNumber;


    Node *newNode = add_element(newNumber);
    Node *temp = head;

    for (int i = 0; i < 2; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Array: \n");
    for (int i = 0; i < 51; i++)
    {
        printf("%d   ", array[i]);
    }
    
    printf("\n");


    printf(" Verkettete Liste: \n");
    Node *iter = head;
    while (iter != NULL)
    {
        printf("%.0f   ", iter->value);
        iter = iter->next;
    }

    printf("\n");


    //Freigeben des ganzen Speichers der verketteten Liste

    Node *tmp;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    
    return 0;
}