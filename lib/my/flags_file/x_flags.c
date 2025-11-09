/*
** EPITECH PROJECT, 2025
** x_flags
** File description:
** x_flags
*/

#include "../../../include/my.h"
#include <stdio.h>
#include <stdarg.h>

int x_flags(unsigned int n)
{
    int n2 = n % 16;

    if ((unsigned int)n >= 10)
        x_flags((unsigned int)n / 16);
    if (n2 > 9)
        my_putchar(((unsigned int)n % 16) + 87);
    if (n2 < 9 && n2 != 0)
        my_put_nbr(n2);
    return 1;
}

int my_printf_x(va_list args, const char *p)
{
    unsigned int x = va_arg(args, unsigned int);

    p--;
    if (*p == '#' && x != 0)
        my_putstr("0x");
    return x_flags(x);
}
