/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandolf <elipandolfo@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 10:39:19 by epandolf          #+#    #+#             */
/*   Updated: 2017/06/28 14:22:23 by epandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_alphabet(void)
{
	char*alpha;
	int i;

	alpha = "abcdefghijklmnopqrstuvwxyz";
	i = 0;
	while (i < 26)
	{
		ft_putchar(alpha[i]);
		i++;
	}
	ft_putchar('\n');
}
