#include <stdio.h>

int ft_iterative_factorial(int nb)
{
	int fact;
	if(nb <= 0)
		return 0;
	fact = 1;
	while (nb > 1)
	{
		fact *= nb--;
	}
	return fact;
}

int ft_recursive_factorial(int nb)
{
	if (nb <= 0)
		return 0;
	if (nb == 1)
		return 1;
	return  nb * ft_recursive_factorial(nb - 1);
}

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

int ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return 0;
	if (power == 0)
		return 1;
	return (nb * ft_recursive_power(nb, power - 1));
}

int ft_fibonacci(int index)
{
	if (index < 0)
		return -1;
	if (index == 0)
		return 0;
	if (index == 1)
		return 1;
	return ft_fibonacci(index-1) + ft_fibonacci(index - 2);
}

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

int ft_is_prime(int nb)
{
	int c;

	if (nb <= 0 || nb == 1 || (nb != 2 && nb % 2 == 0))
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

int main (void)
{
	int n = ft_is_prime(2147483647);
	printf("%d\n", n);
}

//gcc -Wall -Wextra -Werror -o 