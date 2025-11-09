/*
** EPITECH PROJECT, 2025
** e_flags
** File description:
** e_flags
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "../../../include/my.h"

int verif_break(double e, int neg)
{
    if (e < 10 && neg == 2)
        return 1;
    if (e >= 1 && neg == 1)
        return 1;
    return 0;
}

void my_printf_e_neg(double e)
{
    double nb = e;
    int count = 0;
    int break_while = verif_break(e, 1);

    if (nb < 0) {
        nb = -e;
        my_putchar('-');
    }
    while (break_while != 1) {
        count++;
        nb = nb * 10;
        if (nb >= 1)
            break_while = 1;
    }
    my_putfloat(nb);
    if (count < 10)
        my_putstr("e-0");
    else
        my_putstr("e-");
    my_put_nbr(count);
}

void my_printf_e_pos(double e)
{
    double nb = e;
    int count = 0;
    int break_while = verif_break(e, 2);

    if (nb < 0) {
        nb = -e;
        my_putchar('-');
    }
    while (break_while != 1) {
        count++;
        nb = nb / 10;
        if (nb < 10)
            break_while = 1;
    }
    my_putfloat(nb);
    if (count < 10)
        my_putstr("e+0");
    else
        my_putstr("e+");
    my_put_nbr(count);
}

int my_print_e(va_list args, const char *p)
{
    double e = va_arg(args, double);

    if ((e < 1 && e > 0) || (e > -1 && e < 0))
        my_printf_e_neg(e);
    else
        my_printf_e_pos(e);
    return 1;
}
