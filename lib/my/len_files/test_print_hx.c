/*
** EPITECH PROJECT, 2025
** my_printf_HX
** File description:
** TEST
*/
#include <stdarg.h>
#include <unistd.h>
#include "../../../include/my.h"

int hx_flags(unsigned short n)
{
    int n2 = n % 16;

    if (n >= 16) {
        hx_flags(n / 16);
    }
    if (n2 > 9) {
        my_putchar(n2 + 87);
    } else {
        my_putchar(n2 + '0');
    }
    return 0;
}

int my_printf_hx(va_list args)
{
    unsigned short x = (unsigned short)va_arg(args, unsigned int);

    return hx_flags(x);
}
