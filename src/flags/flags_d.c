/*
** EPITECH PROJECT, 2025
** flags_d.c
** File description:
** flags_d.c
*/

#include "../../include/my.h"

void free_and_sort(char **files, flags_bool_t *all_flags, int j)
{
    sort_words(files, j, all_flags);
    free(files);
    exit(0);
}

void my_ls_d_file(int argc, char **argv, flags_bool_t *all_flags)
{
    struct stat s;
    char **files = malloc(sizeof(char *) * (argc));
    int j = 0;

    if (all_flags[1].is_here != 1)
        return;
    for (int i = 1; i < argc; i++) {
        if (stat(argv[i], &s) == -1 || !argv[i])
            continue;
        if (S_ISDIR(s.st_mode)) {
            files[j] = argv[i];
            j++;
        }
        if (S_ISREG(s.st_mode)) {
            files[j] = argv[i];
            j++;
        }
    }
    files[j] = NULL;
    free_and_sort(files, all_flags, j);
}

void my_ls_flags_d(char *path, flags_bool_t *all_flags)
{
    DIR *dir = opendir(path);
    struct dirent *dr;

    dr = readdir(dir);
    while (dr != NULL) {
        if (my_strcmp(dr->d_name, ".") == 0
            && all_flags[3].is_here == 1)
            print_info(path);
        if (my_strcmp(dr->d_name, ".") == 0
            && all_flags[3].is_here != 1)
            my_printf("%s\n", path);
        dr = readdir(dir);
    }
    closedir(dir);
}
