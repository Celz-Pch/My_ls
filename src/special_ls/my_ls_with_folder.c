/*
** EPITECH PROJECT, 2025
** ls
** File description:
** folder
*/

#include "../../include/my.h"

void my_ls_solo_d(int argc, char **argv, flags_bool_t *all_flags)
{
    struct stat s;

    for (int i = 1; i < argc; i++) {
        if (stat(argv[i], &s) == -1 && argv[i][0] != '-') {
            my_printf("ls: cannot access '%s': No such file or directory\n"
                , argv[i]);
            continue;
        }
        if (S_ISDIR(s.st_mode))
            my_printf("%s\n", argv[i]);
        if (S_ISREG(s.st_mode))
            my_printf("%s\n", argv[i]);
    }
}

static void test(char **argv, flags_bool_t *all_flags, int i)
{
    struct stat s;

    stat(argv[i], &s);
    if (S_ISDIR(s.st_mode)) {
        if (all_flags[2].is_here == 1)
            my_ls_recursive(argv[i], all_flags);
        else
            my_ls(argv[i], all_flags);
        return;
    }
    if (!S_ISREG(s.st_mode))
        return;
    if (all_flags[3].is_here == 1) {
        print_info(argv[i]);
        return;
    }
    my_printf("%s\n", argv[i]);
}

void my_ls_solo(int argc, char **argv, flags_bool_t *all_flags)
{
    struct stat s;

    if (all_flags[1].is_here == 1) {
        my_ls_solo_d(argc, argv, all_flags);
        return;
    }
    for (int i = 1; i < argc; i++) {
        if (stat(argv[i], &s) == -1 && argv[i][0] != '-') {
            my_printf("ls: cannot access '%s': No such file or directory\n"
                , argv[i]);
            continue;
        }
        test(argv, all_flags, i);
    }
}

static int has_directories(int argc, char **argv)
{
    struct stat s;
    int i;

    for (i = 1; i < argc; i++) {
        if (stat(argv[i], &s) == -1 || argv[i][0] == '-')
            continue;
        if (S_ISDIR(s.st_mode))
            return 1;
    }
    return 0;
}

void my_ls_flags_folder(int argc, char **argv, flags_bool_t *all_flags)
{
    struct stat s;
    int first = 0;

    for (int i = 1; i < argc; i++) {
        if (stat(argv[i], &s) == -1 || argv[i][0] == '-')
            continue;
        if (!S_ISDIR(s.st_mode))
            continue;
        if (first == 1)
            my_printf("\n");
        if (all_flags[2].is_here != 1)
            my_printf("%s:\n", argv[i]);
        if (all_flags[2].is_here == 1)
            my_ls_recursive(argv[i], all_flags);
        else
            my_ls(argv[i], all_flags);
        first = 1;
    }
}

void my_ls_flags_suite(int argc, char **argv, flags_bool_t *all_flags, int f)
{
    int has_dirs;

    has_dirs = has_directories(argc, argv);
    if (f > 0 && has_dirs > 0)
        my_printf("\n");
    my_ls_flags_folder(argc, argv, all_flags);
}

static void my_ls_test(char **argv, flags_bool_t *all_flags, int i, int *first)
{
    struct stat s;

    stat(argv[i], &s);
    if (all_flags[3].is_here == 1) {
        if (S_ISREG(s.st_mode)) {
            print_info(argv[i]);
            (*first)++;
        }
    }
    if (all_flags[3].is_here == 0) {
        if (S_ISREG(s.st_mode) && argv[i][0] != '-' && *first == 1) {
            my_printf("  %s", argv[i]);
        }
        if (S_ISREG(s.st_mode) && argv[i][0] != '-' && *first == 0) {
            my_printf("%s", argv[i]);
            (*first)++;
        }
    }
}

void my_ls_flags_file(int argc, char **argv, flags_bool_t *all_flags)
{
    struct stat s;
    int first = 0;

    my_ls_d_file(argc, argv, all_flags);
    for (int i = 1; i < argc; i++) {
        if (stat(argv[i], &s) == -1 && argv[i][0] != '-') {
            my_printf("ls: cannot access '%s': No such file or directory\n"
                , argv[i]);
            continue;
        }
        my_ls_test(argv, all_flags, i, &first);
    }
    my_ls_flags_suite(argc, argv, all_flags, first);
}
