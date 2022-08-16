#include "lists.h"

/**
 * free_listint2 - function that frees a listint_t list.
 * @head: pointer to the 1st node
 *
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;
	listint_t *curNode;

	if (head != NULL)
	{
		currNode =  *heead;
		while ((temp = curNode) != NULL)
		{
			curNode = curNode->next;
			free(temp);
		}
		*head = NULL;
	}
}
