/*
** EPITECH PROJECT, 2025
** x_flags
** File description:
** x_flags
*/

#include "../../../include/my.h"
#include <stdio.h>
#include <stdarg.h>

int majx_flags(unsigned int n)
{
    int n2 = n % 16;

    if ((unsigned int)n >= 10)
        majx_flags((unsigned int)n / 16);
    if (n2 > 9)
        my_putchar(((unsigned int)n % 16) + 55);
    if (n2 < 9 && n2 != 0)
        my_put_nbr(n2);
    return 1;
}

int my_printf_majx(va_list args, const char *p)
{
    unsigned int x = va_arg(args, unsigned int);

    p--;
    if (*p == '#' && x != 0)
        my_putstr("0X");
    return majx_flags(x);
}
