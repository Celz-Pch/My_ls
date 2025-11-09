/*
** EPITECH PROJECT, 2025
** get_nb_file
** File description:
** c
*/

#include "../../include/my.h"

int get_nb_file(char *path)
{
    DIR *dir = opendir(path);
    struct dirent *dr;
    int count = 0;

    if (dir == NULL)
        return (0);
    dr = readdir(dir);
    while (dr != NULL) {
        count++;
        dr = readdir(dir);
    }
    closedir(dir);
    return (count);
}
