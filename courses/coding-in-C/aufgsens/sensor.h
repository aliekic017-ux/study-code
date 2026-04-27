#ifndef SENSOR_H
#define SENSOR_H

typedef struct Messung 
{
    double zeit;
    double wert;
    struct Messung *next;
}Messung;


typedef struct Liste
{
    struct Messung *head;
}Liste;


void init_list (Liste *list);
Messung *create_messung (double zeit, double wert);
void append_messung (Liste *list, Messung *pMessung);
void print_liste (Liste *list);
void delete_first_messung (Liste *list);
void delete_liste (Liste *list);
int count_messungen (Liste *list);
Messung *find_max_wert (Liste *list);


#endif