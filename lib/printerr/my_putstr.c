/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** display a string
*/

#include "printerr.h"

void my_putstr_err(char const *str)
{
    int i = 0;

    if (str == NULL)
        return;
    while (str[i] != '\0') {
        i = i + 1;
    }
    write(2, str, i);
    return;
}
