/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** var interpreter parser header
*/

#ifndef VAR_INTERPRETER_H_
#define VAR_INTERPRETER_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *get_env(char **envp, char *str);
int nb_sc(char *str, char c);

#endif /* !VAR_INTERPRETER_H_ */
