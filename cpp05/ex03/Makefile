NAME = ex03

SRC =	main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp\
		RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SHRUBBERY_FILE = home

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "🥣 .o was MADE."
	$(CPP) $(CPPFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f $(SHRUBBERY_FILE)_shrubbery
	@echo "🗑 .o is REMOVED."

fclean:
	@rm -f $(OBJ) $(NAME)
	@rm -f $(SHRUBBERY_FILE)_shrubbery
	@echo "🧽 All CLEAN."

re: fclean all
