/*
** EPITECH PROJECT, 2025
** my_printf_LO
** File description:
** L LENGTH MODIFIER
*/
#include <stdarg.h>
#include "../../../include/my.h"

int lo_flags(unsigned long n)
{
    if (n >= 8)
        lo_flags(n / 8);
    my_putchar((n % 8) + '0');
    return 0;
}

int my_printf_lo(va_list args, const char *p)
{
    unsigned long o = va_arg(args, unsigned long);

    p--;
    if (*p == '#' && o != 0)
        my_putstr("0");
    if (o == 0)
        my_putchar('0');
    else
        lo_flags(o);
    return 2;
}
