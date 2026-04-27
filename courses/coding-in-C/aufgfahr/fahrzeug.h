#ifndef FAHRZEUG_H
#define FAHRZEUG_H

typedef struct Order
{
    int id;
    char *fahrzeug;
    int dauer_minuten;
    struct Order *next;
}Order;

typedef struct List
{
    struct Order *head;
}List;


void init_list(List *p_liste);
Order *create_order (int id , char *fahrzeug, int dauer_minuten);
void append_order(List *p_liste , Order *p_order);
void print_list (List *p_liste);
Order *find_order_by_id (List *p_liste, int id);
void delete_first_order (List *p_liste);
int count_orders (List *p_liste);
void free_liste (List *p_liste);

#endif 