#ifndef PISCINE_CPP_CONTACT_H
# define PISCINE_CPP_CONTACT_H

#include <iostream>

class Contact {

public:

    Contact(void);
    ~Contact(void);

    void 	Add(void);
    void 	PrintSearch(void);
    void 	Print(void) const;
	bool 	GetIsEmpty(void) const;

	static std::string Truncate(std::string s);

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

    static int _nbInstance;
    int _id;
    bool _isEmpty;

};


# endif
