#include "auftrag.h"
#include <stdio.h>
#include <stdlib.h>


int main (void)
{
    Queue benz;
    init_queue(&benz);

    load_orders_from_file(&benz, "auftraege.txt");
    printf("Vollständige Liste der gesamten offenen Aufträge laut auftraege.txt: \n");
    print_queue(&benz);

    dequeue(&benz);
    dequeue(&benz);
    printf("\nListe nach dem Entfernen von 2 Aufträgen: \n");
    print_queue(&benz);

    Order *new1 = create_new_Order(112, "Service B", 150);
    Order *new2 = create_new_Order(114, "Montage", 150);

    enqueue(&benz, new1);
    enqueue(&benz, new2);

    printf("\nListe nach dem Einfügen von 2 Aufträgen: \n");
    print_queue(&benz);

    save_queue_to_file(&benz, "backup.txt");

    free_queue(&benz);

    return 0;
}