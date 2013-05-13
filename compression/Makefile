NAME=	clempel
SRC=	main.c 		\
	clempel.c 	\
	free_list.c 	\
	print_list.c 	\
	add_to_list.c	\
	get_from_list.c
OBJ= 	$(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o ../$(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) ../$(NAME)

re: fclean clean $(NAME)