/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandolf <elipandolfo@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 15:53:05 by epandolf          #+#    #+#             */
/*   Updated: 2017/06/29 22:50:49 by epandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	i--;
	len = i;
	while (i >= len / 2)
	{
		c = str[len - i];
		*(str + (len - i)) = str[i];
		*(str + i) = c;
		i--;
	}
	return (str);
}
