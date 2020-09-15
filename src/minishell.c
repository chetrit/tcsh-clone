/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** minishell2 main function
*/

#include "minishell.h"
#include "history.h"

void check_commands_one(shell_t *shell, char **av)
{
    av = replace_alias(shell, av);
    for (int i = 0; i < NB_COMMANDS; ++i) {
        if (strcmp(commands[i].command, av[0]) == 0) {
            return (commands[i].function(shell, av));
        }
    }
    exec_prog(av, shell);
}

void check_commands(shell_t *shell, char **av)
{
    shell->redirect = get_fd_to_write(shell, av);
    check_commands_one(shell, av);
    close_redirection(shell);
}

void loop_arrays(shell_t *shell)
{
    for (int i = 0; shell->cmds.avs[i] != NULL; i++) {
        shell->cmds.avs[i] = globbing(shell->cmds.avs[i]);
        if (check_for_history(shell, shell->cmds.avs[i]) ||
            check_for_pipes(shell, shell->cmds.avs[i]) || check_for_and_or(
            shell, shell->cmds.avs[i]) || shell->redirect.fd_out == -1) {
            continue;
        }
        check_commands(shell, shell->cmds.avs[i]);
    }
    if (shell->utils.exit) {
        history_save(shell->history);
        exit(shell->utils.return_value);
    }
}

int loop_shell(shell_t *shell)
{
    shell->utils.return_value = 0;
    if (only_space_and_tabs(shell->utils.input)
        || parse_null_command(shell, shell->utils.input)
        || parse_invalid_redirects(shell, shell->utils.input))
        return (1);
    shell->utils.input = clear_arr(shell->utils.input);
    shell->utils.input = parse_pipes(shell->utils.input);
    shell->utils.input = parse_inhibitors(shell->utils.input);
    shell->utils.input = parse_var_interpreter(shell->env, shell->utils.input);
    if (!shell->utils.input)
        return (1);
    shell->cmds.arr = parse_input(shell->utils.input, " \t", shell->env);
    if (is_empty_arr(shell->cmds.arr) == 1)
        return (1);
    format_arr(shell);
    create_arrays(shell);
    loop_arrays(shell);
    get_prompt(shell);
    return (0);
}

int minishell(shell_t *shell, char **env, bool display)
{
    init_shell(shell, env);
    while (1) {
        handle_signal_shell(true);
        if (display) {
            printf(shell->utils.prompt);
        }
        get_input(shell);
        if (!shell->utils.input) {
            history_save(shell->history);
            return (shell->utils.return_value);
        }
        if (loop_shell(shell)) {
            continue;
        }
    }
    return (shell->utils.return_value);
}
