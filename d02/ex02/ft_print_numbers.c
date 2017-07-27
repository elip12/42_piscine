/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandolf <elipandolfo@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 14:16:44 by epandolf          #+#    #+#             */
/*   Updated: 2017/06/28 21:52:04 by epandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_numbers(void)
{
	char*digits;
	int i;

	digits = "0123456789\n";
	i = 0;
	while (i < 11)
	{
		ft_putchar(digits[i]);
		i++;
	}
	ft_putchar('\n');
}
