
NAME = push_swap
BONUS	=	checker

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = push_swap.c \
	parsing.c \
	operation.c \
	method.c \
	sorting.c \
	sorting_small.c \
	utils.c 
	
INCS = push_swap.h
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = checker.c \
	method_bonus.c \
	get_next_line.c \
	parsing.c \
	operation.c \
	method.c \
	sorting.c \
	sorting_small.c \
	utils.c 

BONUS_INCS =	checker.h
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all : $(NAME)

bonus	:	$(BONUS)

$(NAME) : $(OBJS) $(INCS)
			make -C libft
			$(CC) $(CFLAGS) -L ./libft -lft $(OBJS) -o $@

$(BONUS) : $(BONUS_OBJS) $(BONUS_INCS)
			make -C libft
			$(CC) $(CFLAGS) -L ./libft -lft $(BONUS_OBJS) -o $@

%.o :%.c $(INCS)
		$(CC) $(CFLAGS) -c $< -o $@

clean :
		rm -rf $(OBJS)
		rm -rf $(BONUS_OBJS)
		make clean -C libft

fclean : clean
		rm -rf $(NAME)
		rm -rf $(BONUS)
		make fclean -C libft

re : fclean all

.PHONY: all clean fclean re bonus
