/*
** EPITECH PROJECT, 2022
** B-PSU-210-BDX-2-1-minishell2-melissa.laget
** File description:
** get_cmd
*/

#include "minishell1.h"
#include "printerr.h"
int my_printerr(const char *format, ...);

char **get_cmd(char *cmd)
{
    char **cmd_array = NULL;

    cmd_array = str_to_array(cmd, "\t ");
    return cmd_array;
}

char *find_cmd(char **cmd, minishell_t *shell)
{
    char *path = cmd[0];

    for (list_t *tmp = shell->name_path; tmp != NULL; tmp = tmp->next) {
        if (my_strcmp(tmp->name, path) == 1)
            return tmp->path;
    }
    return path;
}

static void check_for_waitpid_error(int i)
{
    if (WIFSIGNALED(i) == true)
        if (WCOREDUMP(i) == true)
            perror("waitpid: ");
    return;
}

void exec_cmd(char *cmd, minishell_t *shell, char **cmd_array)
{
    pid_t pid = fork();
    int i = 0;

    if (pid == 0) {
        if (execve(find_cmd(&cmd, shell), cmd_array, shell->env) == -1) {
            execve_error(cmd);
            execve_error2(cmd);
        }
        exit(0);
    } else {
        waitpid(pid, &i, 0);
        check_for_waitpid_error(i);
        kill(pid, SIGTERM);
    }
}
