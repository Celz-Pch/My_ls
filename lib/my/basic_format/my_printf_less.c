/*
** EPITECH PROJECT, 2025
** format
** File description:
** basic
*/

#include <stdarg.h>
#include "../../../include/my.h"
#include <stdio.h>

void choose_nb2(int nb, const char *p)
{
    int count = get_count_nb(nb);

    my_put_nbr(nb);
    for (int i = 0; i < -my_getnbr(p) - count; i++)
        my_putchar(' ');
}

int my_printf_less(va_list args, const char *p)
{
    int nb = va_arg(args, int);

    if (*p == 'd' || *p == 'i') {
        my_put_nbr(nb);
    } else {
        choose_nb2(nb, p);
    }
    return len_flags(p);
}
