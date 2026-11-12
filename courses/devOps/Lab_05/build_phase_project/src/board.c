#include "board.h"
#include "util.h"

BoardState create_initial_board(int starting_seconds)
{
    BoardState board = {
        seconds_to_minutes(starting_seconds),
        seconds_to_minutes(starting_seconds),
        0
    };

    return board;
}

void apply_move(BoardState* board, int seconds_used)
{
    if (board == 0)
    {
        return;
    }

    board->white_minutes -= seconds_to_minutes(seconds_used);
    board->move_count += 1;
}
