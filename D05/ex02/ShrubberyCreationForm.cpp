#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) { }

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: Form("ShrubberyCreation", 145, 137) {
	this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src) { }

ShrubberyCreationForm::~ShrubberyCreationForm(void) { }

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	if (this != &rhs) {
		this->setTarget(rhs.getTarget());
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (this->getSigned() && executor.getGrade() <= this->getGradeForExec()) {
		std::fstream ifs;
		ifs.open(this->getTarget() + "_shrubbery", std::fstream::in | std::fstream::app);

		ifs << "                                              ." << std::endl;
		ifs << "                                   .         ;" << std::endl;
		ifs << "      .              .              ;%     ;;" << std::endl;
		ifs << "        ,           ,                :;%  %;" << std::endl;
		ifs << "         :         ;                   :;%;'     .," << std::endl;
		ifs << ",.        %;     %;            ;        %;'    ,;" << std::endl;
		ifs << " ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
		ifs << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl;
		ifs << "   ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
		ifs << "    `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
		ifs << "     `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
		ifs << "        `:%;.  :;bd%;          %;@%;'" << std::endl;
		ifs << "           `@%:.  :;%.         ;@@%;'" << std::endl;
		ifs << "             `@%.  `;@%.      ;@@%;" << std::endl;
		ifs << "               `@%%. `@%%    ;@@%;" << std::endl;
		ifs << "                 ;@%. :@%%  %@@%;" << std::endl;
		ifs << "                   %@bd%%%bd%%:;" << std::endl;
		ifs << "                     #@%%%%%:;;" << std::endl;
		ifs << "                     %@@%%%::;" << std::endl;
		ifs << "                     %@@@%(o);  . '" << std::endl;
		ifs << "                     %@@@o%;:(.,'" << std::endl;
		ifs << "                 `.. %@@@o%::;" << std::endl;
		ifs << "                    `)@@@o%::;" << std::endl;
		ifs << "                     %@@(o)::;" << std::endl;
		ifs << "                    .%@@@@%::;" << std::endl;
		ifs << "                    ;%@@@@%::;." << std::endl;
		ifs << "                   ;%@@@@%%:;;;." << std::endl;

		ifs.close();
	}
}
