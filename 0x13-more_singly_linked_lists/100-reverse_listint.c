#include "lists.h"
/**
 * reverse_listint -  function that reverses a listint_t linked list
 * @head: pointer to the first node
 *
 * Return: a pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
listint_t *tempo;
listint_t *tempo_2;

if (head == NULL || *head == NULL)
return (NULL);
tempo = *head;
*head = tempo->next;
tempo->next = NULL;

while (*head != NULL)
{
tempo_2 = (*head)->next;
tempo = *head;
if (tempo_2 == NULL)
return (*head);
*head = tempo_2;
}
if (*head == NULL)
{
*head = tempo;
return (*head);
}
return (NULL);
}


