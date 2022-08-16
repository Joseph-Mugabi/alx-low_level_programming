#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head: point to the 1st node
 * idx: index of the list where the new node should be added
 * @n: n nodes
 *
 * Returns: the address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int j = 0;
	listint_t *newNode, *temp;

	if (head == NULL)
		return (NULL);

	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (NULL);
	newNode->n = n;

	if (idx == 0)
	{
		newNode->next = *head;
		*head= newNode;
		return (newNode);
	}

	temp = *head;
	while (j < (idx - 1))
	{
		temp = temp->next;
		j++;

		if (temp == NULL)
		{
			free(newNode);
			return (NULL);
		}
	}
	newNode->next = temp->next;
	temp->next = newNode;
	return (newNode);
}
