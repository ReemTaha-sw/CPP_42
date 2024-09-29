NAME = harl

SRC = main.cpp\
		Harl.cpp

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "🥣 .o was MADE."
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo "🗑 .o is REMOVED."

fclean:
	@rm -f $(OBJ) $(NAME)
	@echo "🧽 All CLEAN."

re: fclean all

.PHONY: all clean fclean re