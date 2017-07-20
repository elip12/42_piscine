/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandolf <elipandolfo@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 14:37:28 by epandolf          #+#    #+#             */
/*   Updated: 2017/06/29 10:42:13 by epandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
