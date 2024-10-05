#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default")
{
	// std::cout << "PresidentialPardonForm constructor called!\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "PresidentialPardonForm destructor called!\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj), _target(obj._target)
{
	// *this = obj;
}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	AForm::operator=(obj);
	if (this != &obj)
		this->_target = obj._target;
	return *this;
}

void PresidentialPardonForm::executeAction() const {
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox.\n";
}
