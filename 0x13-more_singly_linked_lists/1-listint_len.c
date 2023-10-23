#include "lists.h"

/**
 *listint_len -  returns the number of elements in a linked listint_t list.
 *@h: pointer to the head of a linked listint_t list.
 *
 * Return: number of element in listint_t list.
 */

size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	if (h == NULL)
		return (0);

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}
