/*
** EPITECH PROJECT, 2025
** my_printf_point
** File description:
** point
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "../../../include/my.h"

void my_putfloat_dpoint(double new_f, int after)
{
    int decimals;
    int tmp;
    int digits;

    decimals = (int)new_f;
    tmp = decimals;
    digits = 0;
    while (tmp > 0) {
        tmp /= 10;
        digits++;
    }
    my_put_nbr(decimals);
    while (digits < after) {
        my_putchar('0');
        digits++;
    }
}

void my_putfloat_point(double f, int after)
{
    int get_f;
    double new_f;
    int decimals;

    get_f = (int)f;
    new_f = (f - get_f) * 1000000 + 0.5;
    decimals = (int)new_f;
    if (decimals >= 1000000) {
        get_f += 1;
        decimals = 0;
    }
    my_put_nbr(get_f);
    my_putchar('.');
    my_putfloat_dpoint(new_f, after);
}

int my_putpoint(double f, int after)
{
    if (f < 0) {
        my_putchar('-');
        my_putfloat_point(-f, after);
    } else
        my_putfloat_point(f, after);
    return (0);
}

int my_printf_point(va_list args, const char *p)
{
    double f = va_arg(args, double);

    p++;
    if (*p == 'f' || *p == 'F')
        my_put_nbr((int)f);
    else
        my_putpoint(f, my_getnbr(p));
    return len_flags(p);
}
