/*
** EPITECH PROJECT, 2025
** test
** File description:
** test
*/

#include "../../include/my.h"
#include <sys/stat.h>
#include <time.h>

static time_t file_mtime(const char *path)
{
    struct stat st;

    if (!path || stat(path, &st) == -1)
        return (time_t)0;
    return st.st_mtime;
}

static char *get_filename_from_path(const char *path)
{
    int i;
    int last_slash = -1;

    if (path == NULL)
        return NULL;
    for (i = 0; path[i] != '\0'; i++) {
        if (path[i] == '/')
            last_slash = i;
    }
    if (last_slash == -1)
        return (char *)path;
    return (char *)&path[last_slash + 1];
}

void compare_by_time(char **files, int i, int j)
{
    time_t ti = file_mtime(files[i]);
    time_t tj = file_mtime(files[j]);
    char *tmp;
    char *filename_i = get_filename_from_path(files[i]);
    char *filename_j = get_filename_from_path(files[j]);

    if (!files[i] || !files[j])
        return;
    if (tj > ti) {
        tmp = files[i];
        files[i] = files[j];
        files[j] = tmp;
    } else if (tj == ti && my_strcmp(filename_i, filename_j) < 0) {
        tmp = files[i];
        files[i] = files[j];
        files[j] = tmp;
    }
}

void print_time(char **files, int count, flags_bool_t *all_flags)
{
    int i;
    char *filename;

    for (i = 0; i < count; i++) {
        if (!files[i] || files[i][0] == '\0' || files[i] == NULL)
            continue;
        filename = get_filename_from_path(files[i]);
        if (i == 0)
            my_printf("%s", filename);
        else
            my_printf("  %s", filename);
    }
}

void sort_by_time(char **files, int count, flags_bool_t *all_flags)
{
    int nb_files = 0;

    while (files[nb_files])
        nb_files++;
    if (nb_files <= 0)
        return;
    for (int i = 0; i < nb_files - 1; i++) {
        for (int j = i + 1; j < nb_files; j++) {
            compare_by_time(files, i, j);
        }
    }
    if (verif_printf(files, all_flags) == 1) {
        return;
    }
    print_time(files, nb_files, all_flags);
    exit(0);
}
