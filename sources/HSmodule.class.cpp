/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HSmodule.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:33:45 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 02:03:56 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include "../headers/HSmodule.class.hpp"

HSmodule::HSmodule( int position ) : _position(position), _name("Hostname/username module") { return ; }
HSmodule::~HSmodule( void ) { return ; }


//getter
int			HSmodule::getPosition( void ) const {
	return this->_position;
}

std::string HSmodule::getData( void ) const {
	return this->_data;
}

std::string HSmodule::getName( void ) const {
	return this->_name;
}

//other
void		HSmodule::findData( void ) {

	char		hostname[128];
	char 		username[128];
	std::string data;

	gethostname(hostname, sizeof hostname);

	data = "Hostname : " + static_cast<std::string>(hostname) + " | ";

	getlogin_r(username, sizeof(username));

	data = data + "username : " + username;

	this->_data = data;
}