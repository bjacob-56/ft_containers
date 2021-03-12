SRCS =	srcs/main.cpp

INC =	includes/List.hpp includes/Iterator.hpp

NAME = test

CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

all:	$(NAME)

$(NAME):	$(SRCS) $(INC)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo "----- \033[32m $@ created\033[0m  -----"

clean:
	rm -f $(NAME)

fclean: 	clean

re:		fclean all

.PHONY: all clean fclean re