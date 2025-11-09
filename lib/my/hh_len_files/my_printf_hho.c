/*
** EPITECH PROJECT, 2025
** my_printf_HHO
** File description:
** HH LENGTH MODIFIER
*/
#include <stdarg.h>
#include <unistd.h>
#include "../../../include/my.h"
#include <stdio.h>

int hho_flags(signed char nb)
{
    if (nb <= 0) {
        return 0;
    }
    hho_flags(nb / 8);
    my_put_nbr(nb % 8);
    return 0;
}

int my_printf_hho(va_list args, const char *p)
{
    signed char o = (signed char)va_arg(args, unsigned int);

    if (*p == o != 0) {
        my_putstr("0");
    } else {
        hho_flags(o);
    }
    return 3;
}
