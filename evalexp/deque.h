/*
* deque.h
* author: Eli Pandolfo
*
* header file for a deque and a RPN expression evaluator program
*/

#ifndef FT_DEQUE_H
# define FT_DEQUE_H

# include <stdlib.h>
# include <unistd.h>

/* a t_node is a node in a linked list holding a void pointer for data and a
* pointer to the next node in the list
*/
typedef	struct		s_node
{
	struct s_node	*next;
	void			*data;
}					t_node;

void				push(t_node **head, void *data);
void				*pop(t_node **head);
void				*dequeue(t_node **head);
void				*peek(t_node **head);
void				*q_peek(t_node **head);

int					ft_atoi(char *str);
int					is_op(char c);
char				*next_num(char *exp, int c);
int					operate(char *c, int op1, int op2);
int					prec(char op);
void				ft_putchar(char c);
void				ft_putnbr(int nb);
char				*ft_chardup(char c);

#endif
