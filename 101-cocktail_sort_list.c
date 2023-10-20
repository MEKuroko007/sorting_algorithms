#include "sort.h"

/**
 * swap_node_ahead - Swap a node with the next node in a listint_t doubly-linked list.
 * @list: A pointer to the head of a doubly-linked list.
 * @shaker: A pointer to the current swapping node.
 */
void swap_node_ahead(listint_t **list, listint_t **shaker) {
    listint_t *tmp = (*shaker)->next;

    if (tmp->next != NULL)
        tmp->next->prev = *shaker;
    tmp->prev = (*shaker)->prev;
    if ((*shaker)->prev != NULL)
        (*shaker)->prev->next = tmp;
    else
        *list = tmp;
    (*shaker)->next = tmp->next;
    (*shaker)->prev = tmp;
    tmp->next = *shaker;
    *shaker = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 * ascending order using the cocktail shaker sort algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list) {
    int swapped = 1;
    listint_t *shaker;
    listint_t *tail = NULL;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (swapped) {
        swapped = 0;
        for (shaker = *list; shaker != tail; shaker = shaker->next) {
            if (shaker->n > shaker->next->n) {
                swap_node_ahead(list, &shaker);
                print_list(*list);
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        for (; shaker != tail; shaker = shaker->prev) {
            if (shaker->n < shaker->prev->n) {
                swap_node_ahead(list, &shaker);
                print_list(*list);
                swapped = 1;
            }
        }
        tail = shaker;
    }
}
