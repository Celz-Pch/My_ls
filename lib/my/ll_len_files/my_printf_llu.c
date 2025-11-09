/*
** EPITECH PROJECT, 2025
** my_printf_LU
** File description:
** L LENTGH MODIFIER
*/
#include <stdarg.h>
#include "../../../include/my.h"

int llu_flags(unsigned long long n)
{
    if (n >= 10) {
        llu_flags(n / 10);
    }
    my_putchar((n % 10) + '0');
    return 0;
}

int my_printf_llu(va_list args, const char *p)
{
    unsigned long long u = va_arg(args, unsigned long long);

    llu_flags(u);
    return 3;
}
