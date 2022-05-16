/*
** EPITECH PROJECT, 2022
** B-PSU-210-BDX-2-1-minishell2-melissa.laget [WSL: Manjaro]
** File description:
** get_file
*/

#include "minishell1.h"

list_t *getlist(list_t *list, char *name, char *path)
{
    char *tmp_start = NULL;
    char *tmp_end = NULL;

    if (my_strcmp(name, ".") == 1 || my_strcmp(name, "..") == 1)
        return list;
    if (path[my_strlen(path) - 1] != '/')
        tmp_start = concat_str(path, "/");
    else
        tmp_start = my_strdup(path);
    tmp_end = concat_str(tmp_start, name);
    list = add_node(list, tmp_end, my_strdup(name));
    free(tmp_start);
    return list;
}

minishell_t *get_file_in_dir(minishell_t *shell)
{
    DIR *dirs = NULL;
    struct dirent *dir;

    shell->name_path = NULL;
    for (int i = 0; shell->paths[i] != NULL; i++) {
        dirs = opendir(shell->paths[i]);
        if (dirs == NULL)
            continue;
        while ((dir = readdir(dirs)) != NULL) {
            shell->name_path = getlist(shell->name_path,
            dir->d_name, shell->paths[i]);
        }
        closedir(dirs);
    }
    return shell;
}
