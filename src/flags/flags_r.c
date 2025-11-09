/*
** EPITECH PROJECT, 2025
** raar
** File description:
** raar
*/

#include "../../include/my.h"

void my_ls_recursive(char *path, flags_bool_t *all_flags)
{
    if (path == NULL)
        return;
    my_printf("%s:\n", path);
    my_ls(path, all_flags);
}
