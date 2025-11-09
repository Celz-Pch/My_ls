/*
** EPITECH PROJECT, 2025
** espace
** File description:
** format
*/

#include <stdarg.h>
#include "../../../include/my.h"

int my_printf_espace(va_list args, const char *p)
{
    int nb = va_arg(args, int);
    int count = get_count_nb(nb);

    if (nb > 0)
        my_putchar(' ');
    my_put_nbr(nb);
    return len_flags(p);
}
