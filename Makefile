FLAGS = -Wall -Wextra -Werror -lncurses
INCLUDES = -I includes/
NAME  = beta_game1

SRCS = \
		srcs/assets/assets					\
		srcs/entities/enemy_01_projectile	\
		srcs/entities/enemy_01				\
		srcs/entities/enemy_02				\
		srcs/entities/spaceship_projectile	\
		srcs/entities/spaceship				\
		srcs/exit/entry_exit				\
		srcs/levels/level_01				\
		srcs/levels/level_common			\
		srcs/levels/level_utils				\
		srcs/main_menu/entry_main_menu		\
		srcs/transition/transition			\
		srcs/entry							\
		srcs/preperation					\
		srcs/render							\


FILES = $(addsuffix .c, $(SRCS))

all: $(NAME)

$(NAME):
	@echo "\033[32m""Making your the game!"
	@gcc $(FLAGS) -o $(NAME) $(FILES) $(INCLUDES)
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

quicker:
	@make quick
	./$(NAME)

		# srcs/levels/level_spawners			\
		# srcs/levels/level_entity_update		\
