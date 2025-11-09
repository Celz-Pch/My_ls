/*
** EPITECH PROJECT, 2025
** u_flags
** File description:
** u_flags
*/

#include <stdarg.h>
#include "../../../include/my.h"

int u_flags(unsigned int n)
{
    if ((unsigned int)n >= 10) {
        u_flags((unsigned int)n / 10);
    }
    my_putchar(((unsigned int)n % 10) + '0');
    return 0;
}

int my_printf_u(va_list args, const char *p)
{
    unsigned int u = va_arg(args, unsigned int);

    if (*p != 'u')
        return 0;
    u_flags(u);
    return 1;
}
