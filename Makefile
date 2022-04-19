NAME = pipex

OBJS = pipex.o io_pipe.o

HEAD = pipex.h

LIBS = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(LIBS) -o $(NAME)

$(OBJS):	%.o:%.c
			$(CC) $(FLAGS) -c $< -o $@

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re
