NAME=	climpel
SRC=	main.c
OBJ= 	$(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o ../$(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) ../$(NAME)

re: fclean clean $(NAME)