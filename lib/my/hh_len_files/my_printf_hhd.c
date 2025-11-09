/*
** EPITECH PROJECT, 2025
** my_printf_HHD
** File description:
** Length modifier hh
*/
#include <stdarg.h>
#include "../../../include/my.h"

int my_printf_hhd(va_list args, const char *p)
{
    signed char d = (signed char)va_arg(args, int);

    my_put_nbr(d);
    return 3;
}
