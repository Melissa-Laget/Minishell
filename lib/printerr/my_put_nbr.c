/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** display numbers
*/

#include <stdio.h>

void my_putchar_err(char c);

int my_put_nbr_err(int nb)
{
    int k = 0;
    if (nb < 0) {
        my_putchar_err('-');
        nb = nb * -1;
    }
    if (nb >= 10) {
        k = (nb % 10);
        nb = (nb - k) / 10;
        my_put_nbr_err(nb);
        my_putchar_err(48 + k);
    } else {
        my_putchar_err(48 + (nb % 10));
    }
    return (0);
}
