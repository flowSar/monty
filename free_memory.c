 #include "monty.h"
/**
 * free_memory- free_memory for free used memory by 2D list.
 * @list: matrix.
 *
 */
void free_memory(char **list)
{
	int i = 0;

	if (list != NULL)
	{
		while (list[i] != NULL)
		{
			free(list[i]);
			i++;
		}
		free(list);
	}
}

/**
 * free_linked_list- this function for free linkedlist.
 * @head: linkedlist head.
 *
 */
void free_linked_list(List **head)
{
	List *node = NULL;

	if ((*head) == NULL)
		return;
	node = (*head)->next;
	free_linked_list(&node);
	free((*head)->content);
	free((*head));
}

/**
 * free_stack- this function for free tack.
 * @head: sack head.
 *
 */
void free_stack(stack_t **head)
{
	stack_t *node = NULL;

	if ((*head) == NULL)
		return;
	node = (*head)->next;
	free_stack(&node);
	free((*head));
	(*head) = NULL;
}
