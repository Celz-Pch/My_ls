/*
** EPITECH PROJECT, 2025
** p_function for my_printf
** File description:
** %p
*/

#include "../../../include/my.h"
#include <stdarg.h>
#include <unistd.h>
#include "../../../include/my_struct.h"

static void my_hex(unsigned long n, base_t *base)
{
    if (n >= (unsigned long)base->length) {
        my_hex(n / base->length, base);
        my_putchar(base->symbols[n % base->length]);
    }
}

int my_printf_pointer(va_list args, const char *p)
{
    base_t hex = {"0123456789abcdef", 16};
    unsigned long n = va_arg(args, unsigned long);

    if (*p != 'p')
        return 0;
    my_putstr("0x");
    if (n == 0) {
        my_putchar('0');
        return 0;
    }
    if (n < 0) {
        return -1;
    }
    my_hex(n, &hex);
    return 1;
}
