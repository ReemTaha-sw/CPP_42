#include "ShrubberyCreationForm.hpp"
#include "fstream"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
	// std::cout << "ShrubberyCreationForm constructor called!\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "ShrubberyCreationForm destructor called!\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
    : AForm(copy), _target(copy._target) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	AForm::operator=(obj);
    if (this != &obj) {
        this->_target = obj._target;
    }
	return *this;
}

void ShrubberyCreationForm::executeAction() const {
    std::ofstream ofs((_target + "_shrubbery").c_str());
    if (!ofs) {
        std::cerr << "Failed to open file: " << _target + "_shrubbery" << std::endl;
        return;
    }
    ofs << "       _-_" << std::endl;
    ofs << "    /~~   ~~\\" << std::endl;
    ofs << " /~~         ~~\\" << std::endl;
    ofs << "{               }" << std::endl;
    ofs << " \\  _-     -_  /" << std::endl;
    ofs << "   ~  \\\\ //  ~" << std::endl;
    ofs << "_- -   | | _- _" << std::endl;
    ofs << "  _ -  | |   -_" << std::endl;
    ofs << "      // \\\\" << std::endl;
    ofs.close();
	std::cout << "Shrubbery has been created in " << _target + "_shrubbery" << std::endl;

}
