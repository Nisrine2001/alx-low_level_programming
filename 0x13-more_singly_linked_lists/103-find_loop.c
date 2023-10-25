#include "lists.h"

/**
 * find_listint_loop - function that finds the loop in a linked list
 * @head: pointer to linked list
 *
 * Return: The address of the node where the loop starts
 *  or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
listint_t *first_nis;
listint_t *end_nis;

if (head == NULL || head->next == NULL)
return (NULL);

first_nis = (head->next)->next;
end_nis = (head->next)->next;

while (end_nis)
{
if (first_nis == end_nis)
{
first_nis = head;
while (first_nis != end_nis)
{
first_nis = first_nis->next;
end_nis = end_nis->next;
}
return (first_nis);
}
first_nis = first_nis->next;
end_nis = end_nis->next;
}
return (NULL);
}
