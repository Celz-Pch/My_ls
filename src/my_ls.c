/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** file with all functions for a basic ls with sort and with the main for argv
*/

#include "../include/my.h"

DIR *openverif(const char *path)
{
    struct stat st;
    DIR *dir;

    if (stat(path, &st) == -1)
        exit(84);
    if (!S_ISDIR(st.st_mode))
        exit(84);
    dir = opendir(path);
    if (dir == NULL)
        exit(84);
    return dir;
}

static char *build_full_path(char *path, char *filename)
{
    char *full_path;
    char *path_with_slash;
    int path_len;

    if (path == NULL || filename == NULL)
        return NULL;
    path_len = my_strlen(path);
    if (path_len == 0) {
        return mystrdup(filename);
    }
    if (path[path_len - 1] == '/') {
        path_with_slash = mystrdup(path);
    } else {
        path_with_slash = my_strcat_alloc(path, "/");
    }
    full_path = my_strcat_alloc(path_with_slash, filename);
    free(path_with_slash);
    return full_path;
}

static const char *get_filename_from_path(const char *path)
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
        return path;
    return &path[last_slash + 1];
}

static int is_current_or_parent(const char *entry)
{
    if (entry == NULL)
        return 0;
    if (my_strcmp(entry, ".") == 0)
        return 1;
    if (my_strcmp(entry, "..") == 0)
        return 1;
    return 0;
}

static int is_directory_path(const char *path)
{
    struct stat st;

    if (path == NULL)
        return 0;
    if (lstat(path, &st) == -1)
        return 0;
    return S_ISDIR(st.st_mode);
}

static void free_entries(char **entries)
{
    int i;

    if (entries == NULL)
        return;
    for (i = 0; entries[i] != NULL; i++)
        free(entries[i]);
    free(entries);
}

static void handle_recursive_listing(
    char **entries,
    int count,
    flags_bool_t *all_flags)
{
    const char *filename;

    if (all_flags[2].is_here != 1 || all_flags[1].is_here == 1)
        return;
    for (int i = 0; i < count; i++) {
        if (entries[i] == NULL)
            continue;
        if (!is_directory_path(entries[i]))
            continue;
        filename = get_filename_from_path(entries[i]);
        if (filename == NULL)
            continue;
        if (is_current_or_parent(filename))
            continue;
        my_printf("\n");
        my_ls_recursive(entries[i], all_flags);
    }
}

static int fill_stock_ls(
    DIR *dir,
    char *path,
    char **stock_ls,
    flags_bool_t *all_flags)
{
    struct dirent *dr;
    int i = 0;
    char *full_path;

    dr = readdir(dir);
    while (dr != NULL) {
        if (dr->d_name[0] != '.') {
            full_path = build_full_path(path, dr->d_name);
            stock_ls[i] = full_path;
            i++;
        }
        if (dr->d_name[0] == '.' && all_flags[0].is_here == 1) {
            full_path = build_full_path(path, dr->d_name);
            stock_ls[i] = full_path;
            i++;
        }
        dr = readdir(dir);
    }
    stock_ls[i] = NULL;
    return i;
}

void my_ls(char *path, flags_bool_t *all_flags)
{
    int nb_entries = get_nb_file(path);
    DIR *dir = openverif(path);
    char **stock_ls = malloc(sizeof(char *) * (nb_entries + 1));
    int count;

    if (stock_ls == NULL) {
        closedir(dir);
        return;
    }
    count = fill_stock_ls(dir, path, stock_ls, all_flags);
    closedir(dir);
    sort_words(stock_ls, count, all_flags);
    if (all_flags[3].is_here == 0 && count > 0)
        my_printf("\n");
    handle_recursive_listing(stock_ls, count, all_flags);
    free_entries(stock_ls);
}

int main(int argc, char **argv)
{
    flags_bool_t all_flags[] = {
        {'a', 0}, {'d', 0}, {'R', 0}, {'l', 0}, {'t', 0}
    };

    if (argc == 1)
        my_ls(".", all_flags);
    else
        choose_ls(argc, argv, all_flags);
    return (0);
}
