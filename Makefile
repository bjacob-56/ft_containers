SRCS =	srcs/main.cpp srcs/utils_main.cpp
SRCS_BIS =	srcs/main_bis.cpp srcs/utils_main.cpp
SRCS_TEST =	srcs/mainList.cpp srcs/utils_main.cpp

INC =	includes/List.hpp includes/Iterator.hpp srcs/utils_main.hpp

NAME = main
NAME_BIS = bis
TEST = test

CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address
# CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

all:	$(TEST)

$(NAME):	$(SRCS) $(INC)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo "----- \033[32m $@ created\033[0m  -----"

$(NAME_BIS):	$(SRCS_BIS) $(INC)
	$(CC) $(CFLAGS) $(SRCS_BIS) -o $(NAME_BIS)
	@echo "----- \033[32m $@ created\033[0m  -----"

$(TEST):	$(SRCS_TEST) $(INC)
	$(CC) $(CFLAGS) $(SRCS_TEST) -o $(TEST)
	@echo "----- \033[32m $@ created\033[0m  -----"
	@./$(TEST)

clean:
	rm -f $(NAME)
	rm -f $(NAME_BIS)
	rm -f $(TEST)

fclean: 	clean

re:		fclean all

.PHONY: all clean fclean re