/*
* helper_fcns.c
* author: Eli Pandolfo
*
* some helper functions called by eval_expr.c
*/

#include "deque.h"

/* duplicates a character with malloc */
char	*ft_chardup(char c)
{
	char	*str;

	str = malloc(2);
	str[0] = c;
	str[1] = 0;
	return (str);
}

/* checks if a char is an operator (+, -, *, /, %) */
int		is_op(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*' || c == '%')
		return (1);
	else
		return (0);
}

/* returns the next number in a string expression given the expression and a postion index */
char	*next_num(char *exp, int c)
{
	int		length;
	int		d;
	char	*num;

	length = 0;
	d = c;
	while (exp[d] != ' ' && exp[d] != '(' && exp[d] != ')' && exp[d] &&
		(!is_op(exp[d]) || (exp[d] == '-' && (exp[d + 1] >= '0' &&
		exp[d + 1] <= '9'))))
	{
		length++;
		d++;
	}
	num = (char *)malloc(length + 1);
	d = 0;
	while (d < length)
		num[d++] = exp[c++];
	num[d] = '\0';
	return (num);
}

/* performs a numerical operation on 2 ints */
int		operate(char *c, int op1, int op2)
{
	if (*c == '+')
		return (op2 + op1);
	else if (*c == '-')
		return (op2 - op1);
	else if (*c == '*')
		return (op2 * op1);
	else if (*c == '/')
		return (op2 / op1);
	else if (*c == '%')
		return (op2 % op1);
	else
		return (0);
}

/* assigns precedence to operators (* / %, then + -) */
int		prec(char op)
{
	int precedence;

	precedence = 0;
	if (op == '*' || op == '/' || op == '%')
		precedence = 2;
	else if (op == '+' || op == '-')
		precedence = 1;
	return (precedence);
}
