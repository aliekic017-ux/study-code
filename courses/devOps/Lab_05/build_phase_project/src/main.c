#include "board.h"
#include "move.h"
#include "util.h"

#include <stdio.h>

#ifndef STARTING_TIME
#define STARTING_TIME 180
#endif

int main(void)
{
    BoardState board = create_initial_board(STARTING_TIME);
    const char* first_move = "e2e4";

    print_build_variant();

    if (is_legal_move(first_move))
    {
        apply_move(&board, estimate_move_time(first_move));
    }

    printf("Starting time: %d seconds\n", STARTING_TIME);
    printf("White minutes left: %d\n", board.white_minutes);
    printf("Moves played: %d\n", board.move_count);

    return 0;
}
