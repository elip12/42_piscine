/*
* sastantua.c
* author: Eli Pandolfo
*
* program to create the sastantua pyramid; see examples
*/

#include <unistd.h>
#include <stdlib.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

/* draws a single line (level) in the pyramid: draws from the top down */
void	makeline(int n, int base, int row, int mid)
{
	int i;
	int rg;
	int rows;

	i = 0;
	rg = ((n + 1) / 2) * 2 - 1;
	rows = n * (3 * n + 14) / 4 - 1;
	while (i < base)
	{
		if (n > 4 && row == rows - rg / 2 && i == mid + rg / 2 - 1)
			ft_putchar('$');
		else if (row > rows - rg && (i >= mid - rg / 2 && i <= mid + rg / 2))
			ft_putchar('|');
		else if (i < mid - row)
			ft_putchar(' ');
		else if (i == mid - row)
			ft_putchar('/');
		else if (i == mid + row)
			ft_putchar('\\');
		else if (i < mid + row)
			ft_putchar('*');
		i++;
	}
	ft_putchar('\n');
}

/* creates the pyramid. The hardest part was deriving the formula for the number
* of stars in the bottom row, but once I got that (see attatched photo) it was
* easy to get the length of each previous line */
void	pyramid(int n, int row)
{
	static int	blockcount = 3;
	static int	actualrow = 0;
	int			base;
	int			mid;

	base = 3 * n * n / 2 + 7 * n - 3;
	mid = (base + 2) / 2;
	actualrow++;
	makeline(n, base + 2, row, mid);
	if ((row - 1) * 2 + 1 == base)
		return ;
	else if (actualrow % blockcount == 0)
	{
		actualrow = 0;
		blockcount++;
		pyramid(n, row + (((blockcount - 2) / 2) * 2 + 4) / 2);
	}
	else
		pyramid(n, row + 1);
}

void	sastantua(int size)
{
	if (size <= 0)
		return ;
	pyramid(size, 1);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "please give only 1 number (pyramid size) as an argument", 55);
		return 0;
	}
	sastantua(atoi(av[1]));
	return (0);
}
