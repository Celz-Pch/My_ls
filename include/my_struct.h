/*
** EPITECH PROJECT, 2025
** h file for struct
** File description:
** this file stock the struct
*/

#include <stdarg.h>

#ifndef MY_STRUCT
    #define MY_STRUCT

typedef struct flags_bool {
    char flags;
    int is_here;
} flags_bool_t;

typedef struct mini_my_printf {
    char *key;
    int (*func)(va_list args, const char *format);
} mini_my_printf_t;

typedef struct my_printf_p {
    char *symbols;
    int length;
} base_t;

#endif
