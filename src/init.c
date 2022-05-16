/*
** EPITECH PROJECT, 2022
** B-PSU-210-BDX-2-1-minishell2-melissa.laget [WSL: Manjaro]
** File description:
** init
*/

#include "minishell1.h"

minishell_t *init_minishell(char **env)
{
    char *var = NULL;
    minishell_t *shell = NULL;

    shell = malloc(sizeof(minishell_t));
    write (1, "$>", 3);
    shell->env = my_env(env);
    var = search_forvar(shell->env, "PATH");
    if (var == NULL)
        var = my_strdup("/usr/bin");
    shell->paths = str_to_array(&var[5], ":\0");
    shell = get_file_in_dir(shell);
    shell->cwd = getcwd(NULL, 0);
    shell->last_cwd = NULL;
    return shell;
}
