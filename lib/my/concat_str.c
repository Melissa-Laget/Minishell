/*
** EPITECH PROJECT, 2022
** lib [WSL: Manjaro]
** File description:
** concat_str
*/

#include "my.h"

char *concat_str(char *str1, char *str2)
{
    char *new_str = NULL;
    int len = my_strlen(str1);
    int len2 = my_strlen(str2);
    int count = 0;

    if (str1 == NULL || str2 == NULL || len == 0 || len2 == 0)
        return NULL;
    new_str = malloc(sizeof(char) * (len + len2 + 1));
    if (new_str == NULL)
        return NULL;
    for (count = 0; count < len; count++)
        new_str[count] = str1[count];
    for (int i = 0; i < len2; count++) {
        new_str[count] = str2[i];
        i++;
    }
    new_str[count] = '\0';
    return new_str;
}
