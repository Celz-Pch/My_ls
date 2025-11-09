/*
** EPITECH PROJECT, 2025
** format
** File description:
** basic
*/

#include <stdarg.h>
#include "../../../include/my.h"
#include <stdio.h>

int get_count_nb(int nb)
{
    int count = 1;
    int nb2 = nb;

    if (nb2 < 0) {
        nb2 = -nb2;
    }
    if (nb2 == 0)
        return count + 1;
    while (nb2 > 0) {
        count++;
        nb2 /= 10;
    }
    return count;
}

void choose_nb(int nb, const char *p)
{
    int count = get_count_nb(nb);

    p++;
    if (*p == '0') {
        my_put_zero(nb, my_getnbr(p) - count);
    } else {
        for (int i = 0; i < my_getnbr(p) - count; i++)
            my_putchar(' ');
        if (nb >= 0)
            my_putchar('+');
        my_put_nbr(nb);
    }
}

int len_flags(const char *p)
{
    int i = 0;

    for (i = 0; *p && *p != 'd' && *p != 'i'; i++) {
        p++;
    }
    return i + 1;
}

int my_printf_plus(va_list args, const char *p)
{
    int nb = va_arg(args, int);

    if (*p == 'd' || *p == 'i') {
        if (nb >= 0)
            my_putchar('+');
        my_put_nbr(nb);
    } else {
        choose_nb(nb, p);
    }
    return len_flags(p);
}
