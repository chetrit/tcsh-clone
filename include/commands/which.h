/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** which command header
*/

#ifndef WHICH_H_
#define WHICH_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "structures.h"
#include "commands.h"
#include "my_utils.h"
#include "global.h"

char *get_env(char **envp, char *str);
void alias_print_2d_array(char **arr);

#endif /* !WHICH_H_ */
