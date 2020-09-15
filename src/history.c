/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** history
*/

#include "history.h"
#include "structures.h"
#include "minishell.h"
#include "my_utils.h"

static bool str_is_num(char *s)
{
    for (int i = 0; s[i]; i++)
        if (s[i] < '0' || s[i] > '9')
            return false;
    return true;
}

static char *generate_str_with_space(char *old)
{
    size_t len = strlen(old);
    char *new = malloc(sizeof(char) * (strlen(old) + 2));

    for (size_t i = 0; i != len; i++)
        new[i] = old[i];
    new[len] = ' ';
    new[len + 1] = '\0';
    return new;
}

char *history_retrieve_from_cmd(char *to_find, list_t *history)
{
    int count = 0;
    char *cmd = NULL;
    bool is_num = str_is_num(to_find);

    if (!strcmp(to_find, "!") && history)
        return history->data;
    for (list_t *curr = history; curr; curr = curr->next) {
        if (!strncmp(to_find, curr->data, strlen(to_find))
            || (is_num && count == atoi(to_find))) {
            cmd = curr->data;
            break;
        }
        count += 1;
    }
    if (!cmd) {
        dprintf(2, "%s: Event not found.\n", to_find);
    }
    return cmd;
}

void history_add(shell_t *sh, char **cmd)
{
    char *end = NULL;
    int size = 0;


    for (list_t *curr = sh->history; curr; curr = curr->next)
        size += 1;
    if (size == MAX_CMD)
        return;
    if (!cmd)
        return;
    for (int i = 0; cmd[i]; i++)
        size += strlen(cmd[i]) + 1;
    end = malloc(sizeof(char) * (size + 1));
    memset(end, 0, size + 1);
    size = 0;
    for (int i = 0; cmd[i]; i++)
        end = strcat(end, generate_str_with_space(cmd[i]));
    sh->utils.input = end;
    sh->utils.return_value = loop_shell(sh);
}

bool check_for_history(shell_t *sh, char **av)
{
    bool found = false;

    for (int i = 0; av[i]; i++) {
        if (av[i][0] == '!' && av[i][1]) {
            av[i] = history_retrieve_from_cmd(&av[i][1], sh->history);
            found = true;
            if (!av[i])
                sh->utils.input = " ";
        }
    }
    if (found)
        history_add(sh, av);
    else {
        if (my_strcmp(sh->utils.input, "!"))
            list_insert(&sh->history, sh->utils.input);
    }
    return found;
}
