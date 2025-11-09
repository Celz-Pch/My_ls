/*
** EPITECH PROJECT, 2025
** sort alphabet
** File description:
** word array
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/my.h"

static char my_charlowcase(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
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

static int my_strcmp_lowercase(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return 0;
    while (my_charlowcase(s1[i]) == my_charlowcase(s2[i])) {
        if (my_charlowcase(s1[i]) == '\0')
            return 0;
        i++;
    }
    return my_charlowcase(s1[i]) - my_charlowcase(s2[i]);
}

void compare_and_swap(char **a, char **b)
{
    char *temp;
    char *filename_a = get_filename_from_path(*a);
    char *filename_b = get_filename_from_path(*b);

    if (my_strcmp_lowercase(filename_a, filename_b) > 0) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

void count_and_send(char **words, flags_bool_t *all_flags)
{
    int total_blocks = 0;
    struct stat st;

    for (int i = 0; words[i] != NULL; i++) {
        if (lstat(words[i], &st) == -1)
            continue;
        total_blocks += st.st_blocks;
    }
    if (all_flags[1].is_here != 1)
        my_printf("total %d\n", total_blocks / 2);
    for (int i = 0; words[i] != NULL; i++) {
        print_info(words[i]);
    }
}

int verif_printf(char **words, flags_bool_t *all_flags)
{
    if (all_flags[3].is_here == 1) {
        count_and_send(words, all_flags);
        return 1;
    }
    return 0;
}

static void print_word_list(char **words, int count)
{
    char *filename;

    for (int i = 0; i < count; i++) {
        if (words[i] == NULL)
            continue;
        filename = get_filename_from_path(words[i]);
        if (filename == NULL)
            continue;
        if (i == 0)
            my_printf("%s", filename);
        else
            my_printf("  %s", filename);
    }
}

void sort_words(char **words, int count, flags_bool_t *all_flags)
{
    int i;
    int j;

    if (all_flags[4].is_here == 1) {
        sort_by_time(words, count, all_flags);
        return;
    }
    for (i = 0; i < count; i++) {
        for (j = i + 1; j < count; j++) {
            compare_and_swap(&words[i], &words[j]);
        }
    }
    if (verif_printf(words, all_flags) == 1)
        return;
    print_word_list(words, count);
}

void sort_words_array(char **words, int count, flags_bool_t *all_flags)
{
    if (all_flags[4].is_here == 1) {
        sort_by_time(words, count, all_flags);
        return;
    }
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            compare_and_swap(&words[i], &words[j]);
        }
    }
}
