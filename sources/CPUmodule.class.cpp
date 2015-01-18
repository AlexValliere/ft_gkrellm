/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUmodule.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qde-vial <qde-vial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:34:44 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 18:36:54 by qde-vial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include "../headers/CPUmodule.class.hpp"
#include "../headers/usual_functions.hpp"


CPUmodule::CPUmodule( int position ) : _position(position), _name("CPU module") { this->findData(); return ; }
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
			data =  data + " [" + *it + "Mhz] ";
			++coreId;
		}
	}

	double								value_t_1 = 0;
	// double								value_t_2 = 0;
	double								value_w_1 = 0;
	// double								value_w_2 = 0;
	double								value_final_t = 0;
	double								value_final_w = 0;
	double								cpu = 0;
	std::ifstream						file("/proc/stat");

	if (file) {
		getline(file, line);
	}

	ft_get_value(value_t_1, value_w_1, line);

	// std::ifstream			file2("/proc/stat");
	// if (file2) {
	// 	getline(file2, line);
	// }


	// ft_get_value(value_t_2, value_w_2, line);

	// value_final_t = value_t_1 - value_t_2;
	// value_final_w = value_w_2 - value_w_1;

	value_final_t = value_t_1;
	value_final_w = value_w_1;



	cpu = value_final_w / value_final_t * 100;
	if (cpu < 0) {
		cpu = 0;
	}

	data = data + " CPU usage : " + ft_itoa_long(cpu) + "\%";
	this->_data = data;

	return ;
}

std::string CPUmodule::getData( void ) const {
	return this->_data;
}

std::string CPUmodule::getName( void ) const {
	return this->_name;
}

void		CPUmodule::drawNcurses( int maxWidth ) const {
	int i = 26, j = 0, count = 0;
	if (this->_position == 1) {
		attron(COLOR_PAIR(2));
		mvprintw(2, 2, this->getName().c_str());
		attroff(COLOR_PAIR(2));
		while (count < 3) {
			while (i < maxWidth && this->_data[j]) {
				mvaddch(1 + count, i, this->_data[j]);
				j++;
				i++;
			}
			i = 26;
			count++;
		}

	}
	else if (this->_position == 2) {
		attron(COLOR_PAIR(2));
		mvprintw(6, 2, this->getName().c_str());
		attroff(COLOR_PAIR(2));
		while (count < 3) {
			while (i < maxWidth && this->_data[j]) {
				mvaddch(5 + count, i, this->_data[j]);
				j++;
				i++;
			}
			i = 26;
			count++;
		}
	}
	else if (this->_position == 3) {
		attron(COLOR_PAIR(2));
		mvprintw(10, 2, this->getName().c_str());
		attroff(COLOR_PAIR(2));
		while (count < 3) {
			while (i < maxWidth && this->_data[j]) {
				mvaddch(9 + count, i, this->_data[j]);
				j++;
				i++;
			}
			i = 26;
			count++;
		}
	}
	else if (this->_position == 4) {
		attron(COLOR_PAIR(2));
		mvprintw(14, 2, this->getName().c_str());
		attroff(COLOR_PAIR(2));
		while (count < 3) {
			while (i < maxWidth && this->_data[j]) {
				mvaddch(13 + count, i, this->_data[j]);
				j++;
				i++;
			}
			i = 26;
			count++;
		}
	}
	else  {
		attron(COLOR_PAIR(2));
		mvprintw(18, 2, this->getName().c_str());
		attroff(COLOR_PAIR(2));
		while (count < 3) {
			while (i < maxWidth && this->_data[j]) {
				mvaddch(17 + count, i, this->_data[j]);
				j++;
				i++;
			}
			i = 26;
			count++;
		}
	}
}
