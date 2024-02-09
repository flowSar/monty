#include "monty.h"
/**
 * add- add this function add top two element of the stack
 * @head: linkedlist head..
 * @line_number: line_number.
 *
 * Return: return function name if ther's error and null if isn't.
 */
char *add(stack_t **head,
unsigned int line_number __attribute__((unused)))
{
	stack_t *node = NULL, *prv = NULL;
	int result = 0;

	if ((*head) == NULL)
		return ("add");
	else if ((*head)->next == NULL)
		return ("add");

	node = (*head);
	while (node->next != NULL)
	{
		node = node->next;
	}
	prv = node->prev;
	result = prv->n + node->n;
	node->prev = NULL;
	free(node);
	node = NULL;
	prv->next = NULL;
	prv->n = result;

	return (NULL);
}
/**
 * nop- add this doesn't do anything
 * @h: linkedlist head..
 * @ln: line_number.
 *
 * Return: return function name if ther's error and null if isn't.
 */
char *nop(stack_t **h __attribute__((unused)),
unsigned int ln __attribute__((unused)))
{
	return (NULL);
}
/**
 * sub- subtract the top element from the second top element of the stack
 * @head: linkedlist head..
 * @line_number: line_number.
 *
 * Return: return function name if ther's error and null if isn't.
 */
char *sub(stack_t **head,
unsigned int line_number __attribute__((unused)))
{
	stack_t *node = NULL, *prv = NULL;
	int result = 0;

	if ((*head) == NULL)
		return ("sub");
	else if ((*head)->next == NULL)
		return ("sub");

	node = (*head);
	while (node->next != NULL)
	{
		node = node->next;
	}
	prv = node->prev;
	result = prv->n - node->n;
	node->prev = NULL;
	free(node);
	node = NULL;
	prv->next = NULL;
	prv->n = result;

	return (NULL);
}
/**
 * div_fu- div_fu the top element from the second top element of the stack
 * @head: linkedlist head..
 * @line_number: line_number.
 *
 * Return: return function name if ther's error and null if isn't.
 */
char *div_fu(stack_t **head,
unsigned int line_number __attribute__((unused)))
{
	stack_t *node = NULL, *prv = NULL;
	int result = 0;

	if ((*head) == NULL)
		return ("div");
	else if ((*head)->next == NULL)
		return ("div");

	node = (*head);
	while (node->next != NULL)
	{
		node = node->next;
	}
	prv = node->prev;
	if (node->n == 0)
		return ("division");

	result = prv->n / node->n;
	node->prev = NULL;
	free(node);
	node = NULL;
	prv->next = NULL;
	prv->n = result;

	return (NULL);
}
/**
 * mul- multiply the top element two of the stack.
 * @head: linkedlist head..
 * @line_number: line_number.
 *
 * Return: return function name if ther's error and null if isn't.
 */
char *mul(stack_t **head,
unsigned int line_number __attribute__((unused)))
{
	stack_t *node = NULL, *prv = NULL;
	int result = 0;

	if ((*head) == NULL)
		return ("mul");
	else if ((*head)->next == NULL)
		return ("mul");

	node = (*head);
	while (node->next != NULL)
	{
		node = node->next;
	}
	prv = node->prev;
	result = prv->n * node->n;
	node->prev = NULL;
	free(node);
	node = NULL;
	prv->next = NULL;
	prv->n = result;

	return (NULL);
}
