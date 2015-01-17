#include <ctime>
#include <iostream>

int main()
{
	time_t t = time(0); // get time now
	struct tm * now = localtime( & t );

	std::cout << (now->tm_year + 1900) << '-' 
		<< (now->tm_mon + 1) << '-'
		<< now->tm_mday
		<< std::endl;

	std::cout << (now->tm_hour) << ':' 
		<< (now->tm_min) << ':'
		<< now->tm_sec
		<< std::endl;

	return 0;
}