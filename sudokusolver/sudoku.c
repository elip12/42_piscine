/*
* sudoku.c
* author: Eli Pandolfo
*
* Sudoku solver. I use a recursive backtracking algorithm.
* The algorithm places a number, then goes to the next position and tries to place a new number.
* If it gets to a position where no number can be placed, it backtracks to the previous square
* and increments the number there. The g_mut (global mutable) array stores the locations and values
* of the immutable (given in the board) numbers.
*/

#include <unistd.h>

int		check_pos(char num, int col, int row, char **board);
void	print_board(char **board);
int		valid_input(int ac, char **av);
int		valid_board(char **av);

char	g_mut[81];

/* skips an immutable number or numbers, since we are not allowed to change them */
int		skip(int pos)
{
	int		c;

	c = 0;
	while (pos >= 0)
	{
		if (g_mut[pos] == '0')
			break ;
		pos--;
		c++;
	}
	if (pos == -1)
		return (-1);
	return (c);
}

/* solves the board with recursive backtracking, a brute force method. */
int		solve(char num, int pos, char **board)
{
	int		col;
	int		row;

	if (pos >= 81)
		return (1);
	if (g_mut[pos] != '0')
		return (solve('1', pos + 1, board));
	row = pos / 9 + 1;
	col = pos % 9;
	while (num <= '9')
	{
		if (check_pos(num, col, row, board))
		{
			board[row][col] = num;
			if (solve('1', pos + 1, board)) // checks if this placement can solve the board
				return (1);
		}
		num++;
	}
	board[row][col] = '.';
	if (pos >= 0 && skip(pos - 1) != -1)
		return (solve(board[(pos - (1 + skip(pos - 1))) / 9 + 1][(pos - (1
		+ skip(pos - 1))) % 9] + 1, pos - (1 + skip(pos - 1)), board));
		return (0);
}

/* fills the g_mut array with the positions and values of the immutable numbers */
int 	fill_mut(char **argv)
{
	int		pos;

	pos = 0;
	while (pos < 81)
	{
		if (argv[pos / 9 + 1][pos % 9] != '.')
		{
			g_mut[pos] = argv[pos / 9 + 1][pos % 9];
			if (check_pos(g_mut[pos], pos % 9, pos / 9 + 1, argv) == 0)
			{
				write(1, "Error0\n", 7);
				return (0);
			}
		}
		else
			g_mut[pos] = '0';
		pos++;
	}
	return (1);
}

/* input must be in the form:
* ./a.out "1..4....." "....5...." "........." ".....3..." "........4" "........." "........." "........." "........."
*/
int		main(int argc, char **argv)
{
	if (!valid_input(argc, argv))
	{
		write(1, "Error1\n", 7);
		return (0);
	}
	if (!fill_mut(argv))
		return (0);
	if (solve('1', 0, argv) && valid_board(argv))
		print_board(argv);
	else
		write(1, "Error2\n", 7);
	return (0);
}
