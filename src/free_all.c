/*
** EPITECH PROJECT, 2022
** B-PSU-210-BDX-2-1-minishell2-melissa.laget
** File description:
** free_all
*/

#include "minishell1.h"

void free_all(minishell_t *shell)
{
    for (list_t *tmp = shell->name_path; tmp != NULL; tmp = tmp->next) {
        free(tmp->name);
        free(tmp->path);
    }
    free(shell->path);
    free(shell->paths);
    free(shell->cwd);
    free(shell->last_cwd);
    free_char_arr(shell->env);
    free(shell);
}
