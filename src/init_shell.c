/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** shell init
*/

#include "minishell.h"
#include "history.h"
#include "env_utils.h"

void init_shell(shell_t *shell, char **env)
{
    shell->utils.input = NULL;
    shell->utils.return_value = 0;
    shell->redirect = (shell_redirect_t) {0, 0, 0, 0};
    shell->pipes = (shell_pipes_t) {{-1, -1}, {-1, -1}};
    shell->alias = NULL;
    shell->utils.exit = false;
    shell->history = history_retrieve_from_file();
    cp_env(shell, env);
    get_prompt(shell);
}