/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandolf <elipandolfo@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 10:39:19 by epandolf          #+#    #+#             */
/*   Updated: 2017/06/28 14:27:00 by epandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_alphabet(void)
{
	char*alpha;
	int i;

	alpha = "abcdefghijklmnopqrstuvwxyz";
	i = 25;
	while (i >= 0)
	{
		ft_putchar(alpha[i]);
		i--;
	}
	ft_putchar('\n');
}
