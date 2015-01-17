/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUmodule.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:34:44 by hades             #+#    #+#             */
/*   Updated: 2015/01/17 23:01:40 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../headers/CPUmodule.class.hpp"

CPUmodule::CPUmodule( int position ) : _position(position), _name("CPU module") { return ; }
CPUmodule::~CPUmodule( void ) { return ; }

//getter
int			CPUmodule::getPosition( void ) const {
	return this->_position;
}

//other
void		CPUmodule::findData( void ) {
	

	return ;
}

std::string CPUmodule::getData( void ) const {
	return this->_data;
}

std::string CPUmodule::getName( void ) const {
	return this->_name;
}