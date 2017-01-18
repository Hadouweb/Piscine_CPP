#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array {
public:
    Array(void) {
		this->_data = new T;
    };
    Array(unsigned int n) {
    	this->_data = new T[n];
    }

    Array(Array const & src);

    ~Array(void) { }

    Array & operator=(Array const & rhs);

	int getSize(void) const {
		return sizeof(this->_data) / sizeof(T);
	};

private:
	T *_data;
};

#endif