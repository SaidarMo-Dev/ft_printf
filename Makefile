FLAGS= -Wall -Wextra -Werror

SRCS= ft_dispatch.c ft_print_char.c \
	ft_print_hex_lower.c ft_print_hex_upper.c \
	ft_print_int.c ft_print_percent.c ft_print_ptr.c \
	ft_print_str.c ft_print_uint.c ft_printf_utils.c \
	ft_printf.c ft_walk.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	cc $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all