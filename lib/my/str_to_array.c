/*
** EPITECH PROJECT, 2022
** B-PSU-210-BDX-2-1-minishell2-melissa.laget [WSL: Manjaro]
** File description:
** str_to_array
*/

#include "my.h"

static char *check_array(int count, char *sep, char *str)
{
    char *array = NULL;

    if ((array = malloc(sizeof(char) * (count + 1))) == NULL)
        return NULL;
    for (int i = 0; i < count; i++)
        array[i] = '\0';
    array[count] = '\0';
    return array;
}

static int get_count(char *str, int count, char *sep)
{
    for (count = 0; str[count] != '\0' &&
        is_in_str(sep, str[count]) == 0; count++);
    return count;

}

char **str_to_array(char *str, char *sep)
{
    int nb_words = 0;
    char **array = NULL;
    int count = 0;

    if (str == NULL || sep == NULL)
        return NULL;
    for (; is_in_str(sep, str[0]) == 1; str++);
    nb_words = count_separators(str, sep);
    if ((array = malloc(sizeof(char *) * (nb_words + 1))) == NULL)
        return NULL;
    array[nb_words] = NULL;
    for (int i = 0; i < nb_words; i++) {
        count = get_count(str, count, sep);
        if ((array[i] = check_array(count, sep, str)) == NULL)
            return NULL;
        for (int j = 0; j < count; j++)
            array[i][j] = str[j];
        for (str = &str[count]; is_in_str(sep, str[0]) == 1; str++);
    }
    return array;
}
