#include "Form.hpp"
#include <iomanip>

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}

Form::Form() 
    : _name("Default Form"), _isSigned(false), _gradeToSigned(150), _gradeToExecute(150) {
    checkGrade(this->_gradeToSigned);
    checkGrade(this->_gradeToExecute);
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSigned(gradeToSign), _gradeToExecute(gradeToExecute) {
    checkGrade(this->_gradeToSigned);
    checkGrade(this->_gradeToExecute);
}

Form::Form(const Form &other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSigned(other._gradeToSigned), _gradeToExecute(other._gradeToExecute) {
}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form() {}

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

void Form::checkGrade(int grade) const {
    if (grade < 1)
       { throw GradeTooHighException();}
    else if (grade > 150) {
        throw GradeTooLowException();
}
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (this->_isSigned) {
        std::cout << this->_name << " is already signed.\n";
        return;
    }
    std::cout << "Attempting to sign form: " << this->_name << "\n";
    std::cout << "-----------------------------------\n";
    std::cout << "Required grade to sign: " << this->_gradeToSigned << "\n";
    std::cout << "Bureaucrat grade:       " << bureaucrat.getGrade() << "\n";
    std::cout << "-----------------------------------\n";
    if (bureaucrat.getGrade() > this->_gradeToSigned) {
        throw GradeTooLowException();
    }
    this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
    const int labelWidth = 30;

    out << std::left;
    out << std::setw(labelWidth) << "Form:" << form.getName() << "\n";
    out << std::setw(labelWidth) << "signed:" << (form.isSigned() ? "Yes" : "No") << "\n";
    out << std::setw(labelWidth) << "grade required to sign:" << form.getGradeToSign() << "\n";
    out << std::setw(labelWidth) << "grade required to execute:" << form.getGradeToExecute() << "\n";

    return out;
}