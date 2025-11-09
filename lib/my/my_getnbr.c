/*
** EPITECH PROJECT, 2025
** my_getnbr
** File description:
** my_getnbr
*/

#include <stdio.h>

int my_getnbr(char const *str)
{
    int i = 0;
    int letter_dettect = 0;
    int number = 0;
    int negatif = 1;
    int nbr_get = 0;

    while (str[i] != '\0' && letter_dettect == 0) {
        if (str[i] == 45) {
            negatif = negatif * (-1);
        }
        if (str[i] >= 48 && str[i] <= 57) {
            number = number * 10 + (str[i] - 48);
            nbr_get = 1;
        }
        i++;
        if (str[i] < 48 && nbr_get == 1 || str[i] > 57 && nbr_get == 1) {
            letter_dettect = 1;
        }
    }
    return (number * negatif);
}
