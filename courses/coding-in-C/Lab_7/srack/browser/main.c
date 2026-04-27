
#include <stdio.h>
#include <stdlib.h>
#include "browser.h"


int main (void)

{

    int step = 0;
    int next_id = 1;
    int next_page_number = 100;

    Stack ali;
    Page *p_newPage = NULL;
    init_stack(&ali);


    for (step = 0; step <= 10; step++)
    {
    
        if (step % 2 == 0)
        {
            p_newPage = create_page(next_id, next_page_number);
            if (p_newPage != NULL)
            {
                push(&ali, p_newPage);
            }
            next_id++;
            next_page_number++;

            p_newPage = create_page(next_id, next_page_number);
            if (p_newPage != NULL)
            {
                push(&ali, p_newPage);
            }
            next_id++;
            next_page_number++;

        }
        if (step %2 == 1)
        {
            pop(&ali);
        }
        
        print_stack(&ali);
    }
    
    return 0;
}