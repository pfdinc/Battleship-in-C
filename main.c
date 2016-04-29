#include "battleship.h"

int main (void)
{
	char game_board[ROWS][COLS] = {{'~', '~'}, {'~'}},
		 p2_game_board[ROWS][COLS];

	int direction = 0, row_start = 0, col_start = 0,
		lengths_ships[5] = {5, 4, 3, 3, 2}, index = 0;

	Boolean flag = FALSE; // enum boolean flag = FALSE;

	Stats p1_stats = {0, 0, 0, 0.0}, p2_stats = {0, 0, 0, 0.0};

	srand ((unsigned int) time(NULL));

	init_stats (&p1_stats);
	//p2_stats = p1_stats;

	init_game_board (game_board, ROWS, COLS); 
	init_game_board (p2_game_board, ROWS, COLS); 
	print_game_board (game_board, ROWS, COLS);

	for (index = 0; index < 5; index++)
	{
		do
		{
			generate_direction (&direction); // 0 - horizontal, 1 - vertical
			generate_start_pt (direction, &row_start, &col_start, lengths_ships[index]);
			// check to determine valid location to place ship
			flag = is_invalid_location (game_board, row_start, col_start, direction, lengths_ships[index]);
		} while (flag);

		// place ship here
	}

	printf ("direction: %d, row: %d, col: %d\n", direction, row_start, col_start);
	
	return 0;
}