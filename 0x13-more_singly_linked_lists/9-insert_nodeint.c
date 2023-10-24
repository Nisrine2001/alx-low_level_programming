#include "lists.h"

/**
 * insert_nodeint_at_index - function that inserts a new node
 * at a given position
 * @head: pointer to a first node
 * @n: integer for new node inserted
 * @idx: index of the list where the new node should be added
 * Index starts at 0
 *
 * Return: Returns: the address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
unsigned int o;
listint_t *new_node;
listint_t *tempo = *head;

new_node = malloc(sizeof(listint_t));

if (!new_node || !head)
return (NULL);

new_node->n = n;
new_node->next = NULL;
if (idx == 0)
{
new_node->next = *head;
*head = new_node;
return (new_node);
}
for (o = 0; tempo && o < idx; o++)
{
if (o == idx - 1)
{
new_node->next = tempo->next;
tempo->next = new_node;
return (new_node);
}
else
tempo = tempo->next;
}
return (NULL);

}
