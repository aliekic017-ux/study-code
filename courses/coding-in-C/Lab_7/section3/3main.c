#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct student
{
    int id;    
    double grade;
    struct student *next;  
}student;

typedef struct studentlist
{
    struct student *head;

}studentlist;


void init_list(studentlist *studentlist)
{
    studentlist->head = NULL;

    return;
}

void add_student(studentlist *studentlist , int id, double grade)
{
    student *newstudent = malloc(sizeof(*newstudent));

    if (newstudent == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return; 
    }
    newstudent->id = id;
    newstudent->grade = grade;
    newstudent->next = NULL;


    if (studentlist->head == NULL)
    {
        studentlist->head = newstudent;
        return;
    }
    
    student *iterator = studentlist->head;

    while (iterator->next != NULL)
    {
        iterator = iterator->next;
    }
    iterator->next = newstudent;
   
}

void print_students(studentlist *studentlist)
{
    student *temp = studentlist->head;

    while (temp != NULL)
    {
        printf("ID: %d    Grade: %.1f\n", temp->id , temp->grade);
        temp = temp->next;
     

    }
    
}

void delete_firstStudent (studentlist *studentlist)
{
    // Abfrage, ob Liste leer ist beim Löschen des ersten Students notwenidg
    if (studentlist->head == NULL)
    {
        printf("Die Liste der Studenten ist leer");
        return ; 
    }
    
    student *iterator = studentlist->head;
    studentlist->head = studentlist->head->next;

    free(iterator);

    return;
}

void delete_list (studentlist *studentlist)
{
    while (studentlist->head != NULL)
    {
        delete_firstStudent(studentlist);
       // free(temp);
    
    }
    return; 

}

int main()
{
    studentlist TFE25;

    init_list(&TFE25);
    add_student(&TFE25, 1242, 1.7);
    add_student(&TFE25, 3224, 1.9);
    add_student(&TFE25, 2121, 1.8);
    add_student(&TFE25, 2389, 2.1);

    print_students(&TFE25);
    delete_firstStudent(&TFE25);
    printf("\n"); // Leerzeile, um besser zu sehen, ob ein Student gelöscht wurde
    print_students(&TFE25);

    delete_list(&TFE25);
    printf("\n");
    print_students(&TFE25);
    printf("\n");

    return 0;
}