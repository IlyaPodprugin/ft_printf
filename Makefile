NAME = libftprintf.a
CC = cc
HEADER = ./includes/ft_printf.h
CFLAGS = -Wall -Wextra -Werror -MMD
DIR_SRC = srcs
SRC_FILES = ft_printf.c ft_print_str.c \
			ft_print_char.c ft_print_ptr.c \
			ft_print_digit.c ft_print_hex.c \
			ft_print_uint.c print_digit.c
OBJ_FILES = $(addprefix $(DIR_SRC)/,$(patsubst %.c,%.o,$(SRC_FILES)))
D_FILES = $(addprefix $(DIR_SRC)/,$(patsubst %.c,%.d,$(SRC_FILES)))

all: $(NAME)

$(NAME): $(OBJ_FILES) $(HEADER)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar -crs $(NAME) $?

%.o : %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@ -MD

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ_FILES) $(D_FILES)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re libft

-include $(D_FILES)