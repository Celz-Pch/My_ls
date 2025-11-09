/*
** EPITECH PROJECT, 2025
** all my_printf
** File description:
** func
*/

#include <stdarg.h>
#include "../../../include/my_struct.h"
#include "../../../include/my.h"
#include <stdio.h>

int my_printf_i(va_list args, const char *p)
{
    int i = va_arg(args, int);

    p--;
    if (*p == ' ' && i > 0)
        my_putchar(' ');
    if (*p == '+' && i > 0)
        my_putchar('+');
    p++;
    if (*p == 'i' || *p == 'd')
        my_put_nbr(i);
    return 1;
}

int my_printf_c(va_list args, const char *p)
{
    char c = va_arg(args, int);

    if (*p != 'c')
        return 0;
    return my_putchar(c);
}

int my_printf_s(va_list args, const char *p)
{
    char *s = va_arg(args, char*);

    if (s == NULL) {
        my_printf("(null)");
        return 1;
    }
    if (*p != 's')
        return 0;
    my_putstr(s);
    return 1;
}

int my_printf_pourcent(va_list args, const char *p)
{
    (void)args;
    if (*p != '%')
        return 0;
    my_putchar('%');
    return 1;
}
