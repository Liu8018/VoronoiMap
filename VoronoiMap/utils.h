#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <time.h>

#define DEBUG

//测试代码运行时间
class timer {
public:
	clock_t start;
	clock_t end;
	std::string name;
	timer(const std::string& n) {
#ifdef DEBUG
		start = clock();
		name = n;
#endif // DEBUG
	}
	~timer() {
#ifdef DEBUG
		end = clock();
		printf("%s time: %f \n", name.c_str(), (long long(end) - start) * 1.0 / CLOCKS_PER_SEC * 1000);
#endif // DEBUG
	}
};


//输出变量
template <class T>
void log(const T& a)
{
#ifdef DEBUG
	std::cout << a << std::endl;
#endif // DEBUG
}

#endif 
