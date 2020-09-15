/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** where command header
*/

#ifndef WHERE_H_
#define WHERE_H_

#include <stdio.h>
#include <unistd.h>

#include "structures.h"
#include "global.h"
#include "commands/commands.h"
#include "my_utils.h"

void alias_print_2d_array(char **arr);
char *get_env(char **envp, char *str);

#endif /* !WHERE_H_ */
