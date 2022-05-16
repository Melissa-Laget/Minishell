/*
** EPITECH PROJECT, 2022
** B-PSU-210-BDX-2-1-minishell2-melissa.laget [WSL: Manjaro]
** File description:
** env
*/

#include "minishell1.h"

int str_start_with(char const *long_str, char const *start_str)
{
    int len_long = my_strlen(long_str);
    int len_start = my_strlen(start_str);

    if (long_str == NULL || start_str == NULL)
        return 84;
    if (len_long == 0 || len_start == 0)
        return 0;
    for (int i = 0; start_str[i] != '\0'; i++) {
        if (long_str[i] != start_str[i])
            return 0;
    }
    return 1;
}

char *search_forvar(char **duplicated_env, char *str)
{
    char *tmp_str = concat_str(str, "=");

    for (int i = 0; duplicated_env[i] != NULL; i++) {
        if (str_start_with(duplicated_env[i], tmp_str) == 1)
            return duplicated_env[i];
    }
    return NULL;
}

char **my_env(char **env)
{
    char **duplicated_env = NULL;
    int count = 0;

    for (int i = 0; env[i] != NULL; i++)
        count++;
    duplicated_env = malloc(sizeof(char *) * (count + 1));
    for (int i = 0; i < count; i++) {
        duplicated_env[i] = my_strdup(env[i]);
    }
    duplicated_env[count] = NULL;
    return duplicated_env;
}

int command(char **cmd_array, minishell_t *shell)
{
    if (((my_strncmp(cmd_array[0], "env", 3) == 1) &&
        (my_strlen(cmd_array[0])) == 3))
        return printf_env(cmd_array, shell);
    if ((my_strncmp(cmd_array[0], "setenv", 6) == 1) &&
        (my_strlen(cmd_array[0]) == 6))
        return my_setenv(shell, cmd_array);
    if ((my_strncmp(cmd_array[0], "unsetenv", 8) == 1) &&
        (my_strlen(cmd_array[0]) == 8))
        return my_unsetenv(shell->env, cmd_array[1]);
    if ((my_strncmp(cmd_array[0], "cd", 2) == 1) && (my_strlen(cmd_array[0])
        == 2))
        return cd_command(cmd_array, shell);
    return -1;
}
