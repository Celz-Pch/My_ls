/*
** EPITECH PROJECT, 2025
** float
** File description:
** flags
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "../../../include/my.h"

void my_putfloat_decimals(double new_f)
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
    while (digits < 6) {
        my_putchar('0');
        digits++;
    }
    my_put_nbr(decimals);
}

void my_putfloat_pos(double f)
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
    my_putfloat_decimals(new_f);
}

int my_putfloat(double f)
{
    if (f < 0) {
        my_putchar('-');
        my_putfloat_pos(-f);
    } else
        my_putfloat_pos(f);
    return (0);
}

int my_printf_fl(va_list args, const char *p)
{
    double f = va_arg(args, double);

    if (f != f) {
        my_printf("nan");
        return 3;
    } else if (f == 1.0 / 0.0 || f == -1.0 / 0.0) {
        my_printf("inf");
    } else {
        my_putfloat(f);
    }
    return 1;
}

int my_printf_majfl(va_list args, const char *p)
{
    double f = va_arg(args, double);

    if (f != f) {
        my_printf("NAN");
        return 3;
    } else if (f == 1.0 / 0.0 || f == -1.0 / 0.0) {
        my_printf("INF");
    } else {
        my_putfloat(f);
    }
    return 0;
}
