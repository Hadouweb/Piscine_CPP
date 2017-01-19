#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array {
public:
    Array<T>(void) {
		this->_data = new T[0];
		this->_len = 0;
    };
    Array<T>(unsigned int n) {
    	this->_data = new T[n]();
    	this->_len = n;
    }

    Array<T>(Array<T> const & src) {
		*this = src;
    };

    ~Array<T>(void) {
    	if (this->_data) {
    		delete [] this->_data;
    	}
    }

    Array<T> & operator=(Array const & rhs) {
		if (this != &rhs) {
			this->_len = rhs.getLen();
			if (this->_data)
				delete [] this->_data;
			this->_data = new T[this->_len];
			unsigned int i;
			for (i = 0; i < this->_len; i++) {
				this->_data[i] = rhs._data[i];
			}
		}
		return *this;
    };

    T & operator[](unsigned int n) const {
    	if (n >= this->getLen() || n < 0) {
			throw std::out_of_range("Index out of limit");
		} else
			return this->_data[n];
    }

	unsigned int getLen(void) const {
		return this->_len;
	};

private:
	T *_data;
	unsigned int _len;
};

#endif