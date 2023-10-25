#include "lists.h"


/**
 * delete_nodeint_at_index - deletes a node at the index of listint_t
 * @head: pointer to a first node
 * @index:  index of the node that should be deleted. Index starts at 0
 *
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{

listint_t *tempo = *head;
listint_t *current = NULL;

unsigned int o = 0;

if (*head == NULL)
return (-1);
if (index == 0)
{
*head = (*head)->next;

free(tempo);

return (1);

}


while (o < index - 1)

{

if (!tempo || !(tempo->next))

return (-1);

tempo = tempo->next;

o++;

}

current = tempo->next;

tempo->next = current->next;

free(current);

return (1);

}
