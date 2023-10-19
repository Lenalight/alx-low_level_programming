#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Frees a linked list.
 * @head: Pointer to the list_t list to be freed.
 */
void free_list(list_t *head)
{
	list_t *current_node;

	while (head)
	{
	current_node = head->next;
	free(head->str);
	free(head);
	head = current_node;
	}
}

