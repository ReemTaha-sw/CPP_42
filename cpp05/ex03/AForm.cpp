#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm grade is too low!";
}

const char* AForm::NotSignedException::what() const throw() {
    return "AForm is not signed!";
}

// Default Constructor
AForm::AForm()
    : _name("Default AForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
    checkGrade(_gradeToSign);
    checkGrade(_gradeToExecute);
}

// Parameterized Constructor
AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    checkGrade(_gradeToSign);
    checkGrade(_gradeToExecute);
}

// Copy Constructor
AForm::AForm(const AForm &other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    // Nothing else to do
}

// Assignment Operator
AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        // _name, _gradeToSign, and _gradeToExecute are const and cannot be assigned
        this->_isSigned = other._isSigned;
    }
    return *this;
}

// Destructor
AForm::~AForm() {}

// Getters
const std::string &AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _isSigned;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

// Grade Validation
void AForm::checkGrade(int grade) const {
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
}

// beSigned Function
void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

// execute Function
void AForm::execute(Bureaucrat const &executor) const {
    if (!_isSigned)
        throw NotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
    executeAction();
}

// Overload << operator
std::ostream &operator<<(std::ostream &out, const AForm &form) {
    out << "Form: " << form.getName()
        << ", Signed: " << (form.isSigned() ? "Yes" : "No")
        << ", Grade Required to Sign: " << form.getGradeToSign()
        << ", Grade Required to Execute: " << form.getGradeToExecute();
    return out;
}