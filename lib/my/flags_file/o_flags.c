/*
** EPITECH PROJECT, 2025
** o_flgas
** File description:
** o_flags
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "../../../include/my.h"

int o_flags(unsigned int nb)
{
    if (nb <= 0)
        return 0;
    o_flags(nb / 8);
    my_put_nbr(nb % 8);
    return 0;
}

int my_printf_o(va_list args, const char *p)
{
    unsigned int o = va_arg(args, unsigned int);

    p--;
    if (*p == '#')
        my_putstr("0");
    o_flags(o);
    return 1;
}
