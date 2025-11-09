/*
** EPITECH PROJECT, 2025
** my_printf_ls.c
** File description:
** my_printf_ls.c
*/

#include "../../include/my.h"

void my_printf_ls(char *path, flags_bool_t *all_flags, int i)
{
    if (i == 0 && path[0] != '.') {
        my_printf("%s", path);
    } else if (i != 0 && path[0] != '.')
        my_printf("  %s", path);
}
