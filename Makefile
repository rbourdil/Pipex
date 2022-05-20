NAME = pipex

OBJS = pipex.o child.o path.o free.o error.o

HEADS = pipex.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

SUBDIRS = libft gnl

all:		$(SUBDIRS) $(NAME)

$(SUBDIRS):	
			make -C $@

$(NAME):	$(OBJS)
			$(CC) $(OBJS) -Llibft -lft -Lgnl -lgnl -o $(NAME)

$(OBJS):	%.o:%.c $(HEADS)
			$(CC) $(CFLAGS) -Ilibft -Ignl -c $< -o $@

clean:		
			rm -f $(OBJS)
			make clean -C libft
			make clean -C gnl

fclean:		
			rm -f $(OBJS) $(NAME)
			make fclean -C libft
			make fclean -C gnl

re:			fclean all

.PHONY: all clean fclean re $(SUBDIRS)
