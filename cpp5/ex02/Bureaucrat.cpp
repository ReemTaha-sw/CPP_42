#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat constructor called!\n";
}

Bureaucrat::~Bureaucrat()
{
	std::cout << this->_name << " Bureaucrat destructor called!\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj._name), _grade(obj._grade)
{
	checkGrade(this->_grade);
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
    checkGrade(grade);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!\n";
}

void Bureaucrat::checkGrade(int grade) const {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

const std::string &Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::incrementGrade() {
    checkGrade(this->_grade - 1);
    this->_grade--;
}

void Bureaucrat::decrementGrade() {
    checkGrade(this->_grade + 1);
    this->_grade++;
}

void Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->_name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) const {
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &error) {
        std::cout << _name << " couldn't execute " << form.getName()
                  << " because " << error.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "\n";
	return out;
}