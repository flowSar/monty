#include "monty.h"
/**
 * q_add- q_add this function add top two element of the stack
 * @head: linkedlist head..
 * @line_number: line_number.
 */
void q_add(stack_t **head, unsigned int line_number)
{
	stack_t *node = NULL, *prv = NULL;
	int result = 0;

	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
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
	}
}
/**
 * q_nop- add this doesn't do anything
 * @h: linkedlist head..
 * @ln: line_number.
 */
void q_nop(stack_t **h __attribute__((unused)),
unsigned int ln __attribute__((unused)))
{
	;
}
/**
 * q_sub- subtract the top element from the second top element of the stack
 * @head: linkedlist head..
 * @line_number: line_number.
 */
void q_sub(stack_t **head, unsigned int line_number)
{
	stack_t *node = NULL, *prv = NULL;
	int result = 0;

	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
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
	}
}
/**
 * q_div_fu- div_fu the top element from the second top element of the stack
 * @head: linkedlist head..
 * @line_number: line_number.
 */
void q_div_fu(stack_t **head, unsigned int line_number)
{
	stack_t *node = NULL, *prv = NULL;
	int result = 0;

	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	else if ((*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	else
	{
		node = (*head);
		while (node->next != NULL)
		{
			node = node->next;
		}
		prv = node->prev;
		if (node->n == 0)
		{
			fprintf(stderr, "division by zero\n");
			exit(EXIT_FAILURE);
		}

		else
		{
			result = prv->n / node->n;
			node->prev = NULL;
			free(node);
			node = NULL;
			prv->next = NULL;
			prv->n = result;
		}
	}
}
/**
 * q_mul- multiply the top element two of the stack.
 * @head: linkedlist head..
 * @line_number: line_number.
 */
void q_mul(stack_t **head, unsigned int line_number)
{
	stack_t *node = NULL, *prv = NULL;
	int result = 0;

	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	else if ((*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	else
	{
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
	}
}
