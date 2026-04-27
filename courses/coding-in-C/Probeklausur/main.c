#include "undo.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    Stack programm;
    init_stack(&programm);

    int schleife = 10;
    int id = 1;

    for (int i = 0; i < schleife; i++)
    {
        if (i % 2 == 0)
        {
            Action *new = create_action (id);
            push(&programm, new);
            id++;

            Action *new2 = create_action (id);
            push(&programm, new2);
            id++;
        }
        else
        {
            pop(&programm);
        }
        print_stack(&programm);
    
    }

    return 0;
}