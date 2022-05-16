/*
** EPITECH PROJECT, 2022
** sokoban [WSL: Manjaro]
** File description:
** my
*/

#ifndef MY_H
    #define MY_H

    #include <stddef.h>
    #include <stdlib.h>

int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_put_nbr(int nb);
int my_strcmp(char const *s1, char const *s2);
void my_putstr(char const *str);
void my_putchar(char c);
char *my_strdup(char const *src);
void free_char_arr(char **arr);
void char_arr_len(char **arr);
char *concat_str(char *str1, char *str2);
void add_to_char_arr(char **arr);
void my_nbrlen(int nb);
int count_separators(const char *str, char *sep);
char **str_to_array(char *str, char *sep);
int is_in_str(char const *str, char c);
int my_strncmp(char const *s1, char const *s2, int bits);

#endif
