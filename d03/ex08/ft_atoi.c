/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandolf <elipandolfo@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 17:45:58 by epandolf          #+#    #+#             */
/*   Updated: 2017/06/29 22:39:12 by epandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int s[10];
	int out;
	int stri;
	int head;
	int toggle;

	toggle = 1;
	head = 0;
	stri = 0;
	if (str[0] == '-')
	{
		toggle = -1;
		stri = 1;
	}
	while (str[stri] != '\0')
		stri++;
	stri--;
	while (stri >= (toggle - 1) / -2)
		s[head++] = str[stri--] - 48;
	while (head <= 9)
		s[head++] = 0;
	out = s[0] + s[1] * 10 + s[2] * 100 + s[3] * 1000 + s[4] * 10000;
	out += s[5] * 100000 + s[6] * 1000000 + s[7] * 10000000;
	out = toggle * (out + s[8] * 100000000 + s[9] * 1000000000);
	return (out);
}
