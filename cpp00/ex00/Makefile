NAME = megaphone

SRC = megaphone.cpp

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo "🧹 .o removed."

fclean:
	@rm -f $(OBJ) $(NAME)
	@echo "🧻 All removed."

re: fclean all

.PHONY: all clean fclean re