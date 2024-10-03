#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor called!\n";
}

Intern::~Intern()
{
	std::cout << "Intern destructor called!\n";
}

Intern::Intern(Intern &obj)
{
	*this = obj;
}

Intern& Intern::operator=(Intern &obj)
{
	(void)obj;
	return *this;
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const
{
	std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*formCreationFunctions[3])(const std::string&) = {
		&Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidentialPardon
	};
	for (int i = 0; i < 3; i++)
	{
		if (formName == formTypes[i])
		{
			std::cout << "Intern creates " << formTypes[i] << "\n";
			return formCreationFunctions[i](target);
		}
	}
	throw UnknownFormException();
}

const char* Intern::UnknownFormException::what() const throw()
{
	return "Unknown form type requested!";
}

AForm* Intern::createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}