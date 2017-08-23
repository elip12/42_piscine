/*
* helper_fcns2.c
* author: Eli Pandolfo
*
* some more helper functions called by eval_expr.c
*/

#include "deque.h"

/* writes a char */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/* prints the smallest possible integer, which does not have a corresponding positive int */
int		smallest_int(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putchar('1');
		ft_putchar('4');
		ft_putchar('7');
		ft_putchar('4');
		ft_putchar('8');
		ft_putchar('3');
		ft_putchar('6');
		ft_putchar('4');
		ft_putchar('8');
		return (1);
	}
	return (0);
}

/* prints a number to the console */
void	ft_putnbr(int nb)
{
	int tens;
	int temp;

	if (smallest_int(nb))
		return ;
	tens = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	temp = nb;
	while (temp >= 10)
	{
		temp /= 10;
		tens *= 10;
	}
	while (tens > 0)
	{
		ft_putchar(nb / tens + 48);
		nb = nb % tens;
		tens /= 10;
	}
}
