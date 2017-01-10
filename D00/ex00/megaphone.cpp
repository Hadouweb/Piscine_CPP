#include <iostream>

char	get_char(int c) {
	if (c >= 97 && c <= 122) {
		return c - 32;
	}
	return c;
}

int		main(int ac, char **av) {
	int i;
	int j;

	if (ac > 1) 
	{
		i = 1;
		while (av[i] != NULL)
		{
			j = 0;
			while (av[i][j]) 
			{
				std::cout << get_char(av[i][j]);
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	} else {
		std::cout << "* LOUD AND UNBREARABLE FEEDBACK NOISE *" << std::endl;
	}

	return 0;
}