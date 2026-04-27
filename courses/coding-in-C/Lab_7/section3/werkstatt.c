/*
*
* File: werkstatt.c
* Description: einfach verkettete Liste, was die Aufträge einer Werkstatt verwaltet
*
*/

#include <stdlib.h>
#include <stdio.h>


typedef struct order_node
{
    int order_number;
    int duration_minutes;
    struct order_node *p_next;
}order_node;


typedef struct workshop_list
{
    struct order_node *p_head;

}workshop_list;

/**
 * @brief Initialisierung der Liste, dass Sie leer ist 
 * 
 * @param[in] liste Pointer auf die Liste der Werkstattaufträge 
 * 
 */

void init_list (workshop_list *liste)
{
    liste->p_head = NULL;
}


/**
 * @brief Einfügen eines neuen Auftrags
 * 
 * @param[in] order_number Nummer des neuen Auftrags
 * 
 * @param[in] duration_numbers Wartezeit des neuen Auftrags in min 
 */

void append_order(workshop_list *liste, int order_number, int duration_numbers)
{
    order_node *newOrder = malloc(sizeof(*newOrder));
    if (newOrder == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return ;
    }
    newOrder->order_number = order_number;
    newOrder->duration_minutes = duration_numbers;
    newOrder->p_next = NULL;

   // order_node *iterator = NULL;

    if (liste->p_head == NULL)
    {
        liste->p_head = newOrder;
        return;
    }
    
    order_node *iterator = liste->p_head;

    while (iterator->p_next != NULL)
    {
        iterator = iterator->p_next;
    }
    iterator->p_next = newOrder;

}


/**
 * @brief Ausgeben von allen Aufträgen
 * 
 * @param[in] liste Pointer auf die Liste der Werkstattaufträge 
 * 
 */

void print_list (workshop_list *liste)
{
    if (liste->p_head == NULL)
    {
        printf("Die Liste ist leer");

    }
    
    order_node *temp = liste->p_head;

    while (temp != NULL)
    {
        printf("Auftrag: %d  geschätzte Wartezeit: (%d min)\n", temp->order_number, temp->duration_minutes);
        temp = temp->p_next;
    }

    return; 

}
/**
 * @brief Anzahl der noch offenen Aufträge
 * 
 * @param[in] liste Pointer auf die Liste der Werkstattaufträge 
 * 
 * @param[out] get_length Anzahl der noch offenen Aufträge
 */

int get_length (workshop_list *liste)
{
    order_node *iterator = liste->p_head;
    int Einheiten = 0;

    while (iterator != NULL)
    {
        Einheiten = Einheiten + 1;
        iterator = iterator->p_next;

    }
    return Einheiten;
}

/**
 * @brief Einen bestimmten Auftrag anhand der Auftragsnummer suchen
 * 
 * @param[in] liste Pointer auf die Liste der Werkstattaufträge 
 * @param[in] order_numbers Nummer der Auftrags nach dem gesucht werden sol
 * 
 */

order_node *find_order (workshop_list *liste, int order_number)
{
    order_node *current = NULL;

    if (liste->p_head == NULL)
    {
        printf("Die Liste ist leer");
    }

    current = liste->p_head;

    while (current != NULL)
    {
        if (current->order_number == order_number)
        {
            return current;
        }
        current = current->p_next;

    }
     return NULL;    
    
}


/**
 * @brief Löschen eimes Auftrags anhand der Auftragsnummer
 * 
 * @param[in] order_numbers Auftragsnummer, die gelöscjt werden soll 
 * 
 */

void delete_order ( workshop_list *liste, int order_numbers)
{
    order_node *current = NULL;
    order_node *davor = NULL;

    if (liste->p_head == NULL)
    {
        printf("Die Liste ist leer");
        return;
    }

    current = liste->p_head;
    while (current != NULL)
    {
        if (current->order_number == order_numbers)
        {
            if (davor == NULL)
            {
                liste->p_head = current->p_next;
            }
            else
            {
                davor->p_next = current->p_next;
            }
            free(current);
            return;
        }
        
        davor = current;
        current = current->p_next;

    }
    
    printf("Auftrag nicht gefunden. \n");
    
}

/**
 * @brief Einen Auftrag löschen und den Speicher freigeben 
 * 
 * @param[in] liste Pointer auf die Liste der Werkstattaufträge 
 * 
 */

void delete_auftrag (workshop_list *liste)
{
    order_node *temp = liste->p_head;

    if (temp == NULL)
    {
        printf("Die Liste ist leer");
        return;
    }
    liste->p_head = liste->p_head->p_next;

    free(temp);
    


}

/**
 * @brief Gesamte Liste aller Werkstattaufträge löschen
 * 
 * @param[in] liste Pointer auf die Liste der Werkstattaufträge 
 * 
 */

void delete_liste (workshop_list *liste)
{

    while (liste->p_head != NULL)
    {
        delete_auftrag(liste);
    }
    return;
}

int main ()
{
    workshop_list atu;

    init_list(&atu);
    append_order(&atu, 1001, 30);
    append_order(&atu, 1002, 45);
    append_order(&atu, 1003, 20);

    print_list(&atu);
    
    printf("Anzahl der Aufträge: %d \n", get_length(&atu));

    find_order(&atu, 1002);
    delete_order(&atu, 1002);

    print_list(&atu);

    delete_liste(&atu);

    print_list(&atu);

    return 0;
}
