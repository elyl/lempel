NAME=	lzw
SRC=	main.c 		\
	encode.c 	\
	decode.c	\
	init_list.c	\
	free_list.c 	\
	print_list.c 	\
	add_to_list.c	\
	get_from_list.c \
	get_from_code.c 

OBJ= 	$(SRC:.c=.o)
CC=	gcc
CFLAGS=	-W -Wall -g


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o ../$(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) ../$(NAME)

re: fclean clean $(NAME)