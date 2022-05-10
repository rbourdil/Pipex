NAME = pipex

OBJS = pipex.o path.o io_pipe.o free.o error.o

HEAD = pipex.h

SUBDIRS = libft

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all:		$(SUBDIRS) $(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) -Llibft -lft -o $(NAME)

$(SUBDIRS):
			make -C $@	

$(OBJS):	%.o:%.c $(HEAD)
			$(CC) $(CFLAGS) -Ilibft -c $< -o $@

clean:		
			rm -f $(OBJS)
			make clean -C libft

fclean:			
			rm -f $(OBJS)
			rm -f $(NAME)
			make fclean -C libft
				

re:			fclean all

.PHONY: all clean fclean re $(SUBDIRS)
