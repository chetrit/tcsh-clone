/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** commands header
*/

#ifndef COMMANDS_H_
#define COMMANDS_H_

typedef struct commands_s
{
    char *command;
    void(*function)(shell_t *shell, char **av);
} commands_t;

void fg(shell_t *shell, char **av);
void cd(shell_t *shell, char **av);
void set_env(shell_t *shell, char **av);
void unset_env(shell_t *shell, char **av);
void print_env(shell_t *shell, char **av);
void exit_command(shell_t *shell, char **av);
void create_alias(shell_t *shell, char **av);
void repeat(shell_t *shell, char **av);
void where(shell_t *shell, char **av);
void which(shell_t *shell, char **av);
void jobs(shell_t *shell, char **av);
void echo(shell_t *shell, char **av);

static const commands_t commands[] = {
    {"jobs", &jobs},
    {"fg", &fg},
    {"exit", &exit_command},
    {"env", &print_env},
    {"setenv", &set_env},
    {"unsetenv", &unset_env},
    {"cd", &cd},
    {"alias", &create_alias},
    {"repeat", &repeat},
    {"where", &where},
    {"which", &which},
    {"echo", &echo},
};

static const int NB_COMMANDS = sizeof(commands) / sizeof(commands_t);

#endif /* !COMMANDS_H_ */
