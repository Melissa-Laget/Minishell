/*
** EPITECH PROJECT, 2022
** printf [WSL: Manjaro]
** File description:
** type
*/

#include "printerr.h"

void print_str_err(va_list va)
{
    my_putstr_err(va_arg(va, char *));
    return;
}

void print_char_err(va_list va)
{
    my_putchar_err(va_arg(va, int));
    return;
}

void print_nb_err(va_list va)
{
    my_put_nbr_err(va_arg(va, int));
    return;
}

void print_percents_err(va_list va)
{
    my_putchar_err('%');
    return;
}
