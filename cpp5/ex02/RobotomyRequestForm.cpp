#include "RobotomyRequestForm.hpp"
#include <cstdlib> // rand, srand
#include <ctime> // time

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
	// std::cout << "RobotomyRequestForm constructor called!\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "RobotomyRequestForm destructor called!\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{

}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj), _target(obj._target)
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm &obj)
{
	AForm::operator=(obj);
	if (this != &obj)
	{
		this->_target = obj._target;
	}
	return *this;
}

void RobotomyRequestForm::executeAction() const {
	std::cout << "... Drilling noises...\n";
	srand(time(NULL));
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully!\n";
	else
		std::cout << "Robotomy failed on " << this->_target << "\n";
}