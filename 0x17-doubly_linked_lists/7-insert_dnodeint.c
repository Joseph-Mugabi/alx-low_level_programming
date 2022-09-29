#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - inserts a new node at a given position.
 *  @h: double pointer to the beginning of the linked list
 * @idx: index at which to insert the new node
 * @n: data to enter into new node
 *
 * Returns: the address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *next, *cur_node;
	unsigned int j;

	if (h == NULL)
		return (NULL);
	if (idx != 0)
	{
		cur_node = *h;
		for (j = 0; j < idx - 1 && cur_node != NULL; j++)
			cur_node = cur_node->next;
		if (cur_node == NULL)
			return (NULL);
	}
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	if (idx == 0)
	{
		next = *h;
		*h = new_node;
		new_node->prev = NULL;
	}
	else
	{
		new_node->prev = cur_node;
		next = cur_node->next;
		cur_node->next = new_node;
	}
	new_node->next = next;
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
	return (new_node);
}
