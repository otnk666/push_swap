NAME	=	push_swap

SRCS_DIR	=	./srcs
CC	= cc
CFLG	= -Wall -Wextra -Werror           

INIT_DIR	= $(SRCS_DIR)/ft_initial
CMD_DIR		= $(SRCS_DIR)/ft_command
SORT_DIR	= $(SRCS_DIR)/ft_sort
STACK_DIR	= $(SRCS_DIR)/ft_stack
FINDM_DIR	= $(SRCS_DIR)/ft_findmed

MAIN_SRCS	= $(SRCS_DIR)/main.c \
			$(SRCS_DIR)/die.c

INIT_SRCS	= $(INIT_DIR)/ft_check_arg.c \
			$(INIT_DIR)/ft_check_sort.c \
			$(INIT_DIR)/init_stack.c \
			$(INIT_DIR)/init_strarg.c
				
CMD_SRCS	= $(CMD_DIR)/push.c \
			$(CMD_DIR)/rotate.c \
			$(CMD_DIR)/re_rotate.c \
			$(CMD_DIR)/swap.c

SORT_SRCS	= $(SORT_DIR)/sort.c \
			$(SORT_DIR)/sort_five.c \
			$(SORT_DIR)/quick_sort.c

STACK_SRCS	= $(STACK_DIR)/ft_stackadd_front.c \
			$(STACK_DIR)/ft_stackadd_back.c \
			$(STACK_DIR)/ft_stacknew.c \
			$(STACK_DIR)/ft_stacksize.c

FINDM_SRCS	= $(FINDM_DIR)/ft_findmed.c

SRCS	= $(MAIN_SRCS) $(INIT_SRCS) $(CMD_SRCS) $(SORT_SRCS) $(STACK_SRCS) $(FINDM_SRCS)
OBJS	= $(SRCS:.c=.o)

RM	= rm -f

INCLUDES	= -I./includes -I $(LIBFT_PATH)/includes

LIBFT_PATH	= ./libft
LIBFT_NAME	= libft.a


all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLG) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft

%.o: %.c
	$(CC) $(CFLG) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
