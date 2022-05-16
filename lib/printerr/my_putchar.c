/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** display
*/

#include <unistd.h>

void my_putchar_err(char c)
{
    write(2, &c, 1);
}
