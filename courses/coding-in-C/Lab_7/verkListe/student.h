#ifndef STUDENT_H
#define STUDENT_H

typedef struct student 
{
    int martikelnummer;
    char name [50];
    float notenschnitt;
    struct student *next;
}student;

typedef struct liste
{
    struct student *head;
}liste;

void init_liste (liste *p_liste);
student *create_student (int martikelnummer, char name[], float notenschnitt);
void append_student (liste *p_liste, student *p_student);
void print_list (liste *p_liste);
void delete_first_student (liste *p_liste);
void delete_list (liste *p_liste);

#endif