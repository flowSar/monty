#include "monty.h"

/**
 * mod- computes the rest of the division of the second top element
 *  of the stack by the top element of the stack.
 * @head: linkedlist head..
 * @line_number: line_number.
 *
 * Return: return function name if ther's error and null if isn't.
 */
char *mod(stack_t **head,
unsigned int line_number __attribute__((unused)))
{
	stack_t *node = NULL, *prv = NULL;
	int result = 0;

	if ((*head) == NULL)
		return ("mod");
	else if ((*head)->next == NULL)
		return ("mod");

	node = (*head);
	while (node->next != NULL)
	{
		node = node->next;
	}
	prv = node->prev;
	if (node->n == 0)
		return ("division");

	result = prv->n % node->n;
	node->prev = NULL;
	free(node);
	node = NULL;
	prv->next = NULL;
	prv->n = result;

	return (NULL);
}

/**
 * pchar- pchar this doesn't do anything
 * @h: linkedlist head..
 * @ln: line_number.
 *
 * Return: return function name if ther's error and null if isn't.
 */
char *pchar(stack_t **h __attribute__((unused)),
unsigned int ln __attribute__((unused)))
{
	return (NULL);
}
