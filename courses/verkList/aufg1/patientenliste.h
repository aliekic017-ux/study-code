#ifndef PATIENTENLISTE_H
#define PATIENTENLISTE_H

typedef struct Patient
{
    int id;
    char name[50];
    struct Patient *next;
}Patient;


typedef struct Liste
{
    struct Patient *head;
}Liste;

void init_list (Liste *p_liste);
Patient *create_patient (int id, char name[]);
void append_patient(Liste *p_liste, Patient *p_patient);
void print_liste (Liste *p_liste);
void delete_first_person (Liste *p_liste);
void delete_list (Liste *p_liste);


#endif 