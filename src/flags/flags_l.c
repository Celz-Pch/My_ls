/*
** EPITECH PROJECT, 2025
** flags_l.c
** File description:
** flags_l.c
*/

#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <dirent.h>
#include "../../include/my.h"
#include <string.h>

void print_permissions(mode_t mode)
{
    my_putchar((mode & S_IRUSR) ? 'r' : '-');
    my_putchar((mode & S_IWUSR) ? 'w' : '-');
    my_putchar((mode & S_IXUSR) ? 'x' : '-');
    my_putchar((mode & S_IRGRP) ? 'r' : '-');
    my_putchar((mode & S_IWGRP) ? 'w' : '-');
    my_putchar((mode & S_IXGRP) ? 'x' : '-');
    my_putchar((mode & S_IROTH) ? 'r' : '-');
    my_putchar((mode & S_IWOTH) ? 'w' : '-');
    my_putchar((mode & S_IXOTH) ? 'x' : '-');
}

void print_file_type(mode_t mode)
{
    if (S_ISREG(mode))
        my_putchar('-');
    if (S_ISDIR(mode))
        my_putchar('d');
    if (S_ISCHR(mode))
        my_putchar('c');
    if (S_ISBLK(mode))
        my_putchar('b');
    if (S_ISFIFO(mode))
        my_putchar('p');
    if (S_ISLNK(mode))
        my_putchar('l');
    if (S_ISSOCK(mode))
        my_putchar('s');
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

void print_info_second(const char *path, char *time_str)
{
    struct stat st;
    struct passwd *pwd;
    struct group *grp;
    char *filename;

    if (lstat(path, &st) == -1)
        return;
    pwd = getpwuid(st.st_uid);
    grp = getgrgid(st.st_gid);
    time_str = ctime(&st.st_mtime);
    time_str = ctime(&st.st_mtime);
    time_str = ctime(&st.st_mtime);
    for (int i = 4; i < 16; i++)
        if (time_str[i] >= 'a' && time_str[i] <= 'z')
            time_str[i] = time_str[i];
    write(1, time_str + 4, 12);
    filename = get_filename_from_path(path);
    my_printf(" %s\n", filename);
}

void print_info(const char *path)
{
    struct stat st;
    struct passwd *pwd;
    struct group *grp;
    char *time_str;

    if (stat(path, &st) == -1)
        return;
    pwd = getpwuid(st.st_uid);
    grp = getgrgid(st.st_gid);
    print_file_type(st.st_mode);
    print_permissions(st.st_mode);
    my_printf(" %d %s %s %d ", st.st_nlink,
        pwd ? pwd->pw_name : "unknown",
        grp ? grp->gr_name : "unknown", st.st_size
    );
    print_info_second(path, time_str);
}
