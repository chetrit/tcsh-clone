/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** clear arr header
*/

#ifndef CLEAR_ARR_H_
#define CLEAR_ARR_H_

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *loop_clear(char *getline1, int a, char *str, int b);
char *unparse_pv(char *str);
bool is_err(char *str);
bool is_pv(char *str);

#endif /* !CLEAR_ARR_H_ */
