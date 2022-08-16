#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index
 * index of a listint_t linked list
 * @head: points to the 1st node
 * @index: index of the node that should be deleted.
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int j = 0;
	listint_t *prev;
	listint_t *next;

	if (*head == NULL)
		return (-1);

	prev = *head;
	if (index == 0)
	{
		*head = prev->next;
		free(prev);
		return (1);
	}

	while (j < (index - 1) && prev != NULL)
	{
		prev = prev->next;
		j++;
	}
	next = prev->next;
	prev->next = prev->next->next;
	free(next);

	return (1);
}
