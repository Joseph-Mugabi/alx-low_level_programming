#include "lists.h"

/**
 * free_listint -  function that frees a listint_t list
 * @head: pointer to the 1st node
 *
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	while ((temp = head) != NULL)
	{
		head = head->next;
		free(temp);
	}
}
