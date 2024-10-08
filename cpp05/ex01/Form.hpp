#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSigned;
		const int			_gradeToExecute;
		void				checkGrade(int grade) const;
	public:
		Form();
		~Form();
		Form(const Form &copy);
		Form(const std::string &name, int gradeToSign, int gradeToExecute);
		Form &operator=(const Form &other);

		const std::string	&getName() const;
		bool				isSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(const Bureaucrat &bureaucrat);
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &Form);

#endif
