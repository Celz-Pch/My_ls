/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my.h
*/

#include <dirent.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include "my_struct.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/types.h>

#ifndef LIB_H
    #define LIB_H

int my_putchar(char c);

int my_putstr(char const *str);

int my_put_nbr(int n);

int my_isneg(int nb);

void my_swap(int a, int b);

int my_strlen(char const *str);

int my_getnbr(char const *str);

void my_sort_int_array(int tab, int size);

int my_compute_square_root(int nb);

int my_is_prime(int nb);

int my_find_prime_sup(int nb);

char *my_strcpy(char *dest, char const *src);

char my_strncpy(char dest, char const src, int n);

char my_revstr(char str);

char my_strstr(char str, char const to_find);

int my_strncmp(char const s1, char const s2, int n);

char my_strupcase(char str);

char my_strlowcase(char str);

char my_strcapitalize(char str);

int my_str_isalpha(char const str);

int my_str_isnum(char const str);

int my_str_islower(char const str);

int my_str_isupper(char const str);

int my_str_ismy_printfable(char const str);

int my_showstr(char const str);

int my_showmem(char conststr, int size);

char *my_strcat(char *dest, char const *src);

char *my_strncat(char *dest, char const *src, int nb);

int my_putfloat(double f);

int my_printf_i(va_list args, const char *p);

int my_printf_c(va_list args, const char *p);

int my_printf_s(va_list args, const char *p);

int my_printf_pourcent(va_list args, const char *p);

int my_printf(const char *format, ...);

int my_printf_fl(va_list args, const char *p);

int my_printf_o(va_list args, const char *p);

int my_printf_u(va_list args, const char *p);

int my_printf_pointer(va_list args, const char *p);

int my_printf_x(va_list args, const char *p);

int my_printf_majx(va_list args, const char *p);

int my_printf_maje(va_list args, const char *p);

int my_print_e(va_list args, const char *p);

int guess_format(va_list args, const char *format);

int my_printf_b(va_list args, const char *p);

int my_printf_mathis(va_list args, const char *p);

int my_printf_hx(va_list args, const char *p);

int my_printf_hu(va_list args, const char *p);

int my_printf_hd(va_list args, const char *p);

int my_printf_hmajx(va_list args, const char *p);

int my_printf_ho(va_list args, const char *p);

int my_printf_majfl(va_list args, const char *p);

void my_printf_e_pos(double e);

int my_printf_hhd(va_list args, const char *p);

int my_printf_hhmajx(va_list args, const char *p);

int my_printf_hho(va_list args, const char *p);

int my_printf_hhu(va_list args, const char *p);

int my_printf_hhx(va_list args, const char *p);

void my_printf_e(double e, int is_negative_exp);

int my_printf_format(va_list args, const char *p);

int my_printf_ld(va_list args, const char *p);

int my_printf_lu(va_list args, const char *p);

int my_printf_lo(va_list args, const char *p);

int my_printf_lx(va_list args, const char *p);

int my_printf_lmajx(va_list args, const char *p);

int l_flags(va_list args, const char *p);

int my_printf_plus(va_list args, const char *p);

int my_put_zero(int n, int count);

int my_printf_less(va_list args, const char *p);

int len_flags(const char *p);

int get_count_nb(int nb);

int my_printf_zero(va_list args, const char *p);

int my_printf_espace(va_list args, const char *p);

int get_l(va_list args, const char *p);

int l_doubles(va_list args, const char *p);

int l_flags(va_list args, const char *p);

int verif_lbreak(long double e, int neg);

void my_printf_le_neg(long double e);

int verif_break_lmajneg(long double e);

void my_printf_lmaje_neg(long double e);

int verif_lbreak_majpos(long double e);

void my_printf_lmaje_pos(long double e);

int my_printf_lmaje(va_list args, const char *p);

void my_lputfloat_decimals(long double new_f);

void my_lputfloat_pos(long double f);

int my_lputfloat(long double f);

int my_printf_lfl(va_list args, const char *p);

int my_printf_lmajfl(va_list args, const char *p);

int my_put_nbr2(int n);

int my_printf_le(va_list args, const char *p);

int my_printf_point(va_list args, const char *p);

int my_printf_lld(va_list args, const char *p);

int my_printf_llmajx(va_list args, const char *p);

int my_printf_llo(va_list args, const char *p);

int my_printf_llu(va_list args, const char *p);

int my_printf_llx(va_list args, const char *p);

void sort_words(char **words, int count, flags_bool_t *all_flags);

void sort_words_array(char **words, int count, flags_bool_t *all_flags);

void my_printf_ls(char *path, flags_bool_t *all_flags, int i);

int get_nb_file(char *path);

void choose_ls(int argc, char **argv, flags_bool_t *all_flags);

void my_ls_solo(int argc, char **argv, flags_bool_t *all_flags);

void my_ls_flags_file(int argc, char **argv, flags_bool_t *all_flags);

void my_ls(char *path, flags_bool_t *all_flags);

void print_info(const char *path);

char *mystrdup(const char *s);

void my_ls_flags_d(char *path, flags_bool_t *all_flags);

int my_strcmp(char const *s1, char const *s2);

void my_ls_d_file(int argc, char **argv, flags_bool_t *all_flags);

void my_ls_recursive(char *path, flags_bool_t *all_flags);

int verif_printf(char **words, flags_bool_t *all_flags);

void sort_by_time(char **files, int count, flags_bool_t *all_flags);

DIR *openverif(const char *path);

char *my_strcat_alloc(char *dest, char const *src);

void my_ls_recursive(char *path, flags_bool_t *all_flags);

#endif
