/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DTmodule.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:34:13 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 03:43:25 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
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

void		DTmodule::drawNcurses( int maxWidth ) const {
	int i = 26, j = 0, count = 0;
	if (this->_position == 1) {
		mvprintw(2, 2, this->getName().c_str());
		while (count < 3) {
			while (i < maxWidth && this->_data[j]) {
				mvaddch(1 + count, i, this->_data[j]);
				j++;
				i++;
			}
			i = 26;
			count++;
		}

	}
	else if (this->_position == 2) {
		mvprintw(6, 2, this->getName().c_str());
		while (count < 3) {
			while (i < maxWidth && this->_data[j]) {
				mvaddch(5 + count, i, this->_data[j]);
				j++;
				i++;
			}
			i = 26;
			count++;
		}
	}
	else if (this->_position == 3) {
		mvprintw(10, 2, this->getName().c_str());
		while (count < 3) {
			while (i < maxWidth && this->_data[j]) {
				mvaddch(9 + count, i, this->_data[j]);
				j++;
				i++;
			}
			i = 26;
			count++;
		}
	}
	else if (this->_position == 4) {
		mvprintw(14, 2, this->getName().c_str());
		while (count < 3) {
			while (i < maxWidth && this->_data[j]) {
				mvaddch(13 + count, i, this->_data[j]);
				j++;
				i++;
			}
			i = 26;
			count++;
		}
	}
	else  {
		mvprintw(18, 2, this->getName().c_str());
		while (count < 3) {
			while (i < maxWidth && this->_data[j]) {
				mvaddch(17 + count, i, this->_data[j]);
				j++;
				i++;
			}
			i = 26;
			count++;
		}
	}
}