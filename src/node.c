/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** node functions
*/

#include "node.h"

void list_insert(list_t **head, void *data)
{
    list_t *new = malloc(sizeof(list_t));

    if (new != NULL) {
        new->data = data;
        new->next = *head;
        *head = new;
    }
}

static void list_cut(list_t **head, list_t *previous,
    list_t *curr, fptr_t free_func)
{
    list_t *to_free = curr;

    if (!previous)
        *head = curr->next;
    else
        previous->next = curr->next;
    if (free_func)
        free_func(to_free->data);
    free(to_free);
}

void list_filter(list_t **head, bool (*filter)(), fptr_t free_func)
{
    list_t *previous = NULL;
    list_t *to_free = NULL;

    for (list_t *curr = *head; curr;) {
        if (!filter(curr->data)) {
            to_free = curr;
            curr = curr->next;
            list_cut(head, previous, to_free, free_func);
        } else {
            previous = curr;
            curr = curr->next;
        }
    }
}

void list_free(list_t **head, fptr_t function)
{
    list_t *current = *head;
    list_t *temp;

    while (current) {
        if (function)
            function(temp->data);
        temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}
