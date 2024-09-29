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
    : name(other.name), is_signed(other.is_signed),
      grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute) {
}

// Assignment operator
Form &Form::operator=(const Form &other) {
    if (this != &other) {
        this->is_signed = other.is_signed;
    }
    return *this;
}

// Destructor
Form::~Form() {}

// Getters
const std::string &Form::getName() const {
    return name;
}

bool Form::isSigned() const {
    return is_signed;
}

int Form::getGradeToSign() const {
    return grade_to_sign;
}

int Form::getGradeToExecute() const {
    return grade_to_execute;
}

// Check if grade is valid
void Form::checkGrade(int grade) const {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

// Be signed by a bureaucrat
void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > grade_to_sign) {
        throw GradeTooLowException();
    }
    is_signed = true;
}

// Overload << operator
std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << "Form: " << form.getName() << ", signed: " << (form.isSigned() ? "Yes" : "No")
        << ", grade required to sign: " << form.getGradeToSign()
        << ", grade required to execute: " << form.getGradeToExecute();
    return out;
}