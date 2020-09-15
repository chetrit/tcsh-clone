/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** prompt
*/

#include "prompt.h"

char *get_last_slash(char *path)
{
    char *ptr = path;

    if (my_strcmp(path, "/") == 0)
        return (path);
    for (int i = 0; path[i] != '\0'; i++)
        if (path[i] == '/')
            ptr = &path[i + 1];
    return (ptr);
}

void get_prompt(shell_t *shell)
{
    char *user = get_env(shell->env, "USER");
    char *hostname = get_env(shell->env, "HOSTNAME");
    char *pwd = get_last_slash(getcwd(NULL, 0));
    int i = 0;

    if (!user || !hostname || !pwd) {
        shell->utils.prompt = "$>";
        return;
    }
    for (; hostname[i] != '\0' && hostname[i] != '.'; i++);
    hostname[i] = '\0';
    asprintf(&shell->utils.prompt,
        "\033[31m[%s@%s %s]\e[0m$ ", user, hostname, pwd);
}
