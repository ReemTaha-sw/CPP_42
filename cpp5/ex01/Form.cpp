#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}

// Constructor
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSigned(gradeToSign), _gradeToExecute(gradeToExecute) {
    checkGrade(this->_gradeToSigned);
    checkGrade(this->_gradeToExecute);
}

// Copy constructor
Form::Form(const Form &other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSigned(other._gradeToSigned), _gradeToExecute(other._gradeToExecute) {
}

// Assignment operator
Form &Form::operator=(const Form &other) {
    if (this != &other) {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

// Destructor
Form::~Form() {}

// Getters
const std::string &Form::getName() const {
    return this->_name;
}

bool Form::isSigned() const {
    return this->_isSigned;
}

int Form::getGradeToSign() const {
    return this->_gradeToSigned;
}

int Form::getGradeToExecute() const {
    return this->_gradeToExecute;
}

// Check if grade is valid
void Form::checkGrade(int grade) const {
    if (grade < 1)
       { throw GradeTooHighException();}
    else if (grade > 150) {
        throw GradeTooLowException();
}
}

// Be signed by a bureaucrat
void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSigned) {
        throw GradeTooLowException();
    }
    this->_isSigned = true;
}

// Overload << operator
std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << "Form: " << form.getName() << ", signed: " << (form.isSigned() ? "Yes" : "No")
        << ", grade required to sign: " << form.getGradeToSign()
        << ", grade required to execute: " << form.getGradeToExecute();
    return out;
}