/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HSmodule.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:33:45 by hades             #+#    #+#             */
/*   Updated: 2015/01/17 22:56:13 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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