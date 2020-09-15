/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** cd header
*/

#ifndef CD_H_
#define CD_H_

#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>

#include "structures.h"
#include "my_utils.h"

char *get_env(char **envp, char *str);
void set_env(shell_t *shell, char **av);
void print_error(char *name, int err, bool more, bool even_more);

#endif /* CD_H_ */
