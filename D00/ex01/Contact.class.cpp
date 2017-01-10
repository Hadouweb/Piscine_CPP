#include "Contact.class.hpp"

Contact::Contact(void) {
    Contact::_nbInstance += 1;
    this->_id = Contact::_nbInstance;
    return;
}

Contact::~Contact(void) {
    Contact::_nbInstance -= 1;
    return;
}

void Contact::Add(void)
{
    std::cout << "First name : ";
	getline (std::cin, this->_firstName);

    std::cout << "Last name : ";
	getline (std::cin, this->_lastName);

    std::cout << "Nickname : ";
	getline (std::cin, this->_nickName);

    std::cout << "Login : ";
	getline (std::cin, this->_login);

    std::cout << "Postal address : ";
	getline (std::cin, this->_postalAddress);

    std::cout << "Email address : ";
	getline (std::cin, this->_emailAddress);

    std::cout << "Phone number : ";
	getline (std::cin, this->_phoneNumber);

    std::cout << "Birthday date : ";
	getline (std::cin, this->_birthdayDate);

    std::cout << "Favorite meal : ";
	getline (std::cin, this->_favoriteMeal);

    std::cout << "Underwear color : ";
	getline (std::cin, this->_underwearColor);

    std::cout << "Darkest secret : ";
	getline (std::cin, this->_darkestSecret);

	std::cout << std::endl;
    std::cout << "Contact '" << this->_login << "' added" << std::endl;
}

void Contact::PrintSearch(void)
{
	if (!this->_firstName.empty() &&
		!this->_lastName.empty() &&
		!this->_nickName.empty())
	{
		std::cout.width(10); std::cout << std::right << this->_id << " | ";
		std::cout.width(10); std::cout << std::right << Contact::Truncate(this->_firstName) << " | ";
		std::cout.width(10); std::cout << std::right << Contact::Truncate(this->_lastName) << " | ";
		std::cout.width(10); std::cout << std::right << Contact::Truncate(this->_nickName);
		std::cout << std::endl;
		this->_isEmpty = 0;
	}
	else
		this->_isEmpty = 1;
}

void Contact::Print(void) const
{
	std::cout.width(10); std::cout << std::right << this->_id << " | ";
	std::cout.width(10); std::cout << std::right << Contact::Truncate(this->_firstName) << " | ";
	std::cout.width(10); std::cout << std::right << Contact::Truncate(this->_lastName) << " | ";
	std::cout.width(10); std::cout << std::right << Contact::Truncate(this->_login) << " | ";
	std::cout <<  std::endl;
	std::cout.width(10); std::cout << std::right << Contact::Truncate(this->_nickName) << " | ";
	std::cout.width(10); std::cout << std::right << Contact::Truncate(this->_postalAddress) << " | ";
	std::cout.width(10); std::cout << std::right << Contact::Truncate(this->_emailAddress) << " | ";
	std::cout.width(10); std::cout << std::right << Contact::Truncate(this->_phoneNumber) << " | ";
	std::cout <<  std::endl;
	std::cout.width(10); std::cout << std::right << Contact::Truncate(this->_birthdayDate) << " | ";
	std::cout.width(10); std::cout << std::right << Contact::Truncate(this->_favoriteMeal) << " | ";
	std::cout.width(10); std::cout << std::right << Contact::Truncate(this->_underwearColor) << " | ";
	std::cout.width(10); std::cout << std::right << Contact::Truncate(this->_darkestSecret);
	std::cout << std::endl;
}

bool Contact::GetIsEmpty(void) const
{
	return this->_isEmpty;
}

int Contact::_nbInstance = 0;

std::string Contact::Truncate(std::string s)
{
	std::string str;

	str = s;
	if (s.length() >= 10) {
		str[9] = '.';
		str.resize(10);
	}
	return str;
}
