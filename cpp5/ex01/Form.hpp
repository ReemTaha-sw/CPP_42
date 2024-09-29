#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

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
		Form(Form &copy);
		Form(const std::string &name, int gradeToSign, int gradeToExecute);
		Form &operator=(Form &other);

		const std::string &getName() const;
		bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		// Be signed by a bureaucrat
		void beSigned(const Bureaucrat &bureaucrat);

		// exception classes
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif