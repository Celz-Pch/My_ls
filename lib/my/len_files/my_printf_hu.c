/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/
#include "../../../include/my.h"
#include <stdarg.h>

int hu_flags(unsigned short n)
{
    if (n >= 10) {
        hu_flags(n / 10);
    }
    my_putchar((n % 10) + '0');
    return 0;
}

int my_printf_hu(va_list args, const char *p)
{
    unsigned short u = (unsigned short)va_arg(args, unsigned int);

    hu_flags(u);
    return 2;
}
