NAME	=	push_swap

SRCS_DIR	=	./srcs
CMD_DIR		= $(SRCS_DIR)/ft_command
SORT_DIR	= $(SRCS_DIR)/ft_sort
STACK_DIR	= $(SRCS_DIR)/ft_stack
FINDM_DIR	= $(SRCS_DIR)/ft_findmed

MAIN_SRCS	=	$(SRCS_DIR)/main.c \
				$(SRCS_DIR)/die.c \
				$(SRCS_DIR)/ft_check_arg.c \
				$(SRCS_DIR)/ft_check_sort.c \
				$(SRCS_DIR)/init_stack.c \
				
CMD_SRCS	=	$(CMD_DIR)/command.c

SORT_SRCS	=	$(SORT_DIR)/sort.c \
				$(SORT_DIR)/quick_sort.c \
				$(SORT_DIR)/rotate_utils.c \

STACK_SRCS	=	$(STACK_DIR)/ft_stackadd_front.c \
				$(STACK_DIR)/ft_stackadd_back.c \
				$(STACK_DIR)/ft_stacknew.c \
				$(STACK_DIR)/ft_stacksize.c \

FINDM_SRCS	=	$(FINDM_DIR)/ft_findmed.c \

SRCS	= $(MAIN_SRCS) $(CMD_SRCS) $(SORT_SRCS) $(STACK_SRCS) $(FINDM_SRCS)
OBJS	= $(SRCS:.c=.o)
CC	= cc
CFLG	= -Wall -Wextra -Werror -g -I./includes -fsanitize=address
RM	= rm -f

INCLUDES	= -I./includes -I $(LIBFT_PATH)/includes

LIBFT_PATH	= ./libft
LIBFT_NAME	= libft.a


all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH)
	@$(CC) $(CFLG) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft -L$(FT_PRINTF_PATH) -lftprintf

%.o: %.c
	@$(CC) $(CFLG) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
