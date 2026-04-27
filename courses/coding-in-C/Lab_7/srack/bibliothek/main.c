#include "bibliothek.h"
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    Stack bücherstapel;
    init_stack (&bücherstapel);

    book *new1 = create_newbook(101,"Siddhartha", "Herrmann Hesse");
    book *new2 = create_newbook(12, "Faust", "Goethe");
    book *new3 = create_newbook (102, "Der Vorleser", "Schlink Berrnhrd");

    push(&bücherstapel, new1);
    push(&bücherstapel, new2);
    push(&bücherstapel, new3);

    print_stack(&bücherstapel);

    pop(&bücherstapel);
    print_stack(&bücherstapel);


    book *g1 = find_book_by_isbn(&bücherstapel, 12);

}