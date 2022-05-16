/*
** EPITECH PROJECT, 2022
** B-PSU-210-BDX-2-1-minishell2-melissa.laget [WSL: Manjaro]
** File description:
** cd
*/

#include "minishell1.h"
int my_printerr(const char *format, ...);

static char *get_current_cwd(minishell_t *shell)
{
    char *cwd = NULL;

    for (int i = 0; shell->env[i] != NULL; i++) {
        if (my_strncmp(shell->env[i], "HOME=", 5) == 1) {
            cwd = my_strdup(shell->env[i]);
            return cwd;
        }
    }
    return NULL;
}

static char *get_real_cwd(char *cwd)
{
    int count = 0;
    int i = 0;
    char *new_cwd = NULL;

    for (; cwd[i] != '='; i++)
        count++;
    new_cwd = malloc(sizeof(char) * (my_strlen(cwd) - (count + 1)));
    new_cwd = my_strdup(&cwd[count + 1]);
    return new_cwd;
}

int cd_command(char **cmd_array, minishell_t *shell)
{
    char *cwd = NULL;
    char *cmd = cmd_array[1];

    if (shell->env == NULL)
        return -1;
    cwd = get_current_cwd(shell);
    cwd = get_real_cwd(cwd);
    if (get_cd_null(shell, cwd, cmd_array) == 1)
        return 0;
    if (get_cd_hyphen(shell, cmd_array) == 1)
        return 0;
    if (get_cd_tilde(shell, cwd, cmd_array, cmd) == 1)
        return 0;
    get_cd(shell, cmd_array);
    return 0;
}
