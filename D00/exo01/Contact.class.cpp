#include "Contact.class.hpp"
#include <iostream>

Contact::Contact(void) { }

Contact::~Contact(void) { }


void Contact::SetFirstName(std::string firstName)
{
    if (this->_firstName == NULL) {
        this->_firstName = firstName;
    }
}

void Contact::SetLastName(std::string lastName)
{
    if (this->-_lastName == NULL) {
        this->_lastName = lastName;
    }
}

void Contact::SetNickName(std::string nickName)
{
    if (this->_nickName == NULL) {
        this->_nickName = nickName;
    }
}

void Contact::SetLogin(std::string login)
{
    if (this->_login == NULL) {
        this->_login = login;
    }
}

void Contact::SetPostalAddress(std::string postalAddress)
{
    if (this->_postalAddress == NULL) {
        this->_postalAddress = postalAddress;
    }
}

void Contact::SetEmailAddress(std::string emailAddress)
{
    if (this->_emailAddress == NULL) {
        this->_emailAddress = emailAddress;
    }
}

void Contact::SetPhoneNumber(std::string phoneNumber)
{
    if (this->_phoneNumber == NULL) {
        this->_phoneNumber = phoneNumber;
    }
}

void Contact::SetBirthdayDate(std::string birthdayDate)
{
    if (this->_birthdayDate == NULL) {
        this->_birthdayDate = birthdayDate;
    }
}

void Contact::SetFavoriteMeal(std::string favoriteMeal)
{
    if (this->_favoriteMeal == NULL) {
        this->_favoriteMeal = favoriteMeal;
    }
}

void Contact::SetUnderwearColor(std::string underwearColor)
{
    if (this->_underwearColor == NULL) {
        this->_underwearColor = underwearColor;
    }
}

void Contact::SetDarkestSecret(std::string darkestSecret)
{
    if (this->_darkestSecret == NULL) {
        this->_darkestSecret = darkestSecret;
    }
}