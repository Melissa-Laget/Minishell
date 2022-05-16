/*
** EPITECH PROJECT, 2022
** B-PSU-210-BDX-2-1-minishell2-melissa.laget [WSL: Manjaro]
** File description:
** push_swap
*/

#include "minishell1.h"

list_t *create_list(char *path_var, char *name)
{
    list_t *list = malloc(sizeof(list_t));

    list->path = path_var;
    list->name = name;
    list->next = NULL;
    return list;
}

list_t *add_node(list_t *list, char *path_var, char *name)
{
    list_t *head = list;
    list_t *node = NULL;

    if (list == NULL)
        return create_list(path_var, name);
    node = malloc(sizeof(list_t));
    while (list->next != NULL)
        list = list->next;
    list->next = node;
    node->name = name;
    node->path = path_var;
    node->next = NULL;
    return (head);
}

list_t *get_list(int nb_elem)
{
    list_t *list = NULL;
    char *path_var = NULL;
    char *name = NULL;

    for (int i = 0; i < nb_elem; i++) {
        list = add_node(list, path_var, name);
    }
    return list;
}

list_t *delete_node(list_t *list, int count)
{
    list_t *head = list;
    list_t *tmp = NULL;

    if (list == NULL)
        return NULL;
    if (list->next == list) {
        free(list);
        return NULL;
    }
    for (int i = 0; i < count - 1; i++)
        head = head->next;
    tmp = head->next;
    head->next = head->next->next;
    free(tmp);
    return list;
}
