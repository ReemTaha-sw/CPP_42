NAME = RPN

SRC =	main.cpp RPN.cpp

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "🥣 .o was MADE."
	$(CPP) $(CPPFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo "🗑 .o is REMOVED."

fclean:
	@rm -f $(OBJ) $(NAME)
	@echo "🧽 All CLEAN."

re: fclean all
