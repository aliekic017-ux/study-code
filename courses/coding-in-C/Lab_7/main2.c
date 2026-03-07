#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>



typedef struct Node
{
    double Wert;
    struct Node *next;
}Node;

Node *addElement (double Wert)
{
    // Speicher reservieren
    Node *newElement =  malloc(sizeof*newElement);
    if (newElement == NULL)
    {
        printf("Speicherallokation fehlgeschlagen!!\n");
        return NULL;
    }
        newElement->Wert = Wert;
        newElement->next = NULL;
        return newElement; // Adresse im Speicher des neuen Knotens
    

}
int main()
{
    srand(time(NULL));

    Node *head = NULL; // das erste Element der Liste speichern zu können
    Node *current = NULL;  // für das letzte Element
    

    for (int i = 0; i < 50; i++)
    {
        Node *newElement = addElement(rand());

        if (newElement == 0) // kein Speicher konnte reserviert werden 
        {
            printf("Stop Programm");
            return 1;
        }

        if (head == NULL) // erster Durchlauf wird das erste Element als head gesetzt 
        {
            head = newElement;
            current = head;
        }
        else // nach dem ersten Durchlauf durchläuft es nur noch den Teil. 
        {
            current->next = newElement; // letzte Elemenet zeigt nun auf das neu hinzugefügte Element
            current = newElement; // nun ist das neue Element jetzt das letzte Element

            // current wird beim Einfügen eines neuen Elements immer verschobben und zeigt immer auf das letzte Element
        }
    }

int Array[51];

for (int i = 0; i < 50; i++)
{
    Array[i] = rand();
}

int neuerWert = rand();

for (int i = 50; i > 3; i--)
{
    Array[i] = Array[i-1];

}
Array[3] = neuerWert;

Node *newElement = addElement(neuerWert);
Node *temp = head;

for (int i = 0; i < 2; i++)
{
    temp = temp->next;
}

newElement->next = temp->next;
temp->next = newElement;

printf("Array: \n");
for (int i = 0; i < 51; i++)
{
    printf("%d \n", Array[i]);

}
printf("Linked List: \n");
Node *iterator = head;
while (iterator != NULL)
{
    printf("%.0f\n", iterator->Wert);
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