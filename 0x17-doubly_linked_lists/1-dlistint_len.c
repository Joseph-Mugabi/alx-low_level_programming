#include <stdio.h>
#include "lists.h"
/**
 * dlistint_len - returns the number of elements in a linked dlistint_t list.
 * @h: linked list to return
 *
 * Return: number of elements
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t num_elements = 0;

	while (h != NULL)
	{
		h = h->next;
		num_elements++;
	}
	return (num_elements);
}
