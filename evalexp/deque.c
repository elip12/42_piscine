/*
* deque.c
* author: Eli Pandolfo
*
* With deque.h, implements a deque data structure: a combination of a stack and a queue (LIFO and LILO),
* that uses a linked list as the base structure. I use this since the shunting-yard algorithm and RPN
* evaluation use both a stack and a queue.
*/

#include "deque.h"

/* pushes a node onto the front of the deque */
void		push(t_node **head, void *data)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	newnode->data = data;
	newnode->next = *head;
	*head = newnode;
}

/* pops a node off the head of the deque, and returns that node's data */
void		*pop(t_node **head)
{
	t_node	*temp;
	void	*val;

	temp = *head;
	if (!temp)
		return (0);
	*head = (*head)->next;
	val = (temp->data);
	free(temp);
	return (val);
}

/* pops a node off the end of the list and return's that node's data */
void		*dequeue(t_node **head)
{
	t_node	*temp;
	t_node	*prev;
	void	*val;

	temp = *head;
	if (!temp)
		return (0);
	if (!(temp->next))
	{
		val = temp->data;
		free(temp);
		*head = 0;
		return (val);
	}
	prev = 0;
	while (temp->next)
	{
		prev = temp;
		temp = temp->next;
	}
	val = temp->data;
	free(temp);
	prev->next = 0;
	return (val);
}

/* returns the element at the head of the list */
void		*peek(t_node **head)
{
	void	*ret;

	ret = pop(head);
	push(head, ret);
	return (ret);
}

/* returns the element at the tail of the list */
void		*q_peek(t_node **head)
{
	t_node	*temp;

	temp = *head;
	if (!temp)
		return (0);
	if (!temp->next)
		return (temp->data);
	while (temp->next)
		temp = temp->next;
	return (temp->data);
}
