
int ft_iterative_factorial(int nb)
{
	int fact;
	
	if(nb <= 0)
		return 0;
	fact = 1;
	while (nb > 1)
		fact *= nb--;
	return fact;
}