/*
** EPITECH PROJECT, 2022
** B-PSU-210-BDX-2-1-minishell2-melissa.laget
** File description:
** get_input
*/

#include "minishell1.h"

char *get_input(char *cmd)
{
    size_t buff = 0;

    free(cmd);
    if ((getline(&cmd, &buff, stdin)) < 0)
        return NULL;
    return cmd;
}
