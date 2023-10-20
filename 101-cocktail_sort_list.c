#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked
 * list of integers in ascending order
 * using the Cocktail Shaker sort algorithm
 * @list: A pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		temp = *list;

		while (temp->next != NULL)
		{
			if (temp->n > temp->next->n)
			{
				swap_nodes(list, &temp, &temp->next);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				temp = temp->next;
			}
		}
		if (!swapped)
			break;
		swapped = 0;

		while (temp->prev != NULL)
		{
			if (temp->n < temp->prev->n)
			{
				swap_nodes(list, &temp, &temp->prev);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				temp = temp->prev; }
		}
	} while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: A pointer to the head of the list
 * @node1: A pointer to the first node to be swapped
 * @node2: A pointer to the second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2)
{
	listint_t *prev_node1, *next_node1, *prev_node2, *next_node2;

	prev_node1 = (*node1)->prev;
	next_node1 = (*node1)->next;
	prev_node2 = (*node2)->prev;
	next_node2 = (*node2)->next;

	if (prev_node1)
		prev_node1->next = (*node2);
	else
		*list = (*node2);
	(*node2)->prev = prev_node1;

	if (next_node2)
		next_node2->prev = (*node1);
	(*node1)->next = next_node2;
	(*node1)->prev = (*node2);
	(*node2)->next = (*node1);
}
