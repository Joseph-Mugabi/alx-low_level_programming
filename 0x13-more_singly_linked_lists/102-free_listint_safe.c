#include "lists.h"
/**
 * free_listp2 - frees a linked list
 *  @head: head of a list.
 */
void free_listp2(listpt_t **head)
{
	listpt_t *tmp, *curNode;

	if (head != NULL)
	{
		curNode = *head;

		while ((tmp = curNode) != NULL)
		{
			curNode = curNode->next;
			free(tmp);
		}
		*head = NULL;
	}
}

/**
 * free_listint_safe - function that frees a listint_t list.
 * @h: head of a list.
 *
 * Return: the size of the list that was free’d
 */
size_t free_listint_safe(listint_t **h)
{
	size_t numNode = 0;
	listpt_t *ptr, *new, *prev;
	listint_t *curNode;

	ptr = NULL;
	while (*h != NULL)
	{
		new = malloc(sizeof(listpt_t));

		if (new == NULL)
			exit(98);

		new->pt = (void *)*h;
		new->next = ptr;
		ptr = new;

		prev = ptr;
		while (prev->next != NULL)
		{
			prev = prev->next;
			if (*h == prev->pt)
			{
				*h = NULL;
				free_listp2(&ptr);
				return (numNode);
			}
		}
		curNode = *h;
		*h = (*h)->next;
		free(curNode);
		numNode++;
	}
	*h = NULL;
	free_listp2(&ptr);
	return (numNode);
}
