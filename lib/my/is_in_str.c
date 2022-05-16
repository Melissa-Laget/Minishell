/*
** EPITECH PROJECT, 2022
** is_in_str
** File description:
** look if char is in string
*/

#include "my.h"

int is_in_str(char const *str, char c)
{
    if (str == NULL)
        return 0;
    for (int i = 0; i < my_strlen(str); i++) {
        if (c == str[i])
            return 1;
    }
    return 0;
}
