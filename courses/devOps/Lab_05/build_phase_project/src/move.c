#include "move.h"

#include <string.h>

int is_legal_move(const char* move)
{
    if (move == 0)
    {
        return 0;
    }

    return strlen(move) == 4;
}

int estimate_move_time(const char* move)
{
    if (!is_legal_move(move))
    {
        return 0;
    }

    return 20;
}
