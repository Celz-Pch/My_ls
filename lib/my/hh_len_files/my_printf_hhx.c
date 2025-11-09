/*
** EPITECH PROJECT, 2025
** MY_PRIONT_HHX
** File description:
** HH LENGTH MODIFIER
*/
#include <stdarg.h>
#include <unistd.h>
#include "../../../include/my.h"

int hhx_flags(signed char n)
{
    int n2 = n % 16;

    if (n >= 16)
        hhx_flags(n / 16);
    if (n2 > 9)
        my_putchar(n2 + 87);
    else
        my_putchar(n2 + '0');
    return 0;
}

int my_printf_hhx(va_list args, const char *p)
{
    signed char x = (signed char)va_arg(args, unsigned int);

    p--;
    if (x == 0)
        my_putchar('0');
    else
        hhx_flags(x);
    return 3;
}
