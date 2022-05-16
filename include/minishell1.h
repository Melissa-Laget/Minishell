/*
** EPITECH PROJECT, 2022
** B-PSU-210-BDX-2-1-minishell2-melissa.laget [WSL: Manjaro]
** File description:
** minishell1
*/

#ifndef MINISHELL1_H_
    #define MINISHELL1_H_

    #include <stdio.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <signal.h>
    #include <stdlib.h>
    #include <string.h>
    #include "my.h"
    #include <stdlib.h>
    #include <errno.h>
    #include <dirent.h>
    #include "printf.h"
    #include "printerr.h"
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <stddef.h>
    #include <stdbool.h>

typedef struct list_s {
    struct list_s *next;
    char *path;
    char *name;
} list_t;

typedef struct minishell_s {
    char *path;
    char **paths;
    list_t *name_path;
    char *cwd;
    char *last_cwd;
    char **env;
} minishell_t;

int main(int argc, char **argv, char **env);
int my_sh(int argc, char **argv, char **env);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_strlen(char const *str);
char *my_strdup(char const *src);
char **my_env(char **env);
char *search_forvar(char **duplicated_env, char *str);
int str_start_with(char const *long_str, char const *start_str);
minishell_t *get_file_in_dir(minishell_t *path);
minishell_t *init_minishell(char **env);
list_t *create_list(char *path_var, char *name);
list_t *add_node(list_t *list, char *path_var, char *name);
list_t *get_list(int nb_elem);
list_t *delete_node(list_t *list, int count);
char **get_cmd(char *cmd);
char *find_cmd(char **cmd, minishell_t *shell);
int my_setenv(minishell_t *shell, char **cmd);
int my_unsetenv (char **env, char *cmd);
int command(char **cmd_array, minishell_t *shell);
char *get_input(char *cmd);
void exec_cmd(char *cmd, minishell_t *shell, char **cmd_array);
int cd_command(char **cmd_array, minishell_t *shell);
int get_cd_null(minishell_t *shell, char *cwd, char **cmd_array);
int get_cd_tilde(minishell_t *shell, char *cwd, char **cmd_array, char *cmd);
int get_cd(minishell_t *shell, char **cmd_array);
int get_cd_hyphen(minishell_t *shell, char **cmd_array);
char *get_real_old_cwd(minishell_t *shell, char *cwd);
char *get_old_cwd(minishell_t *shell);
int printf_env(char **cmd_array, minishell_t *shell);
void execve_error(char *cmd);
void execve_error(char *cmd);
void execve_error2(char *cmd);
void free_all(minishell_t *shell);

#endif
