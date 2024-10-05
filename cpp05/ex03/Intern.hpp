#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(Intern &copy);
		Intern &operator=(Intern &other);

		AForm* makeForm(const std::string &formName, const std::string &target) const;
		class UnknownFormException : public std::exception {
			public : virtual const char* what() const throw();
		};

	private:
		static AForm* createShrubbery(const std::string& target);
		static AForm* createRobotomy(const std::string& target);
		static AForm* createPresidentialPardon(const std::string& target);
};

#endif
