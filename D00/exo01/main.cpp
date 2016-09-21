#include <iostream>
#include "Contact.class.hpp"



int     main(int ac, char **av)
{
    if (ac > 1)
    {
        Contact c;

        if (strcmp(av[1], "EXIT") == 0)
        {
            std::exit(0);
        }
        else if (strcmp(av[1], "ADD") == 0)
        {

        }
    }

    return 0;
}