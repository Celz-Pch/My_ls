/*
** EPITECH PROJECT, 2025
** my_printf_LD
** File description:
** L LENTGH MODIFIER
*/
#include <stdarg.h>
#include "../../../include/my.h"

long my_put_nbrlong(long n)
{
    if (n < 0) {
        my_putchar('-');
        if (n == -9223372036854775807L - 1) {
            my_put_nbrlong(9223372036854775807L / 10);
            my_putchar('8');
            return 0;
        }
        n = -n;
    }
    if (n >= 10) {
        my_put_nbrlong(n / 10);
    }
    my_putchar('0' + (n % 10));
    return 0;
}

int my_printf_ld(va_list args, const char *p)
{
    long d = va_arg(args, long);

    (void)p;
    my_put_nbrlong(d);
    return 2;
}
