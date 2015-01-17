/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rmodule.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:35:05 by hades             #+#    #+#             */
/*   Updated: 2015/01/17 22:06:45 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../headers/Rmodule.class.hpp"

Rmodule::Rmodule( void ) { return ; }
Rmodule::~Rmodule( void ) { return ; }


//getter
int			Rmodule::getPosition( void ) const {
	return this->_position;
}

std::string Rmodule::getData( void ) const {
	return this->_data;
}