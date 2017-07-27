int 	ft_is_prime(int nb)
{
	int c;

	if (nb <= 0 || nb == 1)
		return 0;
	c = 3;
	while (c <= nb / 4 + 2)
	{
		if (nb % c == 0)
			return 0;
		c += 2;
	}
	return 1;
}