#include <iostream>
#include "Contact.class.hpp"


void	search(Contact contactList[8], int size)
{
	int s_id;

	if (size == 0)
	{
		std::cout << std::endl;
		std::cout << "There are no contacts." << std::endl;
		std::cout << std::endl;
		std::cout << "ADD, SEARCH or EXIT" << " : ";
		return ;
	}
	std::cout << std::endl;
	std::cout << "What is the desired index ?" << std::endl;
	std::cin >> s_id;

	if (s_id >= 1 && s_id <= size + 1)
	{
		if (!contactList[s_id - 1].GetIsEmpty())
		{
			contactList[s_id - 1].Print();
			std::cout << std::endl;
			return;
		}
	}

	std::cout << "Sorry the desired contact was not found" << std::endl;
	std::cout << std::endl;
}

int     main(void)
{
    std::string cmd;
    Contact contactList[8];
    int size = 0;

    do
    {
        for(int i = 0; cmd[i]; i++)
            cmd[i] = tolower(cmd[i]);

        if (cmd == "exit")
			std::exit(0);
        else if (cmd == "add")
        {
        	std::cout << std::endl;
        	if (size < 8)
        	{
				contactList[size].Add();
				size++;
			}
			else
				std::cout << "You cannot add more than 8 contacts" << std::endl;
			std::cout << std::endl;
			std::cout << "ADD, SEARCH or EXIT" << " : ";
        }
        else if (cmd == "search")
        {
			std::cout << std::endl;
            for (int i = 0; i < size; i++)
				contactList[i].PrintSearch();
			search(contactList, size);
        }
		else
			std::cout << "ADD, SEARCH or EXIT" << " : ";
    } while (std::getline(std::cin, cmd));

    return 0;
}