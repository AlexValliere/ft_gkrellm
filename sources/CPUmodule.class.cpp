/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUmodule.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:34:44 by hades             #+#    #+#             */
/*   Updated: 2015/01/17 22:06:17 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../headers/CPUmodule.class.hpp"

CPUmodule::CPUmodule( void ) { return ; }
CPUmodule::~CPUmodule( void ) { return ; }

//getter
int			CPUmodule::getPosition( void ) const {
	return this->_position;
}

std::string CPUmodule::getData( void ) const {
	return this->_data;
}