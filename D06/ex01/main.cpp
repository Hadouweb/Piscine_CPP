#include <iostream>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

Data * deserialize(void * raw) {
	Data *d = new Data;
	char *ptr = reinterpret_cast<char*>(raw);

	d->n = *reinterpret_cast<int *>(ptr + 8);
	ptr[8] = '\0';
	d->s1 = ptr;
	d->s2 = ptr + 12;

	return d;
}

void * serialize(void) {
	const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *array = new char[20];
	int intValue = rand();
	//std::cout << std::endl << intValue << std::endl;

	for (int i = 0; i < 21; i++) {
		if (i < 8) {
			array[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
			//std::cout << array[i];
		} else if (i >= 8 && i < 12) {
			if (i == 8)
				;//std::cout << std::endl;
			array[i] = (reinterpret_cast<char*>(&intValue))[i - 8];
		} else {
			array[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
			//std::cout << array[i];
		}
	}

	//std::cout << std::endl;
	//std::cout << std::endl;

	return reinterpret_cast<void *>(array);
}

int 	main(void) {
	srand(time(NULL));

	void *ptr = serialize();
	Data *d = deserialize(ptr);

	std::cout << d->n << std::endl;
	std::cout << d->s1 << std::endl;
	std::cout << d->s2 << std::endl;

	return 0;
}