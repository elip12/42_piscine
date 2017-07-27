/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 10:20:22 by epandolf          #+#    #+#             */
/*   Updated: 2017/07/01 10:20:32 by epandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_putchar(char c);

void rush(int x, int y)
{
	int l;
	int w;

	l = 0;
	while (l < y)
	{
		w = 0;
		while (w < x)
		{
			if ((l == 0 || l == y - 1) && (w == 0 || w == x - 1))
				ft_putchar('o');
			else if ((l == 0 || l == y - 1) && (w > 0 && w < x))
				ft_putchar('-');
			else if ((w == 0 || w == x - 1) && (l > 0 && l < y))
				ft_putchar('|');
			else
				ft_putchar(' ');
			w++;
		}
		ft_putchar('\n');
		l++;
	}
}
