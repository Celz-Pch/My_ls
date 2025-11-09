/*
** EPITECH PROJECT, 2025
** my_printf_LU
** File description:
** L LENTGH MODIFIER
*/
#include <stdarg.h>
#include "../../../include/my.h"

int lu_flags(unsigned long n)
{
    if (n >= 10) {
        lu_flags(n / 10);
    }
    my_putchar((n % 10) + '0');
    return 0;
}

int my_printf_lu(va_list args, const char *p)
{
    unsigned long u = va_arg(args, unsigned long);

    lu_flags(u);
    return 2;
}
