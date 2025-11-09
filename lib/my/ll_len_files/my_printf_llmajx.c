/*
** EPITECH PROJECT, 2025
** my_printf_LMAJX
** File description:
** L LENGTH MODIFIER
*/

#include <stdarg.h>
#include "../../../include/my.h"

int llmajx_flags(unsigned long long n)
{
    int n2 = n % 16;

    if (n >= 16)
        llmajx_flags(n / 16);
    if (n2 > 9)
        my_putchar(n2 + 55);
    else
        my_putchar(n2 + '0');
    return 0;
}

int my_printf_llmajx(va_list args, const char *p)
{
    unsigned long long x = va_arg(args, unsigned long long);

    p--;
    if (*p == '#' && x != 0)
        my_putstr("0X");
    if (x == 0)
        my_putchar('0');
    else
        llmajx_flags(x);
    return 3;
}
