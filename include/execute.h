/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** execute header
*/

#ifndef EXECUTE_H_
#define EXECUTE_H_

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>

#include "minishell.h"
#include "env_utils.h"
#include "my_utils.h"
#include "signals_array.h"

static const char *EREXEC_STR = "Exec format error. Wrong Architecture.\n";

#define EREXEC(path) my_strcat(my_strcat(path, ": "), EREXEC_STR)

char *get_last_slash(char *path);
void print_error_path(char *name);

#endif /* EXECUTE_H_ */
