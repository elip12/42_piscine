/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandolf <elipandolfo@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 14:37:28 by epandolf          #+#    #+#             */
/*   Updated: 2017/06/28 21:45:13 by epandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_print_comb.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_print_comb(void)
{
	static	int array[3] = {0, 1, 2};

	while (array[0] <= 7 && array[1] <= 8 && array[2] <= 9)
	{
		ft_putchar(array[0] + 48);
		ft_putchar(array[1] + 48);
		ft_putchar(array[2] + 48);
		if (!(array[0] == 7 && array[1] == 8 && array[2] == 9))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		array[2]++;
		if (array[2] == 10)
		{
			array[1]++;
			if (array[1] == 9)
			{
				array[0]++;
				array[1] = array[0] + 1;
			}
			array[2] = array[1] + 1;
		}
	}
	ft_putchar('\n');
}

int		main(void)
{
	ft_print_comb();
	return (0);
}
