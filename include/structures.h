/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** structures header
*/

#ifndef STRUCTURES_H_
#define STRUCTURES_H_

#include <stdbool.h>
#include <sys/types.h>

typedef struct list_s
{
    void *data;
    struct list_s *next;
} list_t;

typedef struct shell_alias_s
{
    char *command;
    char **alias;
    struct shell_alias_s *next;
} shell_alias_t;

typedef struct shell_redirection_s
{
    int fd_out;
    int fd_save_out;
    bool twice;
    bool left;
} shell_redirect_t;

typedef struct shell_commands_s
{
    char **arr;
    char ***avs;
    char ***pipe_avs;
    char ***and_or_avs;
} shell_commands_t;

typedef struct shell_pipes_s
{
    int first[2];
    int second[2];
} shell_pipes_t;

typedef struct shell_utils_s
{
    char *prompt;
    int return_value;
    bool exit;
    char *input;
} shell_utils_t;

typedef struct shell_s
{
    char **env;
    shell_utils_t utils;
    shell_commands_t cmds;
    shell_redirect_t redirect;
    shell_pipes_t pipes;
    shell_alias_t *alias;
    list_t *history;
} shell_t;

#endif /* STRUCTURES_H_ */
