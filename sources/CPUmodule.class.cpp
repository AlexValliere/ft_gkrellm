/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUmodule.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:34:44 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 16:28:49 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <fstream>
#include <gtk/gtk.h>
#include <iostream>
#include <map>
#include <ncurses.h>
#include <vector>
#include <unistd.h>
#include "../headers/CPUmodule.class.hpp"
#include "../headers/usual_functions.hpp"


CPUmodule::CPUmodule( int position ) : _position(position), _name("CPU module") { this->findData(); return ; }
CPUmodule::~CPUmodule( void )							{ return ; }

CPUmodule::CPUmodule( CPUmodule const & model )			{ *this = model; return ; }

std::string CPUmodule::getData( void ) const			{ return this->_data; }
std::string CPUmodule::getName( void ) const			{ return this->_name; }
int			CPUmodule::getPosition( void ) const		{ return this->_position; }

std::string	CPUmodule::getCores( void ) const			{ return this->_cores; }
std::string	CPUmodule::getModelName( void ) const		{ return this->_modelName; }
std::string	CPUmodule::getVendorID( void ) const		{ return this->_vendorID; }
std::string CPUmodule::getCPUCoresSpeed( void ) const	{ return this->_CPUCoresSpeed; }

CPUmodule&	CPUmodule::operator=( CPUmodule const & model ) {
	this->_data = model.getData();
	this->_name = model.getName();
	this->_position = model.getPosition();
	this->_cores = model.getCores();
	this->_modelName = model.getModelName();
	this->_vendorID = model.getVendorID();
	this->_CPUCoresSpeed = model.getCPUCoresSpeed();

	return *this;
}

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

	this->_CPUCoresSpeed.clear();

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

	data = data + " CPU usage : " + ft_itoa(cpu) + "\5";
	this->_data = data;

	this->_cores = cpu_info["cores"];
	this->_modelName = cpu_info["model_name"];
	this->_vendorID = cpu_info["vendor_id"];
	this->_CPUCoresSpeed.clear();

	if (atoi(cpu_info["cores"].c_str()) > 0)
	{
		std::vector<std::string>::iterator	it;
		int	i = 1;
		for (it = cpu_cores_speed.begin(); it != cpu_cores_speed.end(); it++)
		{
			if (i != 1 && (i % 2) != 0)
				this->_CPUCoresSpeed += "\n";
			else if (i != 1 && (i % 2) == 0)
				this->_CPUCoresSpeed += "  ";
			this->_CPUCoresSpeed = this->_CPUCoresSpeed + "Core #" + static_cast<std::string>(ft_itoa(i));
			this->_CPUCoresSpeed += " :" + *it + "MHz";
			++i;
		}
	}

	return ;
}

void		CPUmodule::addToGtk(GtkWidget* widget) const {
	std::string	text;
	GtkWidget*	pFrame;
	GtkWidget*	pLabel;
	GtkWidget*	pVBoxFrame;

	/* Creation du premier GtkFrame */
	pFrame = gtk_frame_new(this->_name.c_str());
	gtk_frame_set_shadow_type(GTK_FRAME(pFrame), GTK_SHADOW_ETCHED_OUT);
	gtk_box_pack_start(GTK_BOX(widget), pFrame, FALSE, FALSE, 0);

	/* Creation et insertion d une boite pour le premier GtkFrame */
	pVBoxFrame = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(pFrame), pVBoxFrame);

	/* Creation et insertion des elements contenus dans le premier GtkFrame */
	text = "Model: " + this->_modelName + "\n";
	text += "Vendor ID: " + this->_vendorID + "\n";
	text += "Cores: " + this->_cores + "\n";
	text += this->_CPUCoresSpeed;
	pLabel = gtk_label_new(text.c_str());
	gtk_box_pack_start(GTK_BOX(pVBoxFrame), pLabel, TRUE, FALSE, 0);
}

void		CPUmodule::drawNcurses( int maxWidth ) const {
	int i = 26, j = 0, count = 0;
	if (this->_position == 1) {
		mvprintw(2, 2, this->getName().c_str());
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
		mvprintw(6, 2, this->getName().c_str());
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
		mvprintw(10, 2, this->getName().c_str());
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
		mvprintw(14, 2, this->getName().c_str());
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
		mvprintw(18, 2, this->getName().c_str());
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
