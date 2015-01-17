/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSmodule.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:33:55 by hades             #+#    #+#             */
/*   Updated: 2015/01/17 22:07:04 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../headers/OSmodule.class.hpp"

OSmodule::OSmodule( void ) { return ; }
OSmodule::~OSmodule( void ) { return ; }


//getter
int			OSmodule::getPosition( void ) const {
	return this->_position;
}

std::string OSmodule::getData( void ) const {
	return this->_data;
}