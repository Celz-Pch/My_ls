##
## EPITECH PROJECT, 2025
## makefile for printf
## File description:
## makefile for printf project 2025 epitech
##

NAME	= ls

RM	= rm -f

OBJ	= $(SRC:.c=.o)

TEST_NAME = my_ls

all: $(NAME)

$(NAME):
	make -C ./lib/my
	epiclang src/my_ls.c src/special_ls/my_ls_with_folder.c src/flags/flags_l.c src/flags/flags_d.c src/flags/flags_r.c -o $(TEST_NAME) -I./include -L./lib/my -lmy

compile: 
	epiclang src/my_ls.c -o $(TEST_NAME) -I./include -L./lib/my -lmy
	
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) units_test
	$(RM) *.gcda *.gcno

re: fclean all