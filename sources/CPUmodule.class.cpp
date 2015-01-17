/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUmodule.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:34:44 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 00:08:33 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <unistd.h>
#include "../headers/CPUmodule.class.hpp"
#include "../headers/usual_functions.hpp"


CPUmodule::CPUmodule( int position ) : _position(position), _name("CPU module") { return ; }
CPUmodule::~CPUmodule( void ) { return ; }

//getter
int			CPUmodule::getPosition( void ) const {
	return this->_position;
}

//other
void		CPUmodule::findData( void ) {
	std::ifstream						fileInput("/proc/cpuinfo");
	std::string							fileLine;
	std::map<std::string, std::string>	cpu_info;
	std::vector<std::string>			cpu_cores_speed;
	std::string							data;
	std::string 						line;
	double								value_t_1 = 0;
	double								value_t_2 = 0;
	double								value_w_1 = 0;
	double								value_w_2 = 0;
	double								value_final_t = 0;
	double								value_final_w = 0;
	double								cpu = 0;
	std::size_t							index;

	while (std::getline(fileInput, fileLine))
	{
		index = fileLine.find("model name");
		if (index != std::string::npos)
		{
			index = fileLine.find(":");
			cpu_info["model_name"] = fileLine.substr(index + 2);
		}

		index = fileLine.find("cpu cores");
		if (index != std::string::npos)
		{
			index = fileLine.find(":");
			cpu_info["cores"] = fileLine.substr(index + 2);
		}

		
		index = fileLine.find("vendor_id");
		if (index != std::string::npos)
		{
			index = fileLine.find(":");
			cpu_info["vendor_id"] = fileLine.substr(index + 2);
		}

		index = fileLine.find("cpu MHz");
		if (index != std::string::npos)
		{
			index = fileLine.find(":");
			cpu_cores_speed.push_back(fileLine.substr(index + 2));
		}
	}

	data =  "CPU name : " + cpu_info["model_name"] + " | ";
	data = data + "CPU vendor ID : " + cpu_info["vendor_id"] + " | ";
	data = data + "CPU cores : " + cpu_info["cores"] + " | ";

	if (atoi(cpu_info["cores"].c_str()) > 0)
	{
		std::vector<std::string>::iterator	it;
		int	coreId = 0;

		for (it = cpu_cores_speed.begin(); it != cpu_cores_speed.end(); it++)
		{
			data =  data + "CPU speed core #" + ft_itoa(coreId) + " : " + *it;
			++coreId;
		}
	}

	std::ifstream			file("/proc/stat");
	if (file) {
		getline(file, line);
	}

	ft_get_value(value_t_1, value_w_1, line);

	std::ifstream			file2("/proc/stat");
	if (file2) {
		getline(file2, line);
	}


	ft_get_value(value_t_2, value_w_2, line);

	value_final_t = value_t_2 - value_t_1;
	value_final_w = value_w_2 - value_w_1;


	cpu = value_final_w / value_final_t * 100;
	if (cpu < 0) {
		cpu = 0;
	}

	data = data + " CPU usage : " + ft_itoa(cpu) + "\%";
	this->_data = data;

	return ;
}

std::string CPUmodule::getData( void ) const {
	return this->_data;
}

std::string CPUmodule::getName( void ) const {
	return this->_name;
}