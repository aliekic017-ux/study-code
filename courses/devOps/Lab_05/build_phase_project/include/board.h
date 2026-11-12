#ifndef BOARD_H
#define BOARD_H

typedef struct
{
    int white_minutes;
    int black_minutes;
    int move_count;
} BoardState;

BoardState create_initial_board(int starting_seconds);
void apply_move(BoardState* board, int seconds_used);

#endif
