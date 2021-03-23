SRCS =	srcs/main.cpp srcs/utils_main.cpp
SRCS_BIS =	srcs/main_bis.cpp srcs/utils_main.cpp
SRCS_LIST =	srcs/mainList.cpp srcs/utils_main.cpp
SRCS_VECTOR =	srcs/mainVector.cpp
SRCS_MAP =	srcs/mainMap.cpp

INC =	includes/Iterator.hpp includes/List.hpp includes/Vector.hpp includes/Map.hpp srcs/utils_main.hpp

NAME = main
NAME_BIS = bis
LIST = test_list
VECTOR = test_vector
MAP = test_map

CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address
# CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

all:	$(MAP)

$(NAME):	$(SRCS) $(INC)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo "----- \033[32m $@ created\033[0m  -----"

$(NAME_BIS):	$(SRCS_BIS) $(INC)
	$(CC) $(CFLAGS) $(SRCS_BIS) -o $(NAME_BIS)
	@echo "----- \033[32m $@ created\033[0m  -----"

$(LIST):	$(SRCS_LIST) $(INC)
	clear
	$(CC) $(CFLAGS) $(SRCS_LIST) -o $(LIST)
	@echo "----- \033[32m $@ created\033[0m  -----"
	@./$(LIST) 2

$(VECTOR):	$(SRCS_VECTOR) $(INC)
	clear
	$(CC) $(CFLAGS) $(SRCS_VECTOR) -o $(VECTOR)
	@echo "----- \033[32m $@ created\033[0m  -----"
	@./$(VECTOR) 2

$(MAP):	$(SRCS_MAP) $(INC)
	clear
	$(CC) $(CFLAGS) $(SRCS_MAP) -o $(MAP)
	@echo "----- \033[32m $@ created\033[0m  -----"
	@./$(MAP) 2

clean:
	rm -f $(NAME)
	rm -f $(NAME_BIS)
	rm -f $(LIST)
	rm -f $(VECTOR)
	rm -f $(MAP)

fclean: 	clean

re:		fclean all

.PHONY: all clean fclean re