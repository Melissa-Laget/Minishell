/*
** EPITECH PROJECT, 2022
** B-PSU-210-BDX-2-1-minishell2-melissa.laget [WSL: Manjaro]
** File description:
** unsetenv
*/

#include "minishell1.h"

static int check_cmd_unset(char **env, int i)
{
    for (; env[i] != NULL; i++)
        env[i] = env[i + 1];
    return 0;
}

int my_unsetenv(char **env, char *cmd)
{
    int i = 0;

    if (cmd == NULL)
        return -1;
    for (; env[i] != NULL; i++) {
        if (my_strncmp(env[i], cmd, my_strlen(cmd)) == 1) {
            check_cmd_unset(env, i);
        }
    }
    cmd = NULL;
    return 0;
}
