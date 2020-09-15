/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** back quotes header
*/

#ifndef BACK_QUOTES_H_
#define BACK_QUOTES_H_

#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "structures.h"

void loop_shell(shell_t *shell);
void init_shell(shell_t *shell, char **env);

#endif /* !BACK_QUOTES_H_ */
