#include "student.h"
#include <stdlib.h>
#include <stdio.h>


int main (void)
{
    
    liste klasse8er;
    init_liste(&klasse8er);


    int anzahl = 0;
    int martikelnummer = 0;
    char name[50];
    float notenschnitt = 0.0f;


    printf("Wie viele Studenten sollen eingelesen werden?? \n");
    if (scanf("%d", &anzahl) != 1)
    {
        printf("Fehler bei der Eingabe bei der Studentanzahl");
        return -1;
    }

    for (int i = 0; i < anzahl; i++)
    {
        printf(" \nMartikelnummer: ");
        if (scanf("%d", &martikelnummer) != 1)
        {
            printf("Fehler bei der Eingabe der Martikelnummer");
            return -1;
        }

        printf("\nName: ");
        if (scanf ("%49s", name) != 1)
        {
            printf("Fehler bei der Eingabe des Namen");
            return -1;
        }

        printf(" Notenschnitt: ");
        if (scanf ("%f", &notenschnitt) != 1)
        {
            printf("Fehler bei der Eingabe vom Notenschnitt");
            return -1;
        }

        student *neuerStudent = create_student(martikelnummer, name, notenschnitt);
        append_student(&klasse8er, neuerStudent);
    }
    

    printf("Studentenliste: \n");
    print_list(&klasse8er);

    delete_first_student(&klasse8er);
    print_list(&klasse8er);

    delete_list(&klasse8er);
    print_list(&klasse8er);

    return 0;
}