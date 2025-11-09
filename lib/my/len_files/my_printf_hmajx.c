/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/
#include "../../../include/my.h"
#include <stdarg.h>

int hmajx_flags(unsigned short n)
{
    int n2 = n % 16;

    if (n >= 16) {
        hmajx_flags(n / 16);
    }
    if (n2 > 9) {
        my_putchar(n2 + 55);
    } else {
        my_putchar(n2 + '0');
    }
    return 0;
}

int my_printf_hmajx(va_list args, const char *p)
{
    unsigned short x = (unsigned short)va_arg(args, unsigned int);

    hmajx_flags(x);
    return 2;
}
