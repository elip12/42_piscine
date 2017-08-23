/*
* eval_expr.c
* author: Eli Pandolfo
*
* evaluates a mathematical expression. Uses the shunting-yard algorithm to convert
* to reverse polish notation, then evalutes the expression in reverse polish notation
*
* NOTE: a negative number must have the negative sign directly before the number
*	ex: 1--1 = 2, 1 - -1 = 2, 1- -1 = 2, 1- - 1 = seg fault
*/

#include "deque.h"

/* helper function for converting to postfix, to keep method under 25 lines */
void	pf_helper(char *exp, int c, t_node **queue, t_node **opstack)
{
	if (is_op(exp[c]))
	{
		while (*opstack && prec(((char *)peek(opstack))[0]) >= prec(exp[c]))
			push(queue, pop(opstack));
		push(opstack, ft_chardup(exp[c]));
	}
	else if (exp[c] == '(')
		push(opstack, ft_chardup(exp[c]));
	else if (exp[c] == ')')
	{
		while (*opstack && ((char *)(peek(opstack)))[0] != '(')
			push(queue, pop(opstack));
		pop(opstack);
	}
}

/* an implementation of the shunting-yard algorithm to convert an expression into
* reverse polish notation (postifx notation). Uses 2 deques to simulate a stack and a queue.
* takes in an expression (string from command line), and 2 ints (basically local counters, but
* when writing the program I had to keep all methods under 25 lines).
* Returns a queue contating the RPN expression
*/
t_node	*to_postfix(char *exp, int c, int arraycount)
{
	t_node			*queue;
	t_node			*opstack;
	static char		*num[1000];

	queue = 0;
	opstack = 0;
	while (exp[c])
	{
		if ((exp[c] >= '0' && exp[c] <= '9') || (exp[c] == '-' &&
			(exp[c + 1] >= '0' && exp[c + 1] <= '9')))
		{
			num[arraycount] = next_num(exp, c);
			push(&queue, num[arraycount++]);
			while (exp[c + 1] >= '0' && exp[c + 1] <= '9')
				c++;
		}
		pf_helper(exp, c, &queue, &opstack);
		c++;
	}
	while (opstack)
		push(&queue, pop(&opstack));
	return (queue);
}

/* evaluates the expression in postfix. Takes in a queue, outputs an int. */
int		*eval_postfix(t_node *queue)
{
	t_node		*stack;
	int			*op1;
	int			*op2;
	static int	result[1000] = {0};
	int			count;

	stack = 0;
	count = 0;
	while (queue)
	{
		if (((char *)q_peek(&queue))[1] == 0 && is_op(*(char *)q_peek(&queue)))
		{
			op1 = pop(&stack);
			op2 = pop(&stack);
			result[count] = operate((char *)dequeue(&queue), *op1, *op2);
			push(&stack, &result[count]);
		}
		else
		{
			result[count] = ft_atoi((char *)dequeue(&queue));
			push(&stack, &result[count]);
		}
		count++;
	}
	return ((int *)pop(&stack));
}

/* takes an expression in the form of a string, converts it to postfix,
* evaluates the postfix expression, and returns the result
*/
int		eval_expr(char *str)
{
	t_node	*postfix;
	int		*result;

	postfix = to_postfix(str, 0, 0);
	result = eval_postfix(postfix);
	return (*result);
}

/* uses command line args to evaluate a single expression */
int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
