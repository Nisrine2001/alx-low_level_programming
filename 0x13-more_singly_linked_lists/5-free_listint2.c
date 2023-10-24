#include "lists.h"

/**
 * free_listint2 _ function that frees a listint_t list
 * @head: pointer to a first node
 *
 * Return: The function sets the head to NULL
 */
void free_listint2(listint_t **head)
{
listint_t *current;
listint_t *node;

if (!head)
return;
current = *head;

while (current)
{
node = current;
current = node->next;
free(node);
}
*head = NULL;
}
