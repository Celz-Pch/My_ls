/*
** EPITECH PROJECT, 2025
** my_printf_LX
** File description:
** L LENGTH MODIFIER
*/
#include <stdarg.h>
#include "../../../include/my.h"

int llx_flags(unsigned long long n)
{
    int n2 = n % 16;

    if (n >= 16)
        llx_flags(n / 16);
    if (n2 > 9)
        my_putchar(n2 + 87);
    else
        my_putchar(n2 + '0');
    return 0;
}

int my_printf_llx(va_list args, const char *p)
{
    unsigned long long x = va_arg(args, unsigned long long);

    p--;
    if (*p == '#' && x != 0)
        my_putstr("0x");
    if (x == 0)
        my_putchar('0');
    else
        llx_flags(x);
    return 3;
}
