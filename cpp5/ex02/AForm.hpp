#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;
        void                checkGrade(int grade) const;

    protected:
        virtual void executeAction() const = 0;

    public:
        AForm();
        AForm(const AForm &copy);
        AForm(const std::string &name, int gradeToSign, int gradeToExecute);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        // Getters
        const std::string   &getName() const;
        bool                isSigned() const;
        int                 getGradeToSign() const;
        int                 getGradeToExecute() const;

        // Member Functions
        void beSigned(const Bureaucrat &bureaucrat);
        void execute(Bureaucrat const &executor) const;

        // Exception classes
        class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
        };
        class NotSignedException : public std::exception {
        public:
            virtual const char* what() const throw();
        };
};

// Overload << operator for AForm
std::ostream &operator<<(std::ostream &out, const AForm &form);
#endif
