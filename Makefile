CFLAGS = -Werror -Wall -Wextra

S_NAME = server

SRC = server.c\
		put_str.c\
		server_utils.c

OBJ = server.o\
		put_str.o\
		server_utils.o

C_NAME = client

C_SRC = client.c\
		put_str.c

C_OBJ = client.o\
		put_str.o


all : $(S_NAME) $(C_NAME)

$(S_NAME) : $(OBJ)
	@gcc $(CFLAGS) -o $(S_NAME) $(OBJ) 

$(C_NAME) : $(C_OBJ)
	@gcc $(CFLAGS) -o $(C_NAME) $(C_OBJ) 

%.o: %.c 
	@gcc $(CFLAGS) -c $<

clean :
	@echo "Removing object files ..."
	@rm -f $(OBJ)
	@rm -f $(C_OBJ)

fclean : clean
	@echo "Removing $(S_NAME) ..."
	@rm -f $(S_NAME)
	@rm -f $(C_NAME)

re : fclean all

.PHONY : clean fclean re all