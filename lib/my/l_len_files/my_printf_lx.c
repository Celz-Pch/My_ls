/*
** EPITECH PROJECT, 2025
** my_printf_LX
** File description:
** L LENGTH MODIFIER
*/
#include <stdarg.h>
#include "../../../include/my.h"

int lx_flags(unsigned long n)
{
    int n2 = n % 16;

    if (n >= 16)
        lx_flags(n / 16);
    if (n2 > 9)
        my_putchar(n2 + 87);
    else
        my_putchar(n2 + '0');
    return 0;
}

int my_printf_lx(va_list args, const char *p)
{
    unsigned long x = va_arg(args, unsigned long);

    p--;
    if (*p == '#' && x != 0)
        my_putstr("0x");
    if (x == 0)
        my_putchar('0');
    else
        lx_flags(x);
    return 2;
}
