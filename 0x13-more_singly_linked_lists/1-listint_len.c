#include "lists.h"

/**
 * listint_len - function that returns the number of 
 * elements in a linked listint_t list.
 * @h: linked list to print
 *
 * Return: returns the number of elements in a linked 
 */
size_t listint_len(const listint_t *h)
{
	size_t a = 0;

	while (h != NULL)
	{
		h = h->next;
		a++;
	}
	return (a);
}
