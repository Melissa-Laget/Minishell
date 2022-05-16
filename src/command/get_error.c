/*
** EPITECH PROJECT, 2022
** B-PSU-210-BDX-2-1-minishell2-melissa.laget
** File description:
** get_error
*/

#include "minishell1.h"
int my_printerr(const char *format, ...);

void execve_error(char *cmd)
{
    if (errno == E2BIG)
        my_printerr("%s%s\n", cmd, ": Too many arguments.");
    if (errno == EACCES)
        my_printerr("%s%s\n", cmd, ": Permission denied.");
    if (errno == EFAULT)
        my_printerr("%s%s\n", cmd, ": Bad address.");
    if (errno == EINVAL)
        my_printerr("%s%s\n", cmd, ": Invalid values.");
    if (errno == EIO)
        my_printerr("%s%s\n", cmd, ": Input/output error.");
    if (errno == EISDIR)
        my_printerr("%s%s\n", cmd, ": Is a directory.");
    if (errno == ELIBBAD)
        my_printerr("%s%s\n", cmd, ": Accessing a corrupted shared library.");
    if (errno == ELOOP)
        my_printerr("%s%s\n", cmd, ": Too many levels of symbolic links.");
    if (errno == EMFILE)
        my_printerr("%s%s\n", cmd, ": Too many open files.");
    if (errno == ENAMETOOLONG)
        my_printerr("%s%s\n", cmd, ": Filename too long.");
}

void execve_error2(char *cmd)
{
    if (errno == ENOENT)
        my_printerr("%s%s\n", cmd, ": No such file or directory.");
    if (errno == ENOEXEC)
        my_printerr("%s%s\n", cmd, ": Exec format error.");
    if (errno == ENOMEM)
        my_printerr("%s%s\n", cmd,
        ": Not enough space/cannot allocate memory.");
    if (errno == ENOTDIR)
        my_printerr("%s%s\n", cmd, ": Not a directory.");
    if (errno == EPERM)
        my_printerr("%s%s\n", cmd, ": Operation not permitted.");
    if (errno == ETXTBSY)
        my_printerr("%s%s\n", cmd, ": Text file busy.");
}
