/*
** EPITECH PROJECT, 2022
** printf [WSL: Manjaro]
** File description:
** printf
*/

#ifndef PRINTF_H
    #define PRINTF_H

    #include <stdarg.h>
    #include <unistd.h>

int my_printerr(const char *format, ...);
void which_formatter_err(char *format, va_list va);
void my_putchar_err(char c);
int my_put_nbr_err(int nb);
void my_putstr_err(char const *str);
void print_str_err(va_list va);
void print_char_err(va_list va);
void print_nb_err(va_list va);
void print_percents_err(va_list va);

#endif
