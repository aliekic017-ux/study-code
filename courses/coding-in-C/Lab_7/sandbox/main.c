#include <stdlib.h>
#include <stdio.h>
#include <string.h>



typedef struct // Nutzdaten
{
    int z;
}DATA;

typedef struct listElement // Knoten
{
    struct listElement *next; // Zeiger auf das nächste Element
    DATA d; // die Daten in dem Fall: z
}listElement;

void showList (listElement *start) // start ist ein Zeiger auf das erste Element der Liste (HEAD)
{
    // Wenn start = Null, dann ist die Liste leer.
    if (start != NULL) // Ausgabe des ersten Element der Liste
    {
        listElement *p = start; // p ist ein Laufzeiger
        printf("%i", p->d.z); // start beim ersten Wert und azsgeben des Weres
        while (p->next != NULL) // wenn es noch ein weiteren Element gibt gehe auf next und gebe den Wert aus
        {
            p = p->next; // durch alle Knoten gehen
            printf("-> %i", p->d.z);  // Ausgabe der Nutzdaten in den jeweiligen Elementen
        }
        printf("\n");
    }
    else
    {
        printf("Die Liste ist leer!\n");
    }
}

int appendElement (listElement **start, const DATA *dInp) // hinten anhängen
{
    listElement *newElement = (listElement*)malloc(sizeof(listElement));  // TYpcast aif listElement da malloc ein void zeiger ausgibt
    if (newElement != NULL)
    {
        // Listenelement anlegen 
        newElement->d.z = dInp->z; // Wert übertragen
        newElement->next = NULL; // Pointer auf das nächste Element ist NULL

        if (*start == NULL)
        {
            *start = newElement;
        }
        else
        {
            listElement *n = *start;
            // Iterieren bis man am Ende der Liste angekommen ist 
            while (n->next != NULL) n = n->next;
            n->next = newElement; // Setze Pointer auf das neue Element
            
            
        }
        

        return 0;  // Element konnte erfolgreich angelegt werden
    }
    return -1;  // Speicheranforderung fehlgeschlagen
    
}




int main()
{
    listElement* start = NULL;  // Pointer auf den Start der Liste

    
    showList(start);

    DATA myD; // Anlegen einer VAriable vom Datentyp DATA
    for (int i = 0; i < 5; i++)
    {
        myD.z = i + 1;
        appendElement(&start, &myD);
    }
    

    showList(start);



    return 0;
}