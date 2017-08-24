/*
* bsq.c
* author: Eli Pandolfo (for all code except ft_valid), and Paulina Sprawska (for ft_valid)
*
* bsq: brockian simple qricket, from the Hitchhikers Guide to the Galaxy
* - the challenge was to write a program that given a "field" strewn with "boulders",
* which contains some info on what square are open, which are boulders, and which will be filled:

10.ox
........o.
ooo....o..
..o....o..
o...oo..o.
..o...o.o.
oo.ooo....
.........o
..o...oo..
.o..ooo..o
........o.

* find the largest square that can be make inside that field that touches no boulders
* and is as close as possible to the top left, and fill it with a "full" character:

...xxx..o.
oooxxx.o..
..oxxx.o..
o...oo..o.
..o...o.o.
oo.ooo....
.........o
..o...oo..
.o..ooo..o
........o.

* This was the final project of the School 42, USA, Piscine. Originally, I did it
* with my partner Paulina, but chose to rewrite the solving algorithm to make it more
* efficient. Paulina and I worked together on all parts of the program except the algorithm
* itself, which I rewrote after the piscine ended. I wrote most of the IO, and she wrote most
* of the helper code (ft_atoi.c, ft_split_whitespaces.c, malloc.c).
*
* My approach was to brute force the problem: for every open cell in the grid representing
* the field starting at the top left, I found the largest square that could be made using
* that cell as the top left corner, and then picked the largest of these squares. The
* algorithm is basically instant for a 1000x1000 board, but takes around 4 seconds for a
* moderately obstacle-filled 10000x10000 grid. The max run time (big O) is n squared, where n is
* the number of cells in the board (a 1000x1000 would have 1 million cells). The more heavily
* obstacled, the faster the algorithm solves the board.
*/

#include "bsq.h"

int			rows;
int			cols;
char		obstacle;
char		empty;
char		full;

/*==========================output=======================================*/
/* prints the map */
void	print(char **map)
{
	int x = 0;

	while(x < rows)
	{
		int y = 0;
		while(y < cols)
		{
			printf("%c ", map[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
}

/* once largest square is found, prints full characters inside the square
* biggest[0] = x, biggest[1] = y, biggest[2] = size */
void fill_square(char **map, int biggest[3])
{
	int i = 0;

	while(i < biggest[2])
	{
		int j = 0;
		while(j < biggest[2])
		{
			map[biggest[0] + i][biggest[1] + j] = full;
			j++;
		}
		i++;
	}
}

/*===============================solving algorithm========================================*/

/* returns min of 2 numbers */
int		min(int n, int m)
{
	if (n < m)
		return n;
	return m;
}

/* given a starting corner (x1, y1), and an ending corner (x2, y2), checks whether
* the ending corner and all squares between them are obstacle free */
int square_valid(int x1, int x2, int y2, char **map)
{
	int c = 0;
	while(c <= (x2 - x1))
	{
		if(map[x2 - c][y2] == obstacle || map[x2][y2 - c] == obstacle)
			return (0);
		c++;
	}
	return (1);
}

/* given a top left corner, returns the size of the square made from that corner */
int biggest_square_given_corner(int x, int y, char **map)
{
	int size = 1;
	int max_size = min(rows, cols);
	while(size + x < max_size && size + y < max_size)
	{
		if(square_valid(x, x + size, y + size, map) == 0)
		 	return size;
		size++;
	}
	return size;
}

/* treats every open square as a top left corner, and finds biggest square on board */
void solve(char **map)
{
	int tempsize;
	int biggest[3] = {0};
	int x = 0;

	while(x < rows)
	{
		int y = 0;
		while(y < cols)
		{
			if(map[x][y] == empty && (tempsize = biggest_square_given_corner(x, y, map)) > biggest[2])
			{
				biggest[0] = x;
				biggest[1] = y;
				biggest[2] = tempsize;
			}
			y++;
		}
		x++;
	}
	printf("x: %d, y: %d, size: %d\n", biggest[0], biggest[1], biggest[2]);
	fill_square(map, biggest);
}

/*===========================================input/running==================================*/

/* checks if board is valid */
int     ft_valid(char *str)
{
    int     i;
    int     len;
    int     if_dot;

    if_dot = 0;
    i = 0;
    len = 0;
    if (rows < 1)
        return (1);
    while(str[len] != '\n')
        len++;
    cols = len;
    while (str[i])
    {
        if (str[i] == empty)
            if_dot = 1;
        while ((str[i] != '\n') && ((str[i] == empty) || (str[i] == obstacle)))
            i++;
        if (i != len)
            return (1);
        else {
        	len += cols + 1;
        	i++;
        }
    }
    if (if_dot != 1)
        return (1);
    return (0);
}

/* - extracts board size (rows and cols), empty char, full char, and obstacle char
* - copies board to a 2D array of chars instead of a single string
* - solves board
* - prints solution/solved board
*/
void	io_run(char *file, char *buf, int *ret, int fd)
{
	int		start;
	char	*begin;
	char	*atoi;

	create_malloc(file, &buf, ret, fd);
	start = 0;
	while (buf[start] && buf[start] != '\n')
		start++;

	begin = &buf[start] + 1;
	full = buf[--start];
	obstacle = buf[--start];
	atoi = (char *)malloc(--start);
	empty = buf[start];
	atoi[start] = '\0';

	while (--start >= 0)
		atoi[start] = buf[start];
	rows = ft_atoi(atoi);

	if ((ft_valid(begin) == 0))
	{
		printf("board valid\n");
		char **map = ft_split_whitespaces(begin);
		solve(map);
		//print(map);
	}
	else
		write(2, "map error\n", 10);
	close(fd);
}

/* reads files in from command line args or stdin */
int main(int ac, char **av)
{
	char	*buf;
	int		c;
	int		fd;
	int 	ret;
	char	**stdin;

	buf = 0;
	if (ac == 1)
	{
		buf = malloc(4096);
		ret = read(0, buf, 4096);
		buf[ret] = '\0';
		stdin = ft_split_whitespaces(buf);
		c = 0;
		free(buf);

		while (stdin[c])
		{
			if ((fd = open(stdin[c++], O_RDWR)) != -1)
				io_run(stdin[c-1], buf, &ret, fd);
			c++;
		}
	}
	else
	{
		c = 1;
		while (c < ac)
		{
			if ((fd = open(av[c], O_RDWR)) != -1)
				io_run(av[c], buf, &ret, fd);
			c++;
		}
	}
	return (0);
}

/*==========================================================================*/
