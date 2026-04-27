#include <stdio.h>
#include <stdlib.h>
#include "symbol.h"


int main ()
{
    int id = 0;
    char symbol = 'A';

    int step = 0;
    Symbol *p_new_symbol = NULL;

    Stack Websote;
    init_stack(&Websote);
    
    for (step = 0; step <= 10; step++)
    {
        if (step % 2 == 0)
        {
            p_new_symbol = create_symbol(id, symbol);
            if (p_new_symbol != NULL)
            {
                push(&Websote, p_new_symbol);
            }
            id++;
            symbol++;

            p_new_symbol = create_symbol(id, symbol);
            if ((p_new_symbol != NULL))
            {
                push(&Websote, p_new_symbol);
            }
            id++;
            symbol++;
        }
        if (step % 2 == 1)
        {
            pop(&Websote);
        }
        print_stack(&Websote);
        

    }

    return 0;
}