/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HSmodule.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:33:45 by hades             #+#    #+#             */
/*   Updated: 2015/01/17 22:07:01 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../headers/HSmodule.class.hpp"

HSmodule::HSmodule( void ) { return ; }
HSmodule::~HSmodule( void ) { return ; }


//getter
int			HSmodule::getPosition( void ) const {
	return this->_position;
}

std::string HSmodule::getData( void ) const {
	return this->_data;
}