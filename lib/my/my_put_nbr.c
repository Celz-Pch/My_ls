/*
** EPITECH PROJECT, 2025
** my_put_nbr
** File description:
** put nbr
*/

#include "../../include/my.h"
#include <stdio.h>

int verif_number(int n)
{
    if (n == -2147483648) {
        my_putstr("-2147483648");
        return (1);
    }
    return (0);
}

int my_put_nbr(int n)
{
    if (verif_number(n) == 1) {
        return -1;
    }
    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    if (n >= 10) {
        my_put_nbr(n / 10);
    }
    my_putchar('0' + (n % 10));
    return 0;
}

int my_put_nbr2(int n)
{
    if (verif_number(n) == 1) {
        return -1;
    }
    if (n < 0) {
        n = -n;
    }
    if (n >= 10) {
        my_put_nbr(n / 10);
    }
    my_putchar('0' + (n % 10));
    return 0;
}

void my_zero(int count)
{
    for (int i = 0; i < count; i++)
        my_putchar('0');
}

int my_put_zero(int n, int count)
{
    if (verif_number(n) == 1) {
        return -1;
    }
    if (n >= 0) {
        my_putchar('+');
        my_zero(count);
    }
    if (n < 0) {
        my_putchar('-');
        my_zero(count);
        n = -n;
    }
    if (n >= 10) {
        my_put_nbr(n / 10);
    }
    my_putchar('0' + (n % 10));
    return 0;
}
