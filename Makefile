
SRCS= ft_dispatch.c ft_print_char.c \
	ft_print_hex_lower.c ft_print_hex_upper.c \
	ft_print_int.c ft_print_percent.c ft_print_ptr.c \
	ft_print_str.c ft_print_uint.c ft_printf_utils.c \
	ft_printf.c ft_walk.c

SRCS_BONUS = ./_bonus/ft_cheker_bonus.c  ./_bonus/ft_dispatch_bonus.c \
	./_bonus/ft_helpers_bonus.c  ./_bonus/ft_parser_bonus.c \
	./_bonus/ft_print_char_bonus.c  ./_bonus/ft_print_hex_bonus.c \
	./_bonus/ft_print_int_bonus.c  ./_bonus/ft_print_percent_bonus.c \
	./_bonus/ft_print_ptr_bonus.c  ./_bonus/ft_print_str_bonus.c \
	./_bonus/ft_print_uint_bonus.c  ./_bonus/ft_printf_bonus.c \
	./_bonus/ft_putnbr_base_bonus.c  ./_bonus/ft_utils_bonus.c \
	./_bonus/ft_walk_bonus.c

AR = ar rcs

CC = cc

OBJ_DIR		= obj

OBJ_BONUS_DIR	= obj_bonus

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

OBJS_BONUS = $(SRCS_BONUS:./_bonus/%.c=$(OBJ_BONUS_DIR)/%.o)

FLAGS= -Wall -Wextra -Werror

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	rm -f $(NAME)
	$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.c ft_printf.h
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)

fclean: clean
	rm -f $(NAME)

bonus : $(OBJS_BONUS)
	rm -f $(NAME)
	$(AR) $(NAME) $(OBJS_BONUS)

$(OBJ_BONUS_DIR)/%.o: ./_bonus/%.c ./_bonus/ft_printf_bonus.h
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

re: fclean all

.PHONY: clean fclean all re bonus
