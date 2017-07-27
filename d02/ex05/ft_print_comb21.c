/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandolf <elipandolfo@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 14:37:28 by epandolf          #+#    #+#             */
/*   Updated: 2017/06/29 09:00:18 by epandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_print_comb2.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_print_comb2(void)
{
	static int array[2] = {0, 1};

	while (array[0] + array[1] <= 197)
	{
		ft_putchar((array[0] / 10) + 48);
		ft_putchar((array[0] % 10) + 48);
		ft_putchar(' ');
		ft_putchar((array[1] / 10) + 48);
		ft_putchar((array[1] % 10) + 48);
		if (!(array[0] == 98 && array[1] == 99))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		array[1]++;
		if (array[1] == 100)
		{
			array[0]++;
			array[1] = array[0] + 1;
		}
	}
	ft_putchar('\n');
}

int		main(void)
{
	ft_print_comb2();
	return (0);
}
