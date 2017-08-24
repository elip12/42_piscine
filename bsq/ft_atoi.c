/*
* ft_atoi.c
* author: Paulina Sprawska
*
* replicates the behavior of the standard library atoi fcn (string to integer).
* see $> man atoi
*/


int		change(char *str, char *num, int len)
{
	int		i;

	i = 0;
	while ((str[i] == ' ') || (str[i] == '\n') || (str[i] == '\t')
		|| (str[i] == '\f') || (str[i] == '\r') || (str[i] == '\v'))
		i++;
	if (((str[i] == '-') || (str[i] == '+'))
		&& (str[i + 1] > 47) && (str[i + 1] < 58))
	{
		num[0] = str[i];
		len++;
		i++;
	}
	while ((str[i] > 47) && (str[i] < 58))
	{
		num[len] = str[i];
		len++;
		i++;
	}
	return (len);
}

int		ft_atoi(char *str)
{
	int		nb;
	int		i;
	char	num[12];
	int		len;

	nb = 0;
	len = 0;
	len = change(str, num, len) - 1;
	i = 1;
	while ((len > -1) && (num[len] != '-') && (num[len] != '+'))
	{
		nb = nb + (num[len] - 48) * i;
		i *= 10;
		len--;
	}
	if (num[0] == '-')
		nb = nb - nb - nb;
	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	return (nb);
}
