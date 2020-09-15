/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** parse input header
*/

#ifndef PARSE_INPUT_H_
#define PARSE_INPUT_H_

#include <string.h>
#include <stdlib.h>

char *parse_str(char *separators, char *str);
char **unparse_dstr(char **str, char *separators, char **env);
int simple_quote_founder(char *str, int i, int a);
char *keep_backquotes(char *str);

#endif /* !PARSE_INPUT_H_ */
