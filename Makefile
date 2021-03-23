SRCS_TEST = srcs/testList.cpp srcs/testVector.cpp srcs/testMap.cpp srcs/testQueue.cpp srcs/testStack.cpp
SRCS =	srcs/main.cpp srcs/utils_main.cpp $(SRCS_TEST)

INC =	includes/Iterator.hpp includes/List.hpp includes/Vector.hpp includes/Map.hpp includes/Queue.hpp includes/Stack.hpp srcs/utils_main.hpp

NAME = main

CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address
# CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

all:	$(NAME)

$(NAME):	$(SRCS) $(INC)
	clear
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo "----- \033[32m $@ created\033[0m  -----"
	@./$(NAME)

clean:
	rm -f $(NAME)

fclean: 	clean

re:		fclean all

.PHONY: all clean fclean re