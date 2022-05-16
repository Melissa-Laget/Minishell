/*
** EPITECH PROJECT, 2022
** B-PSU-210-BDX-2-1-minishell2-melissa.laget [WSL: Manjaro]
** File description:
** minishell
*/

#include "minishell1.h"

static int my_sh2(char *cmd, char **cmd_array, minishell_t *shell)
{
    cmd[my_strlen(cmd) - 1] = cmd[my_strlen(cmd)];
    cmd_array = get_cmd(cmd);
    free(cmd);
    if (my_strncmp(cmd_array[0], "exit", 5) == 1)
        exit(0);
    cmd = find_cmd(cmd_array, shell);
    if (command(cmd_array, shell) != -1)
        return 0;
    exec_cmd(cmd, shell, cmd_array);
    return 0;
}

int my_sh(int argc __attribute__((unused)),
char **argv __attribute__((unused)), char **env)
{
    char *cmd = NULL;
    char **cmd_array = NULL;
    minishell_t *shell = NULL;

    shell = init_minishell(env);
    while (1) {
        if ((cmd = (get_input(cmd))) == NULL) {
            write (1, "exit\n", 6);
            return 0;
        }
        my_sh2(cmd, cmd_array, shell);
        cmd = '\0';
        cmd_array = NULL;
        write (1, "$>", 3);
    }
    free(cmd);
    free_char_arr(cmd_array);
    free_all(shell);
    return 0;
}
