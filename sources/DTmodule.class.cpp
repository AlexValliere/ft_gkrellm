/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DTmodule.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:34:13 by hades             #+#    #+#             */
/*   Updated: 2015/01/17 22:06:25 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../headers/DTmodule.class.hpp"

DTmodule::DTmodule( void ) { return ; }
DTmodule::~DTmodule( void ) { return ; }


//getter
int			DTmodule::getPosition( void ) const {
	return this->_position;
}

std::string DTmodule::getData( void ) const {
	return this->_data;
}