#include "move.h"

#include <stdio.h>

int main(void)
{
    if (!is_legal_move("e2e4"))
    {
        printf("Expected e2e4 to be legal\n");
        return 1;
    }

    if (is_legal_move("invalid"))
    {
        printf("Expected invalid to be illegal\n");
        return 1;
    }

    if (estimate_move_time("e2e4") != 20)
    {
        printf("Unexpected move time\n");
        return 1;
    }

    printf("All move tests passed\n");
    return 0;
}
