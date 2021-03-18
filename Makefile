SRCS =	srcs/main.cpp
SRCS_BIS =	srcs/main_bis.cpp

INC =	includes/List.hpp includes/Iterator.hpp

NAME = test
NAME_BIS = bis

CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address
# CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

all:	$(NAME)

$(NAME):	$(SRCS) $(INC)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo "----- \033[32m $@ created\033[0m  -----"

$(NAME_BIS):	$(SRCS_BIS) $(INC)
	$(CC) $(CFLAGS) $(SRCS_BIS) -o $(NAME_BIS)
	@echo "----- \033[32m $@ created\033[0m  -----"

clean:
	rm -f $(NAME)

fclean: 	clean

re:		fclean all

.PHONY: all clean fclean re