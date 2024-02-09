#include "monty.h"

/**
 * q_mod- computes the rest of the division of the second top element
 *  of the stack by the top element of the stack.
 * @head: linkedlist head..
 * @line_number: line_number.
 */
void q_mod(stack_t **head, unsigned int line_number)
{
	stack_t *node = NULL, *prv = NULL;
	int result = 0;

	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	else if ((*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
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
			result = prv->n % node->n;
			node->prev = NULL;
			free(node);
			node = NULL;
			prv->next = NULL;
			prv->n = result;
		}
	}
}

/**
 * q_pchar- pchar this doesn't do anything
 * @h: linkedlist head..
 * @ln: line_number.
 */
void q_pchar(stack_t **h __attribute__((unused)),
unsigned int ln __attribute__((unused)))
{
	;
}
