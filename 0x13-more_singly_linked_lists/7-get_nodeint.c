#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: pointer to the 1st node
 * @index: the nth number or index
 *
 * Return: nth node of a listint_t linked list or returns null if the node
 * doesn't exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int j = 0;

	if (head == NULL)
		return (NULL);

	while ((j < index) && head != NULL)
	{
		head = head->next;
		j++;
	}
	if (j == index)
		return (head);

	return (NULL);
}
