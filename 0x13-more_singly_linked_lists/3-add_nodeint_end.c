#include "lists.h"

/**
 * add_nodeint_end - adds a node to the end of a linked list
 * @head: Pointer to the head of listint_t list
 * @n: the integer for the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n);
{
listint_t *new_node, *last_node;

new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
	return (NULL);

new_node->n = n;
new_node->next = NULL;

if (*head == NULL)
	*head = new_node;
else
{
	last_node = *head;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = new_node;
}
return (*head);
}
