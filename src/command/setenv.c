/*
** EPITECH PROJECT, 2022
** B-PSU-210-BDX-2-1-minishell2-melissa.laget [WSL: Manjaro]
** File description:
** setenv
*/

#include "minishell1.h"

int my_setenv(minishell_t *shell, char **cmd)
{
    char **new_env = NULL;
    char *tmp  = NULL;
    int i = 0;

    if (cmd[1] == NULL || cmd[2] == NULL)
        return -1;
    for (; shell->env[i] != NULL; i++);
    new_env = malloc(sizeof(char *) * (i + 2));
    for (int count = 0; count <= i + 1; count++)
        new_env[count] = NULL;
    my_unsetenv(shell->env, cmd[1]);
    for (int count = 0; shell->env[count] != NULL; count++)
        new_env[count] = shell->env[count];
    free(shell->env);
    for (i = 0; new_env[i] != NULL; i++);
    tmp = concat_str(cmd[1], "=");
    new_env[i] = concat_str(tmp, cmd[2]);
    shell->env = new_env;
    return 0;
}
