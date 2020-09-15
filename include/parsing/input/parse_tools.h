/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** parse tools header
*/

#ifndef PARSE_TOOLS_H_
#define PARSE_TOOLS_H_

#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

#include "structures.h"
#include "global.h"

char *cpy_dquote(char *str2, char *str);
int is_two_quote(char *str, int i);
char *keep_backquotes(char *str);

char *exec_command_back_quote(char *str, char **env);
void exec_command_parenthesis(char *command, char **env);
char *double_quote(char *separators, char **arr, int i);

#endif /* !PARSE_TOOLS_H_ */
