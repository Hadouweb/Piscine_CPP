#include "Contact.class.hpp"
#include <iostream>

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
    std::cin >> this->_firstName;

    std::cout << "Last name : ";
    std::cin >> this->_lastName;

    std::cout << "Nickname : ";
    std::cin >> this->_nickName;

    std::cout << "Login : ";
    std::cin >> this->_login;

    std::cout << "Postal address : ";
    std::cin >> this->_postalAddress;

    std::cout << "Email address : ";
    std::cin >> this->_emailAddress;

    std::cout << "Phone number : ";
    std::cin >> this->_phoneNumber;

    std::cout << "Birthday date : ";
    std::cin >> this->_birthdayDate;

    std::cout << "Favorite meal : ";
    std::cin >> this->_favoriteMeal;

    std::cout << "Underwear color : ";
    std::cin >> this->_underwearColor;

    std::cout << "Darkest secret : ";
    std::cin >> this->_darkestSecret;

    std::cout << "Contact '" << this->_login << "' added" << std::endl;
}

void Contact::Print(void)
{
    std::cout << "Index : " << this->_id;
    std::cout << " First name : " << this->_firstName;
    std::cout << " Last name : " << this->_lastName;
    std::cout << " Nickname : " << this->_nickName;
    std::cout << std::endl;
}

int Contact::getNbInstance(void)
{
    return Contact::_nbInstance;
}

int Contact::_nbInstance = 0;