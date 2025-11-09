/*
** EPITECH PROJECT, 2025
** mini_my_printf
** File description:
** min_my_printf
*/
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "../../include/my_struct.h"
#include "../../include/my.h"

const mini_my_printf_t all_func[] = {
    {"i", my_printf_i}, {"d", my_printf_i},
    {"c", my_printf_c}, {"s", my_printf_s},
    {"%", my_printf_pourcent}, {"u", my_printf_u},
    {"f", my_printf_fl}, {"o", my_printf_o},
    {"p", my_printf_pointer}, {"x", my_printf_x},
    {"X", my_printf_majx}, {"#", guess_format},
    {"e", my_print_e}, {"E", my_printf_maje},
    {"b", my_printf_b}, {" ", my_printf_espace},
    {"F", my_printf_majfl}, {"+", my_printf_plus},
    {"0", my_printf_zero}, {".", my_printf_point},
    {"hhd", my_printf_hhd}, {"hho", my_printf_hho},
    {"hhu", my_printf_hhu}, {"hhx", my_printf_hhx},
    {"hd", my_printf_hd}, {"ho", my_printf_ho},
    {"hx", my_printf_hx}, {"hu", my_printf_hu},
    {"hhX", my_printf_hhmajx}, {"-", my_printf_less},
    {"ld", my_printf_ld}, {"lX", my_printf_lmajx},
    {"lo", my_printf_lo}, {"lu", my_printf_lu},
    {"lx", my_printf_lx}, {"hX", my_printf_hmajx},
    {"lld", my_printf_lld}, {"llX", my_printf_llmajx},
    {"llo", my_printf_llo}, {"llu", my_printf_llu},
    {"llx", my_printf_llx}, {"hi", my_printf_hd},
    {"li", my_printf_ld}, {"lli", my_printf_lld},
    {"hhi", my_printf_hhd}
};

int my_strcomp(const char *all, const char *p)
{
    int i = 0;
    int count = 0;

    for (i = 0; all[i] != '\0'; i++) {
        if (all[i] == *p) {
            p++;
            count++;
        }
    }
    if (count == my_strlen(all)) {
        return 1;
    }
    return 0;
}

int guess_format(va_list args, const char *p)
{
    unsigned long i;

    p++;
    for (i = 0; i < sizeof(all_func) / sizeof(all_func[0]); i++) {
        if (my_strcomp(all_func[i].key, p) == 1) {
            all_func[i].func(args, p);
            return 2;
        }
    }
    return 0;
}

int get_flags(va_list args, const char *p)
{
    unsigned long i;
    int is_format = 0;
    int len = 0;

    for (i = 0; i < sizeof(all_func) / sizeof(all_func[0]); i++) {
        if (my_strcomp(all_func[i].key, p) == 1) {
            is_format = all_func[i].func(args, p);
        }
    }
    return is_format;
}

int my_printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    int take = 0;

    va_start(args, format);
    for (const char *p = format; *p != '\0'; p++) {
        if (*p == '%') {
            p++;
            take = get_flags(args, p);
            p += take - 1;
        } else {
            count++;
            my_putchar(*p);
        }
    }
    va_end(args);
    return count;
}
