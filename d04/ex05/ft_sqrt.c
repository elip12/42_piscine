int ft_sqrt(int nb)
{
	int c;
	int ret;
	
	if (nb < 0)
		return 0;
	c = 1;
	ret = 0;
	while (c <= nb / 4 + 1)
	{
		if (nb / c == c)
			return c;
		c++;
	}
	return 0;
}