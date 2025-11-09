/*
** EPITECH PROJECT, 2025
** my_printf_HHU
** File description:
** HH LENGTH MODIFIER
*/
#include "../../../include/my.h"
#include <stdarg.h>

int hhu_flags(signed char n)
{
    if (n >= 10) {
        hhu_flags(n / 10);
    }
    my_putchar((n % 10) + '0');
    return 0;
}

int my_printf_hhu(va_list args, const char *p)
{
    signed char u = (signed char)va_arg(args, unsigned int);

    hhu_flags(u);
    return 3;
}
