#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {

public:

	int foo;
	char a1;
	char a2;

	Sample(char a1, char a2);
	~Sample(void);

	int f(void) const;

};

#endif