/*
** EPITECH PROJECT, 2025
** str
** File description:
** cata
*/


#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *result;

    result = dest;
    while (dest[i] != '\0') {
        i++;
    }
    while (src[j] != '\0') {
        result[i] = src[j];
        i++;
        j++;
    }
    result[i] = '\0';
    return (result);
}

char *my_strcat_alloc(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *result;

    result = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    if (result == NULL)
        return (NULL);
    while (dest[i] != '\0') {
        result[i] = dest[i];
        i++;
    }
    while (src[j] != '\0') {
        result[i] = src[j];
        i++;
        j++;
    }
    result[i] = '\0';
    return (result);
}
