#include "lists.h"

/**
 * free_listint - function that frees a listint_t list
 * @head: pointer to a first node
 *
 * Return: nothing
 */
void free_listint(listint_t *head)
{
listint_t *current;
while (head)
{
current = head;
head = head->next;
free(current);
}
}
