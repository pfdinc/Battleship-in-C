#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <stdio.h>
#include <stdlib.h>


#define ROWS 10
#define COLS 10

typedef enum boolean
{
	FALSE, TRUE
} Boolean;


//typedef enum boolean Boolean;

typedef struct stats

void game_choice(int number);

void init_game_board (char game_board[ROWS][COLS],
	                  int num_rows, int num_cols);

void print_game_board (char game_board[ROWS][COLS],
	                  int num_rows, int num_cols);

void generate_direction (int *direction);
void generate_start_pt (int direction, int *row_pt, int *col_pt,
	                    int length);

Boolean is_invalid_location (char game_board[ROWS][COLS], int start_row,
	                         int start_col, int direction, int length);

void init_stats (Stats *stats_ptr);

#endif