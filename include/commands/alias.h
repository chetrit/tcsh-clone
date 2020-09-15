/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** alias header
*/

#ifndef ALIAS_H_
#define ALIAS_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "structures.h"
#include "global.h"

void print_one_alias(shell_t *shell, char *alias);
void print_all_alias(shell_t *shell, int fd);

#endif /* !ALIAS_H_ */
