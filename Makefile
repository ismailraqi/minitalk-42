CFLAGS = -Werror -Wall -Wextra

NAME = server

SRC = server.c\
		put_str.c

OBJ = server.o\
		put_str.o



all : $(NAME)

$(NAME) : $(OBJ)
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) 

%.o: %.c 
	@gcc $(CFLAGS) -c $<

clean :
	@echo "Removing object files ..."
	@rm -f $(OBJ)

fclean : clean
	@echo "Removing $(NAME) ..."
	@rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all