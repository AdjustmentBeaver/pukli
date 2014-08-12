#ifndef __UTILS_H__
#define __UTILS_H__

#include <sstream>
#include <iostream>
#include <string>


class LOG {
public:
	template<typename T> LOG& operator<<(const T& value) {
		buffer << value << "\t";
		return *this;
	}

	~LOG() {
		buffer << std::endl;
		std::cerr << buffer.str();
	}

private:
	std::ostringstream buffer;
};

#define LOG LOG()

#endif