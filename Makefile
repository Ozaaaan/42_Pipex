NAME = pipex

LIBFT = Libft/libft.a

SRCS =	pipex.c \
	pipex_utils.c \

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf
	
all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(OBJS) -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C Libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)
	make clean -C Libft

fclean : clean
	$(RM) $(NAME)
	make fclean -C Libft

re : fclean all

.PHONY: all, clean, fclean, re, bonus
