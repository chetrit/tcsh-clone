/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** header for node func
*/

#ifndef NODE_H_
#define NODE_H_

#include "signals.h"
#include "structures.h"
#include <stdlib.h>

typedef void (*fptr_t)();

void list_insert(list_t **head, void *data);
void list_filter(list_t **head, bool (*filter)(), fptr_t free_func);
void list_free(list_t **head, fptr_t function);

#endif /* !NODE_H_ */
