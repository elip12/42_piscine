/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 21:29:30 by epandolf          #+#    #+#             */
/*   Updated: 2017/06/29 22:38:37 by epandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)
{
	int min;
	int itr;
	int c;
	int temp;

	c = 0;
	while (c < size)
	{
		itr = c;
		min = c;
		while (itr < size)
		{
			if (tab[itr] < tab[min])
				min = itr;
			itr++;
		}
		temp = tab[c];
		tab[c] = tab[min];
		tab[min] = temp;
		c++;
	}
}
