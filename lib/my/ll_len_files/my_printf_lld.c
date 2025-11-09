/*
** EPITECH PROJECT, 2025
** my_printf_LD
** File description:
** L LENTGH MODIFIER
*/
#include <stdarg.h>
#include "../../../include/my.h"
#include <limits.h>

int my_put_nbrll(long long n)
{
    if (n < 0) {
        my_putchar('-');
        if (n == LLONG_MIN) {
            my_put_nbrll(-(n / 10));
            my_putchar('8');
            return 0;
        }
        n = -n;
    }
    if (n >= 10) {
        my_put_nbrll(n / 10);
    }
    my_putchar('0' + (n % 10));
    return 0;
}

int my_printf_lld(va_list args, const char *p)
{
    long long d = va_arg(args, long long);

    (void)p;
    my_put_nbrll(d);
    return 3;
}
