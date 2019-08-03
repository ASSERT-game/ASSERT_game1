FLAGS = -Wall -Wextra -Werror -lncurses
INCLUDES = -I includes/
NAME  = game1

all: $(NAME)

$(NAME):
	@echo "\033[32m""Making your the game!"
	@gcc $(FLAGS) -o $(NAME) srcs/entry.c $(INCLUDES)
	@echo "\033[32m""Done!"

clean:
	rm -f entry.o

fclean:
	rm -f $(NAME)

re: fclean all

quick:
	@make fclean
	@make all
	@make clean
	@clear
