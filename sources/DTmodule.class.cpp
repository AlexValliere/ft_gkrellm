/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DTmodule.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:34:13 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 03:03:14 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../headers/DTmodule.class.hpp"
#include "../headers/usual_functions.hpp"

DTmodule::DTmodule( int position ) : _position(position), _name("Date/time module") { this->findData(); return ; }
DTmodule::~DTmodule( void ) { return ; }


//getter
int			DTmodule::getPosition( void ) const {
	return this->_position;
}

std::string DTmodule::getData( void ) const {
	return this->_data;
}

std::string DTmodule::getName( void ) const {
	return this->_name;
}

//other
void		DTmodule::findData( void ) {
	std::string    data;
	time_t t = time(0); // get time now
	struct tm * now = localtime( & t );

	data = data + ft_itoa((now->tm_year + 1900)) + '-' + ft_itoa((now->tm_mon + 1)) + '-' + ft_itoa(now->tm_mday) + " // ";

	data = data + ft_itoa(now->tm_hour) + ':' + ft_itoa(now->tm_min) + ':' + ft_itoa(now->tm_sec);

	this->_data = data;
}
