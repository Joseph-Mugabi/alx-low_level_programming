#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: head of a list.
 *
 * Return: the address of the node where the loop starts.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *new, *prev;

	new = head;
	prev = head;
	while (head && new && new->next)
	{
		head = head->next;
		new = new->next->next;

		if (head == new)
		{
			head = prev;
			prev = new;
			while (1)
			{
				new = prev;
				while (new->next != head && new->next != prev)
				{
					new = new->next;
				}
				if (new->next == head)
					break;

				head = head->next;
			}
			return (new->next);
		}
	}
	return (NULL);
}
