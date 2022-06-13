CFLAGS = -Werror -Wall -Wextra

S_NAME = server

SRC = server.c\
		printing_utils.c\
		server_utils.c\
		queue_utils.c

OBJ = server.o\
		printing_utils.o\
		server_utils.o\
		queue_utils.o

C_NAME = client

C_SRC = client.c\
		printing_utils.c

C_OBJ = client.o\
		printing_utils.o


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