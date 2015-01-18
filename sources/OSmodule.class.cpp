/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSmodule.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:33:55 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 03:03:29 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sys/utsname.h>
#include "../headers/OSmodule.class.hpp"

OSmodule::OSmodule( int position ) : _position(position), _name("OS info module") { this->findData(); return ; }
OSmodule::~OSmodule( void ) { return ; }


//getter
int			OSmodule::getPosition( void ) const {
	return this->_position;
}

std::string OSmodule::getData( void ) const {
	return this->_data;
}

std::string OSmodule::getName( void ) const {
	return this->_name;
}

//other
void		OSmodule::findData( void ) {
		struct utsname 	buffer;
		std::string		data;

		uname(&buffer);

		data = "system name = " + static_cast<std::string>(buffer.sysname) + " | node name  = " + static_cast<std::string>(buffer.nodename) +
		 " | release = " + static_cast<std::string>(buffer.release) + " | version = " + static_cast<std::string>(buffer.version) + " | machine = " + static_cast<std::string>(buffer.machine);

		this->_data = data;
		
}