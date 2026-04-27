#include "aufgaben.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    List ToDO;
    init_list(&ToDO);

    read_file(&ToDO, "input.txt");
    printf("Liste nach dem Einlesen:\n");
    print_list(&ToDO);

    printf("Erste Aufgabe entfernen:\n");
    remove_task(&ToDO);
    print_list(&ToDO);

    write_file(&ToDO, "output.txt");




}