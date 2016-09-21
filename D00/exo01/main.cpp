#include <iostream>
#include <list>
#include "Contact.class.hpp"

int     main(void)
{
    std::string cmd;
    std::list<Contact*> contactList;

    do
    {
        for(int i = 0; cmd[i]; i++)
        {
            cmd[i] = tolower(cmd[i]);
        }

        if (cmd == "exit")
        {
            std::exit(0);
        }
        else if (cmd == "add")
        {
            Contact *contact = NULL;
            contact = new Contact;
            contact->Add();
            contactList.push_back(contact);
        }
        else if (cmd == "search")
        {
            for (std::list<Contact*>::iterator it = contactList.begin(); it != contactList.end(); it++)
            {
                (*it)->Print();
            }
        }
        else
        {
            std::cout << "ADD, SEARCH or EXIT" << std::endl << std::endl;
        }

    } while (std::getline(std::cin, cmd));

    return 0;
}