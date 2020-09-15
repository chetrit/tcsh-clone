/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** history header
*/

#ifndef HISTORY_H_
#define HISTORY_H_

#include "global.h"

static const int MAX_CMD = 1000;
UNUSED static const char *HISTORY_FILEPATH = ".42sh_history";

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "node.h"

list_t *history_retrieve_from_file(void);
void history_save(list_t *history);
bool check_for_history(shell_t *sh, char **av);

#endif /* !HISTORY_H_ */
