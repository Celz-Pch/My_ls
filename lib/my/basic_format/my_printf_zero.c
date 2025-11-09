/*
** EPITECH PROJECT, 2025
** zero
** File description:
** zero
*/

#include <stdarg.h>
#include "../../../include/my.h"

void my_zero2(int count)
{
    for (int i = 0; i < count; i++)
        my_putchar('0');
}

int my_printf_zero(va_list args, const char *p)
{
    int nb = va_arg(args, int);
    int count = get_count_nb(nb);

    if (nb >= 0) {
        my_zero2(my_getnbr(p) - count + 1);
        my_put_nbr(nb);
    } else {
        my_putchar('-');
        my_zero2(my_getnbr(p) - count);
        my_put_nbr2(nb);
    }
    return len_flags(p);
}
