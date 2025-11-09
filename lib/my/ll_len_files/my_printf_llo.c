/*
** EPITECH PROJECT, 2025
** my_printf_LO
** File description:
** L LENGTH MODIFIER
*/

#include <stdarg.h>
#include "../../../include/my.h"

int llo_flags(unsigned long long n)
{
    if (n >= 8)
        llo_flags(n / 8);
    my_putchar((n % 8) + '0');
    return 0;
}

int my_printf_llo(va_list args, const char *p)
{
    unsigned long long o = va_arg(args, unsigned long long);

    p--;
    if (*p == '#' && o != 0)
        my_putstr("0");
    if (o == 0)
        my_putchar('0');
    else
        llo_flags(o);
    return 3;
}
