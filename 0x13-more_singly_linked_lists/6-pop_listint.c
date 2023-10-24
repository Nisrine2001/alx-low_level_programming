#include "lists.h"

/**
 * pop_listint - it deletes the head node of a listint_t linked list
 * and returns the head node’s data (n)
 * @head: pointer to a first node
 *
 * Return: if the linked list is empty return 0
 */
int pop_listint(listint_t **head)
{
listint_t *current;
int n;

if (*head == NULL)
return (0);

current = *head;
n = (*head)->n;
*head = (*head)->next;

free(current);

return (n);
}
