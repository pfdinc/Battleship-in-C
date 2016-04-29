#include "battleship.h"



void game_choice(int number)
{

printf("               **********Welcome To Battel Ship*************\n\n\n");

printf("Please choose from the following\n\n\n");
printf("1) Play Battleship\n");
printf("2) Print Game Rule\n");
printf("3) Exit The Game\n");

scanf("%d",&number);
if(number == 1)
{
	system("clr");
	printf("Good Luck");
	// return the game 

}
else if(number==2)
{
	// return the welcome rules to the game 
}
else if(number==3)
{
	
}

else
	
{

}
int select_who_starts_first(void)
{

}
void randomly_place_ships_on_board(char game_board[ROWS][COLS],
	                  int num_rows, int num_cols)
{


}
void init_game_board (char game_board[ROWS][COLS],
	                  int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	for (row_index = 0; row_index < num_rows; row_index++)
	{
		for (col_index = 0; col_index < num_cols; col_index++)
		{
			game_board[row_index][col_index] = '~';
		}
	}
}

void print_game_board (char game_board[ROWS][COLS],
	                  int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	printf ("  0 1 2 3 4 5 6 7 8 9\n");

	for (row_index = 0; row_index < num_rows; row_index++)
	{
		printf ("%d ", row_index);

		for (col_index = 0; col_index < num_cols; col_index++)
		{
			printf ("%c ", game_board[row_index][col_index]);
		}

		putchar ('\n');
	}
}

void generate_direction (int *direction)
{
	*direction = rand() % 2; // 0 = horizontal, 1 - vertical
}

void generate_start_pt (int direction, int *row_pt, int *col_pt,
	                    int length)
{
	if (direction == 0) // horizontal, will place ships from start point to right on board
	{
		*row_pt = rand () % ROWS;
		*col_pt = rand () % (COLS - length + 1);
	}
	else // vertical - will place ships from start point down on board
	{
		*row_pt = rand () % (ROWS - length + 1);
		*col_pt = rand () % COLS;
	}

}

Boolean is_invalid_location (char game_board[ROWS][COLS], int start_row,
	                         int start_col, int direction, int length)
{
	int index = 0;
	Boolean flag = FALSE;

	for (index = 0; index < length; index++)
	{
		if (direction == 0) // horizontal
		{
			if (game_board[start_row][start_col + index] != '~')
			{
				flag = TRUE; // invalid location to place ship
			}
		}
		else // vertical
		{
			if (game_board[start_row + index][start_col] != '~')
			{
				flag = TRUE; // invalid location to place ship
			}
		}
	}

	return flag;
}

void init_stats (Stats *stats_ptr)
{
	(*stats_ptr).num_hits = 0;
	stats_ptr->num_misses = 0;
	stats_ptr->total_shots = 0;
	stats_ptr->hits_miss_ratio = 0.0;
}