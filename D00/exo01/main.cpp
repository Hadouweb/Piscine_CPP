#include <iostream>
#include "Contact.class.hpp"

int     main(void)
{
    std::string cmd;
    Contact *contactList[8];
    int size = 0;

    do
    {
        for(int i = 0; cmd[i]; i++)
            cmd[i] = tolower(cmd[i]);

        if (cmd == "exit")
            std::exit(0);
        else if (cmd == "add")
        {
        	if (size < 8)
        	{
				Contact *contact = new Contact;
				contact->Add();
				contactList[size] = contact;
				size++;
			}
			else
				std::cout << "You cannot add more than 8 contacts" << std::endl;
        }
        else if (cmd == "search")
        {
            for (int i = 0; i < size; i++)
                contactList[i]->Print();
        }
        else
            std::cout << "ADD, SEARCH or EXIT" << std::endl << std::endl;

    } while (std::getline(std::cin, cmd));

    return 0;
}