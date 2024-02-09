#include "monty.h"

/**
 * q_push- q_push this function push element to the stack
 * @head: linkedlist head..
 * @data: first index.
 */
void q_push(stack_t **head, unsigned int data)
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
}

/**
 * q_pall- q_pall this function print all stack element if FILO order
 * @head: linkedlist head.
 * @line_number: line_number.
 */
void q_pall(stack_t **head, unsigned int line_number)
{
	stack_t *node = NULL;

	if ((*head) == NULL)
		return;
	node = (*head)->next;
	pall(&node, line_number);
	printf("%d\n", (*head)->n);
}
/**
 * q_pint- q_pint print the element at the top of stack
 * @head: linkedlist head.
 * @line_number: line_number.
 */

void q_pint(stack_t **head, unsigned int line_number)
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
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * q_pop- q_pop this function delete the top element of the stack
 * @head: linkedlist head.
 * @line_number: line_number.
 *
 * Return: return piece of string.
 */
void q_pop(stack_t **head, unsigned int line_number)
{
	stack_t *node = NULL, *prv = NULL;

	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
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
}

/**
 * q_swap- q_swap this function the top two element of the stack
 * @head: linkedlist head..
 * @line_number: line_number.
 */
void q_swap(stack_t **head, unsigned int line_number)
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
		{
			fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
			exit(EXIT_FAILURE);
		}

	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

}
