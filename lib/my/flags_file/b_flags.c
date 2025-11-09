/*
** EPITECH PROJECT, 2025
** binaire flags
** File description:
** b flags
*/

#include <stdarg.h>
#include "../../../include/my.h"

int b_flags(int binaire)
{
    if (binaire > 1)
        b_flags(binaire / 2);
    my_putchar((binaire % 2) + '0');
    return 1;
}

int my_printf_b(va_list args, const char *p)
{
    unsigned int b = va_arg(args, int);

    if (*p != 'b')
        return 0;
    return b_flags(b);
}
