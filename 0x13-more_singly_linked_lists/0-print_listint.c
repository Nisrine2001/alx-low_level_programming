#include "lists.h"
#include <stdio.h>

/**
 * print_listint - prints all the elements of a listint_t list.
 * @h: pointer to the head of list_t
 *
 * Return: the number of nodes
 */
size_t print_listint(const listint_t *h)
{
size_t nodes = 0;

if (!h)
return (0);

while (h)
{
printf("%d\n", h->n);
h = h->next;
nodes++;
}

return (nodes);
}
