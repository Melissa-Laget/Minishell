/*
** EPITECH PROJECT, 2022
** printf [WSL: Manjaro]
** File description:
** my_printf
*/

#include "printerr.h"

static const void (*print_func[])(va_list va) = {
    &print_percents_err,
    &print_str_err,
    &print_char_err,
    &print_nb_err
};

static const char *formatter = "%scd";
static const int nb_formatter = 4;

void which_formatter_err(char *format, va_list va)
{
    if (format == NULL)
        return;
    for (int i = 0; i < nb_formatter; i++) {
        if (format[1] == formatter[i]) {
            print_func[i](va);
            return;
        }
    }
    write(2, &format[0], 2);
}

int my_printerr(const char *format, ...)
{
    va_list va;
    va_start(va, format);

    if (format == NULL)
        return 0;
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            which_formatter_err((char *)&format[i], va);
            i += 1;
        } else
            write(2, &format[i], 1);
    }
}
