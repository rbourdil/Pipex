NAME = pipex

OBJS = pipex.o io_pipe.o

HEAD = pipex.h

LIBS = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

FILES = infile outfile

all:		$(NAME) $(FILES)

$(FILES):
			touch $(FILES)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(LIBS) -o $(NAME)

$(OBJS):	%.o:%.c $(HEAD)
			$(CC) $(FLAGS) -c $< -o $@

clean:
			rm -f $(OBJS) $(FILES)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re
