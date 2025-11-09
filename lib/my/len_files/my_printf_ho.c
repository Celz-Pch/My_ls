/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/
#include <stdarg.h>
#include <unistd.h>
#include "../../../include/my.h"

int ho_flags(unsigned short nb)
{
    if (nb <= 0)
        return 0;
    ho_flags(nb / 8);
    my_put_nbr(nb % 8);
    return 0;
}

int my_printf_ho(va_list args, const char *p)
{
    unsigned short o = (unsigned short)va_arg(args, unsigned int);

    p--;
    if (*p == o != 0) {
        my_putstr("0");
    } else {
        ho_flags(o);
    }
    return 2;
}
