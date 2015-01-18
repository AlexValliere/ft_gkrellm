/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rmodule.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:35:05 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 02:24:06 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sys/sysinfo.h>
#include "../headers/Rmodule.class.hpp"
#include "../headers/usual_functions.hpp"

Rmodule::Rmodule( int position ) : _position(position), _name("RAM module") { return ; }
Rmodule::~Rmodule( void ) { return ; }


//getter
int			Rmodule::getPosition( void ) const {
	return this->_position;
}

std::string Rmodule::getData( void ) const {
	return this->_data;
}

std::string Rmodule::getName( void ) const {
	return this->_name;
}

//other
void		Rmodule::findData( void ) {
	/* Conversion constants. */
	const long 			minute = 60;
	const long 			hour = minute * 60;
	const long 			day = hour * 24;
	const double 		megabyte = 1024 * 1024;
	std::string			data;

	/* Obtain system statistics. */
	struct sysinfo si;
	sysinfo (&si);

	/* Summarize interesting values. */
	data = "system uptime : " + static_cast<std::string>(ft_itoa(si.uptime / day)) + " days, " + static_cast<std::string>(ft_itoa((si.uptime % day) / hour)) + static_cast<std::string>(":") + static_cast<std::string>(ft_itoa((si.uptime % hour) / minute)) + static_cast<std::string>(":") + static_cast<std::string>(ft_itoa(si.uptime % minute));
	data = data + " | total RAM : " + static_cast<std::string>(ft_itoa(si.totalram / megabyte)) + "MB | ";
	data = data + "free RAM : " + static_cast<std::string>(ft_itoa(si.freeram / megabyte)) + "MB | ";
	data = data + "process count : " + static_cast<std::string>(ft_itoa(si.procs));

	this->_data = data;

}