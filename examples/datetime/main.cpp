#include <ctime>
#include <iostream>
#include "../../headers/usual_functions.hpp"

int main()
{
	std::string    data;
	time_t t = time(0); // get time now
	struct tm * now = localtime( & t );

	data = ft_itoa(now->tm_year + 1900) + '-' + ft_itoa(now->tm_mon + 1) + '-' + ft_itoa(now->tm_mday) + " // ";

	data = data + ft_atoi(now->tm_hour) + ':' + ft_atoi(now->tm_min) + ':' + ft_atoi(now->tm_sec);

	return 0;
}