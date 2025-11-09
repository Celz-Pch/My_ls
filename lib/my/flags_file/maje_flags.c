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

int verif_break_majneg(double e)
{
    if (e >= 1)
        return 1;
    return 0;
}

void my_printf_maje_neg(double e)
{
    double nb = e;
    int count = 0;
    int break_while = verif_break_majneg(e);

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
        my_putstr("E-0");
    else
        my_putstr("E-");
    my_put_nbr(count);
}

int verif_break_majpos(double e)
{
    if (e < 10)
        return 1;
    return 0;
}

void my_printf_maje_pos(double e)
{
    double nb = e;
    int count = 0;
    int break_while = verif_break_majpos(e);

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
        my_putstr("E+0");
    else
        my_putstr("E+");
    my_put_nbr(count);
}

int my_printf_maje(va_list args, const char *p)
{
    double e = va_arg(args, double);

    if (*p != 'E')
        return 0;
    if ((e < 1 && e > 0) || (e > -1 && e < 0))
        my_printf_maje_neg(e);
    else
        my_printf_maje_pos(e);
    return 1;
}
