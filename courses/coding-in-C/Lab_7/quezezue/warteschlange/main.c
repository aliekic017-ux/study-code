#include "warteschlange.h"
#include <stdio.h>
#include <stdlib.h>



int main (void)
{
    Queue laden;
    init_queue(&laden);

    customer *ali = NULL;
    customer *ezgi = NULL;
    customer *ece = NULL;


    ali = create_customer(102, "ali");

    enqueue(&laden,ali);

    ezgi = create_customer(103, "ezgi");
   
    enqueue(&laden,ezgi);

    print_queue(&laden);

    ece = create_customer(109, "ece");
    enqueue(&laden,ece);

    print_queue(&laden);

    dequeue(&laden);
    print_queue(&laden);

    delete_queue(&laden);
    print_queue(&laden);


    return 0;
}