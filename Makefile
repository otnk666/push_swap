NAME	= push_swap
SRCS	= main.c \
		sort.c \
		command.c \
		quick_sort.c \
		error_checker.c

OBJS	= $(SRCS:.c=.o)
CC	= cc
CFLG	= -Wall -Wextra -Werror -g
RM	= rm -f

INCLUDES	= -I./includes -I $(LIBFT_PATH) -I $(FT_PRINTF_PATH)

LIBFT_PATH	= ./libft
LIBFT_NAME	= libft.a

FT_PRINTF_PATH	= ./ft_printf
FT_PRINTF_NAME	= libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH)
	@$(MAKE) -C $(FT_PRINTF_PATH)
	@$(CC) $(CFLG) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft -L$(FT_PRINTF_PATH) -lftprintf

%.o: %.c
	@$(CC) $(CFLG) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(FT_PRINTF_PATH) clean
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(FT_PRINTF_PATH) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
