/*
** EPITECH PROJECT, 2025
** choose_ms
** File description:
** a function that choose between ls 1 or ls x
*/

#include "../../include/my.h"

void edit_struct(int flags_found, char *flags, int i, flags_bool_t *all_flags)
{
    if (flags[i] == all_flags[flags_found].flags)
        all_flags[flags_found].is_here = 1;
}

void detect_flags(char *flags, flags_bool_t *all_flags)
{
    int i;
    int struct_len;

    for (i = 1; flags[i] != '\0'; i++) {
        for (struct_len = 0; struct_len < 6; struct_len++) {
            edit_struct(struct_len, flags, i, all_flags);
        }
    }
}

void check_flags(int argc, char **argv, flags_bool_t *all_flags)
{
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            detect_flags(argv[i], all_flags);
        }
    }
}

void do_flags_no_file(int argc, char **argv, flags_bool_t *all_flags)
{
    if (all_flags[1].is_here == 1) {
        my_ls_flags_d(".", all_flags);
        return;
    }
    if (all_flags[2].is_here == 1) {
        my_ls_recursive(".", all_flags);
        return;
    }
    if (all_flags[4].is_here == 1) {
        my_ls(".", all_flags);
        return;
    }
    if (all_flags[0].is_here == 1) {
        my_ls(".", all_flags);
        return;
    }
    if (all_flags[3].is_here == 1) {
        my_ls(".", all_flags);
        return;
    }
}

static int get_count_dir(int argc, char **argv)
{
    struct stat s;
    int count = 0;

    for (int i = 1; i < argc; i++) {
        if (stat(argv[i], &s) == -1 && argv[i][0] != '-') {
            return 84;
            continue;
        }
        if ((S_ISDIR(s.st_mode) || S_ISREG(s.st_mode)) && argv[i][0] != '-')
            count++;
    }
    return count;
}

void choose_ls(int argc, char **argv, flags_bool_t *all_flags)
{
    struct stat s;
    int count = 0;

    check_flags(argc, argv, all_flags);
    count = get_count_dir(argc, argv);
    if (count == 0)
        do_flags_no_file(argc, argv, all_flags);
    if (count == 1) {
        my_ls_solo(argc, argv, all_flags);
    } else {
        my_ls_flags_file(argc, argv, all_flags);
    }
}
