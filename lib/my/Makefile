##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile for libmy.a
##

SRC = \
 basic_format/my_printf_espace.c \
 basic_format/my_printf_less.c \
 basic_format/my_printf_plus.c \
 basic_format/my_printf_zero.c \
 basic_format/my_printf_point.c \
 flags_file/b_flags.c \
 flags_file/basic_flags.c \
 flags_file/e_flags.c \
 flags_file/f_flags.c \
 flags_file/maje_flags.c \
 flags_file/majx_flags.c \
 flags_file/o_flags.c \
 flags_file/p_flags.c \
 flags_file/u_flags.c \
 flags_file/x_flags.c \
 hh_len_files/my_printf_hhd.c \
 hh_len_files/my_printf_hhmajx.c \
 hh_len_files/my_printf_hho.c \
 hh_len_files/my_printf_hhu.c \
 hh_len_files/my_printf_hhx.c \
 l_len_files/my_printf_ld.c \
 l_len_files/my_printf_lmajx.c \
 l_len_files/my_printf_lo.c \
 l_len_files/my_printf_lu.c \
 l_len_files/my_printf_lx.c \
 len_files/my_printf_hd.c \
 len_files/my_printf_hmajx.c \
 len_files/my_printf_ho.c \
 len_files/my_printf_hu.c \
 len_files/my_printf_hx.c \
 my_getnbr.c \
 my_printf.c \
 my_put_nbr.c \
 my_putchar.c \
 my_putstr.c \
 my_strcmp.c \
 my_strlen.c \
 sort_word_array.c \
 get_nb_file.c \
 choose_ls.c \
 t_sort.c \
 my_strdup.c \
 my_printf_ls.c \
 my_strcat.c \
 my_strcpy.c \
 ll_len_files/my_printf_lld.c \
 ll_len_files/my_printf_llmajx.c \
 ll_len_files/my_printf_llo.c \
 ll_len_files/my_printf_llu.c \
 ll_len_files/my_printf_llx.c \

OBJ = $(SRC:.c=.o)
NAMELIB = libmy.a
CC = epiclang

all: $(NAMELIB)

$(NAMELIB): $(OBJ)
	ar rc $(NAMELIB) $(OBJ)
	make clean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAMELIB)
	rm -f ../../$(NAMELIB)

re: fclean all
