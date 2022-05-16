/*
** EPITECH PROJECT, 2022
** B-PSU-210-BDX-2-1-minishell2-melissa.laget
** File description:
** cd_command
*/

#include "minishell1.h"
int my_printerr(const char *format, ...);

int get_cd_null(minishell_t *shell, char *cwd, char **cmd_array)
{
    if (cmd_array[1] == NULL) {
        chdir(cwd);
        shell->last_cwd = shell->cwd;
        shell->cwd = getcwd(NULL, 0);
        return 1;
    }
    return 0;
}

int get_cd_tilde(minishell_t *shell, char *cwd, char **cmd_array, char *cmd)
{
    char *cd = NULL;

    if (my_strncmp(cmd_array[1], "~", 1) == 1) {
        cd = concat_str(cwd, &cmd[1]);
        if (cd == NULL) {
            if ((chdir(cwd)) == -1)
                perror("ERROR: ");
            return 1;
        }
        if ((chdir(cd)) == -1)
            perror("ERROR: ");
        shell->last_cwd = shell->cwd;
        shell->cwd = getcwd(NULL, 0);
        free(cd);
        return 1;
    }
    return 0;
}

int get_cd(minishell_t *shell, char **cmd_array)
{
    if (cmd_array[2] != NULL) {
        my_printerr("%s: Too many arguments.\n", cmd_array[0]);
    } else if ((chdir(cmd_array[1])) == -1)
        perror("ERROR: ");
    free(shell->last_cwd);
    shell->last_cwd = shell->cwd;
    shell->cwd = getcwd(NULL, 0);
    return 0;
}

int get_cd_hyphen(minishell_t *shell, char **cmd_array)
{
    if (my_strcmp(cmd_array[1], "-") == 1) {
        chdir(shell->last_cwd);
        free(shell->last_cwd);
        shell->last_cwd = shell->cwd;
        shell->cwd = getcwd(NULL, 0);
        return 1;
    }
    return 0;
}
