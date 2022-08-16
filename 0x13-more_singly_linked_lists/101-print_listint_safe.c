#include "lists.h"

/**
 * free_listpt - frees a linked list.
 * @head: head of the list.
 */
void free_listpt(listpt_t **head)
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
 * print_listint_safe - prints a listint_t linked list.
 * @head: head of a list.
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t num_nodes = 0;
	listpt_t *ptr, *new, *old;

	ptr = NULL;
	while (head != NULL)
	{
		new = malloc(sizeof(listpt_t));

		if (new == NULL)
			exit(98);

		new->pt = (void *)head;
		new->next = ptr;
		ptr = new;

		old = ptr;

		while (old->next != NULL)
		{
			old = old->next;
			if (head == old->pt)
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free_listpt(&ptr);
				return (num_nodes);
			}
		}
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		num_nodes++;
	}
	free_listpt(&ptr);
	return (num_nodes);
}
