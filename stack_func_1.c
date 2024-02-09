#include "monty.h"

/**
 * push- _getchunck this function push element to the stack
 * @head: linkedlist head..
 * @data: first index.
 *
 * Return: return function name if ther's error and null if isn't.
 */
char *push(stack_t **head, unsigned int data)
{
	stack_t *node = NULL, *new_node = NULL;
	stack_t *pv = NULL;

	if ((*head) == NULL)
	{
		(*head) = malloc(sizeof(stack_t));
		(*head)->n = data;
		(*head)->next = NULL;
		(*head)->prev = NULL;
	}
	else
	{
		node = (*head);
		while (node != NULL)
		{
			pv = node;
			node = node->next;
		}
		new_node = malloc(sizeof(stack_t));
		new_node->n = data;
		new_node->next = NULL;
		new_node->prev = pv;
		pv->next = new_node;
	}
	return (NULL);
}

/**
 * pall- pall this function print all stack element if FILO order
 * @head: linkedlist head.
 * @line_number: line_number.
 *
 * Return: return function name if ther's error and null if isn't.
 */
char *pall(stack_t **head, unsigned int line_number)
{
	stack_t *node = NULL;

	if ((*head) == NULL)
		return (NULL);
	node = (*head)->next;
	pall(&node, line_number);
	printf("%d\n", (*head)->n);
	return (NULL);
}
/**
 * pint- pint print the element at the top of stack
 * @head: linkedlist head.
 * @line_number: line_number.
 *
 * Return: return function name if ther's error and null if isn't.
 */

char *pint(stack_t **head,
unsigned int line_number __attribute__((unused)))
{
	stack_t *node = NULL;

	if ((*head) != NULL)
	{
		node = (*head);
		while (node->next != NULL)
		{
			node = node->next;
		}
		printf("%d\n", node->n);
	}
	else
		return ("pint");
	return (NULL);
}

/**
 * pop- pop this function delete the top element of the stack
 * @head: linkedlist head.
 * @line_number: line_number.
 *
 * Return: return function name if ther's error and null if isn't.
 */
char *pop(stack_t **head,
unsigned int line_number __attribute__((unused)))
{
	stack_t *node = NULL, *prv = NULL;

	if ((*head) == NULL)
		return ("pop");
	else if ((*head)->next == NULL)
	{
		free((*head));
		(*head) = NULL;
	}
	else if ((*head) != NULL)
	{
		node = (*head);
		while (node->next != NULL)
		{
			node = node->next;
		}
		prv = node->prev;
		node->prev = NULL;
		free(node);
		node = NULL;
		prv->next = NULL;
	}
	return (NULL);
}

/**
 * swap- swap this function the top two element of the stack
 * @head: linkedlist head..
 * @line_number: line_number.
 *
 * Return: return function name if ther's error and null if isn't.
 */
char *swap(stack_t **head,
unsigned int line_number __attribute__((unused)))
{
	stack_t *node = NULL, *prv = NULL;
	int tmp = 0;

	if ((*head) != NULL)
	{
		if ((*head)->next != NULL)
		{
			node = (*head);
			while (node->next != NULL)
			{
				node = node->next;
			}
			prv = node->prev;
			tmp = node->n;
			node->n = prv->n;
			prv->n = tmp;
		}
		else
			return ("swap");
	}
	else
		return ("swap");
	return (NULL);
}
