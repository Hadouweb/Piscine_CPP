#ifndef PISCINE_CPP_CONTACT_H
# define PISCINE_CPP_CONTACT_H

#include <iostream>

class Contact {

public:

    Contact(void);
    ~Contact(void);

    void SetFirstName(std::string firstName);
    void SetLastName(std::string lastName);
    void SetNickName(std::string nickName);
    void SetLogin(std::string login);
    void SetPostalAddress(std::string postalAdress);
    void SetEmailAddress(std::string emailAddress);
    void SetPhoneNumber(std::string phoneNumber);
    void SetBirthdayDate(std::string birthdayDate);
    void SetFavoriteMeal(std::string favoriteMeal);
    void SetUnderwearColor(std::string underwearColor);
    void SetDarkestSecret(std::string darkestSecret);

private:

    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _login;
    std::string _postalAddress;
    std::string _emailAddress;
    std::string _phoneNumber;
    std::string _birthdayDate;
    std::string _favoriteMeal;
    std::string _underwearColor;
    std::string _darkestSecret;

};


# endif
