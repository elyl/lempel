NAME=	lzw
SRC=	main.c 		\
	encode.c 	\
	decode.c	\
	init_enc.c	\
	search_str.c	\
	add_str.c	\
	write_bits.c

OBJ= 	$(SRC:.c=.o)
CC=	gcc
CFLAGS=	-W -Wall -g
RM=	@rm -fv

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re: fclean clean $(NAME)