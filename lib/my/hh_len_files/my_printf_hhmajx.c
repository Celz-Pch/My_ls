/*
** EPITECH PROJECT, 2025
** my_printf_HHXMAJ
** File description:
** HH LENGTH MODIFIER
*/
#include "../../../include/my.h"
#include <stdarg.h>

int hhmajx_flags(signed char n)
{
    int n2 = n % 16;

    if (n >= 16) {
        hhmajx_flags(n / 16);
    }
    if (n2 > 9) {
        my_putchar(n2 + 55);
    } else {
        my_putchar(n2 + '0');
    }
    return 0;
}

int my_printf_hhmajx(va_list args, const char *p)
{
    signed char x = (signed char)va_arg(args, unsigned int);

    p--;
    if (*p == x != 0) {
        my_putstr("0X");
    }
    hhmajx_flags(x);
    return 3;
}
