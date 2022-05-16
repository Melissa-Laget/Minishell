/*
** EPITECH PROJECT, 2022
** B-PSU-210-BDX-2-1-minishell2-melissa.laget [WSL: Manjaro]
** File description:
** str_utils
*/

#include "my.h"

int count_separators(const char *str, char *sep)
{
    int count = 1;

    if (str == NULL || sep == NULL)
        return 84;
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_in_str(sep, str[i]) == 0)
            continue;
        for (; is_in_str(sep, str[i]) == 1; i++);
        if (str[i] != '\0')
            count ++;
    }
    return count;
}
