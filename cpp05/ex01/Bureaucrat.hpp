#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		void				checkGrade(int grade) const;

	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat &operator=(const Bureaucrat &other);
		// getters
		const std::string	&getName() const;
		int					getGrade() const;
		// ++/--
		void				incrementGrade();
		void				decrementGrade();
		// Form
		void signForm(Form &form);
		
		// exceptions classes
		class	GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
