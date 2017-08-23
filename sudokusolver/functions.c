/*
* functions.c
* author: Eli Pandolfo
*
* helper functions for the sudoku solver
*/

#include <unistd.h>

/* checks if the input to the board is valid; 9 rows with 9 cols in each row, and
* at least one open square */
int		valid_input(int ac, char **av)
{
	int		c;
	int		d;
	int		dotc;

	if (ac != 10)
		return (0);
	dotc = 0;
	c = 1;
	while (c < 10)
	{
		d = 0;
		while (av[c][d])
		{
			d++;
			if (av[c][d] == '.')
				dotc++;
		}
		if (d != 9)
			return (0);
		c++;
	}
	if (dotc == 0)
		return (0);
	return (1);
}

/* boolean to return true or false if you can place a number at a specific location */
int		check_pos(char num, int col, int row, char **board)
{
	int		c;
	int		y;

	c = 0;
	while (c < 9)
	{
		if ((board[row][c] == num  && c != col)|| (board[c + 1][col] == num && c + 1 != row))
			return (0);
		c++;
	}
	c = 0;
	while (c < 3)
	{
		y = 0;
		while (y < 3)
		{
			if (board[((row - 1) / 3) * 3 + 1 + c][(col / 3) * 3 + y] == num && !(((row - 1) / 3) * 3 + 1 + c == row && (col / 3) * 3 + y == col))
				return (0);
			y++;
		}
		c++;
	}
	return (1);
}

/* checks if a box is valid -- no repeated numbers */
int		valid_box(char **av)
{
	int		row;
	int		col;
	int		boxsum;

	row = 0;
	while (row < 3)
	{
		col = 0;
		boxsum = 0;
		while (col < 9)
		{
			boxsum += av[row * 3 + 1][(col / 3) * 3 + col % 3] - 48;
			boxsum += av[row * 3 + 2][(col / 3) * 3 + col % 3] - 48;
			boxsum += av[row * 3 + 3][(col / 3) * 3 + col % 3] - 48;
			col++;
			if (col % 3 == 0)
			{
				if (boxsum != 45)
					return (0);
				boxsum = 0;
			}
		}
		row++;
	}
	return (1);
}

/* checks if a solved board in valid; if the sum of all numbers in each row, col, and box == 45 */
int		valid_board(char **av)
{
	int		row;
	int		col;
	int		rowsum;
	int		colsum;

	row = 1;
	while (row < 10)
	{
		col = 0;
		rowsum = 0;
		colsum = 0;
		while (col < 9)
		{
			colsum += av[col + 1][row - 1] - 48;
			rowsum += av[row][col++] - 48;
		}
		if (rowsum != 45 || colsum != 45)
			return (0);
		row++;
	}
	if (valid_box(av))
		return (1);
	return (0);
}

/* prints the solved sudoku board */
void	print_board(char **board)
{
	int		x;
	int		y;

	x = 1;
	y = 0;
	while (x < 10)
	{
		while (y < 9)
		{
			write(1, &board[x][y], 1);
			write(1, " ", 1);
			y++;
		}
		y = 0;
		write(1, "\n", 1);
		x++;
	}
}
