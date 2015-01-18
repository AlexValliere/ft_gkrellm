/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSmodule.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:33:55 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 14:56:43 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sys/utsname.h>
#include <ncurses.h>
#include "../headers/OSmodule.class.hpp"

OSmodule::OSmodule( int position ) : _position(position), _name("OS info module") { this->findData(); return ; }
OSmodule::~OSmodule( void ) { return ; }


//getter
int			OSmodule::getPosition( void ) const {
	return this->_position;
}

std::string OSmodule::getData( void ) const {
	return this->_data;
}

std::string OSmodule::getName( void ) const {
	return this->_name;
}

//other
void		OSmodule::findData( void ) {
		struct utsname 	buffer;
		std::string		data;

		uname(&buffer);

		data = "system name = " + static_cast<std::string>(buffer.sysname) + " | node name  = " + static_cast<std::string>(buffer.nodename) +
		 " | release = " + static_cast<std::string>(buffer.release) + " | version = " + static_cast<std::string>(buffer.version) + " | machine = " + static_cast<std::string>(buffer.machine);

		this->_data = data;
		
}

void		OSmodule::drawNcurses( int maxWidth ) const {
	int i = 26, j = 0, count = 0;
	if (this->_position == 1) {
		attron(COLOR_PAIR(2));
		mvprintw(2, 2, this->getName().c_str());
		attroff(COLOR_PAIR(2));
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
		attron(COLOR_PAIR(2));
		mvprintw(6, 2, this->getName().c_str());
		attroff(COLOR_PAIR(2));
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
		attron(COLOR_PAIR(2));
		mvprintw(10, 2, this->getName().c_str());
		attroff(COLOR_PAIR(2));
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
		attron(COLOR_PAIR(2));
		mvprintw(14, 2, this->getName().c_str());
		attroff(COLOR_PAIR(2));
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
		attron(COLOR_PAIR(2));
		mvprintw(18, 2, this->getName().c_str());
		attroff(COLOR_PAIR(2));
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
