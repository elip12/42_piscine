/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandolf <elipandolfo@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 09:51:21 by epandolf          #+#    #+#             */
/*   Updated: 2017/06/29 10:24:07 by epandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_print_combn.h"

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void ft_print_combn(int n)
{
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i;
	int total;

	i = 0;
	total = 0;
	while (i < n)
	{
		array[i++] = i;
		total += 10-1-i;
	}
	while (i >= 0) //now i is n-1
	{
		while (array[i] 
	}

}
