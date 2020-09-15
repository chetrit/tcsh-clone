/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** minishell header
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#include "structures.h"
#include "commands/commands.h"
#include "special_char.h"
#include "env_utils.h"

//MAIN FUNCTIONS
void exec_prog(char **f_av, shell_t *shell);
void cd(shell_t *shell, char **av);
void print_error(char *name, int err, bool more, bool even_more);
void init_shell(shell_t *shell, char **env);

//FORMATTING FUNCTIONS
void format_arr(shell_t *shell);
int only_space_and_tabs(char *str);
int is_multiple_slashes(char *str);
shell_redirect_t get_fd_to_write(shell_t *shell, char **arr);
void close_redirection(shell_t *shell);
int check_for_pipes(shell_t *shell, char **av);
char **replace_alias(shell_t *shell, char **av);
void get_input(shell_t *shell);
void handle_signal_shell(bool is_shell);
int check_for_and_or(shell_t *shell, char **av);
bool is_empty_arr(char **arr);
char *clear_arr(char *str);
char **globbing(char **av);
int loop_shell(shell_t *shell);

//PARSING FUNCTIONS
char *parse_var_interpreter(char **env, char *str);
char **parse_input(char *str, char *separators, char **env);
int parse_invalid_redirects(shell_t *shell, char *str);
int parse_null_command(shell_t *shell, char *str);
char *parse_pipes(char *str);
char *parse_inhibitors(char *str);

#endif /*MINISHELL_H_*/
