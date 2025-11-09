/*
** EPITECH PROJECT, 2025
** strdup
** File description:
** strdup
*/

#include <stdlib.h>

char *mystrdup(const char *s)
{
    int len = 0;
    char *dup;

    while (s[len] != '\0')
        len++;
    dup = malloc(len + 1);
    if (!dup)
        return NULL;
    for (int i = 0; i <= len; i++)
        dup[i] = s[i];
    return dup;
}
