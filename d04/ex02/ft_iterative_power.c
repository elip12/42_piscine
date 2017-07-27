
int ft_iterative_power(int nb, int power)
{
	int pow;

	pow = nb;
	if (power < 0)
		return 0;
	if (power == 0)
		return 1;
	while (power > 1)
	{
		pow *= nb;
		power--;
	}
	return pow;
}