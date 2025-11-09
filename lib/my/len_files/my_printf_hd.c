/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/
#include <stdarg.h>
#include <unistd.h>
#include "../../../include/my.h"

int my_printf_hd(va_list args, const char *p)
{
    short d = (short)va_arg(args, int);

    my_put_nbr(d);
    return 2;
}
