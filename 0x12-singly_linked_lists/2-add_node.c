#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - Adds a new node at the beginning of a list_t list.
 * @head: Pointer to a pointer to the list_t list.
 * @str: String to be duplicated and added to the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	char *str_copy;
	size_t str_length;

	if (!str)
		return (NULL);

	str_length = strlen(str);

	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);

	str_copy = strdup(str);
	if (!str_copy)
	{
	free(new_node);
		return (NULL);
	}

	new_node->str = str_copy;
	new_node->len = str_length;
	new_node->next = *head;

	*head = new_node;

	return (new_node);
}

