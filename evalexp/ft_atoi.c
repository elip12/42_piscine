/*
* ft_atoi.c
* author: Eli Pandolfo
* replicates C's atoi function
* converts a string to an integer, where the string can have any whitespaces
* before the first sign or number, works with - and + signs, and will evaluate
* "   -234t567" as -234
*/

#include "deque.h"

/* makes sure the string is valid, and determines the location of the first sign or number
* in the expression
*/
int		check_valid(char *str)
{
	int c;
	int head;

	c = 0;
	head = -1;
	while (str[c] != '\0')
	{
		if (head == -1 && (str[c] == '-' || (str[c] >= '0' && str[c] <= '9')))
			head = c;
		c++;
	}
	c = 0;
	while (c < head)
	{
		if (!((str[c] >= 9 && str[c] <= 13) || str[c] == ' '))
			if (!(c == head - 1 && str[c] == '+' && str[head] != '-'))
				return (-1);
		c++;
	}
	return (head);
}

/* converts a string into an integer */
int		ft_atoi(char *str)
{
	int head;
	int toggle;
	int result;
	int tens;
	int stri;

	toggle = 1;
	head = check_valid(str);
	if (!(result = 0) && (head == -1))
		return (0);
	if (str[head] == '-' && (stri = -1))
	{
		toggle = -1;
		stri = head++ + 1;
	}
	while ((tens = 1) && str[stri + 1] != '\0')
		stri++;
	while (stri >= head)
	{
		result += (str[stri] - 48) * tens;
		tens *= 10;
		if (str[stri] < '0' || str[stri] > '9')
		{
			result = 0;
			tens = 1;
		}
		stri--;
	}
	return (toggle * result);
}
