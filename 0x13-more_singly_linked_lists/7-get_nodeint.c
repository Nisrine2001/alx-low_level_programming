#include "lists.h"

/**
 * get_nodeint_at_index - function that returns the nth node
 * of a listint_t linked list
 * @head: pointer to a fisrt node
 * @index:  the index of the node, starting at 0
 *
 * Return: if the node does not exist, return NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int s;

for (s = 0; s < index; s++)
{
if (head == NULL)
return (NULL);

head = head->next;
}
return (head);
}
