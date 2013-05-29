export CC=	gcc
export CFLAGS=	-W -Wall -g
export RM=	@rm -vf
CDIR=		compression
DDIR=		decompression

climpel:
	@(cd $(CDIR) && $(MAKE))

clean:
	@(cd $(CDIR) && $(MAKE) $@)

fclean:
	@(cd $(CDIR) && $(MAKE) $@)

re: clean fclean $(NAME)