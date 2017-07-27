/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandolf <elipandolfo@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 19:40:31 by epandolf          #+#    #+#             */
/*   Updated: 2017/06/29 11:12:28 by epandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(int nb)
{
	int rem;
	int stack[12];

	if ((stack[1] = 11) && nb < 0)
	{
		stack[0] = 1;
		nb = nb * -1;
	}
	while (nb > 0)
	{
		rem = nb % 10;
		nb = nb / 10;
		stack[stack[1]--] = rem;
	}
	if (stack[0] == 1)
		ft_putchar('-');
	while (stack[1] + 1 <= 10)
	{
		rem = stack[1 + stack[1]++] + 48;
		ft_putchar(rem);
	}
	if (nb == 0)
		ft_putchar('0');
	ft_putchar('\n');
	stack[0] = 0;
}
