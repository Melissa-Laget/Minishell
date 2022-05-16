/*
** EPITECH PROJECT, 2022
** lib [WSL: Manjaro]
** File description:
** my_strdup
*/

#include <unistd.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *dest = malloc(sizeof(char) * (len + 1));
    int j = 0;

    if (src == NULL || len == 0)
        return NULL;
    for (int j = 0; j < len; j++)
        dest[j] = src[j];
    dest[len] = '\0';
    return dest;
}
