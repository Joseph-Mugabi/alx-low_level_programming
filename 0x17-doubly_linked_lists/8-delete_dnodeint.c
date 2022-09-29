#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index
 * index of a dlistint_t linked list.
 * @index: index is the index of the node that
 * should be deleted. Index starts at 0
 * @head: double pointer to the linked list
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *curr_node;
	unsigned int j;

	if (head == NULL || *head == NULL)
		return (-1);

	curr_node = *head;
	if (index == 0)
	{
		*head = curr_node->next;
		if (curr_node->next != NULL)
			curr_node->next->prev = NULL;
		free(curr_node);
		return (1);
	}
	for (j = 0; j < index; j++)
	{
		if (curr_node->next == NULL)
			return (-1);
		curr_node = curr_node->next;
	}
	curr_node->prev->next = curr_node->next;
	if (curr_node->next != NULL)
		curr_node->next->prev = curr_node->prev;
	free(curr_node);
	return (1);
}
