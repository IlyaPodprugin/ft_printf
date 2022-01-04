NAME = libftprintf.a
CC = cc
HEADER = ./includes/ft_printf.h
CFLAGS = -Wall -Wextra -Werror -MMD
SRC_FILES = ./srcs/ft_printf.c
OBJ_FILES = $(patsubst %.c,%.o,$(SRC_FILES))
D_FILES = $(patsubst %.c,%.d,$(SRC_FILES))

all: $(NAME)

$(NAME): $(OBJ_FILES) $(HEADER)
	$(MAKE) -C ./libft
	ar -crs $(NAME) $?

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -MD

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ_FILES) $(D_FILES)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re libft

-include $(D_FILES)