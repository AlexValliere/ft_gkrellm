/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HSmodule.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:33:45 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 03:45:47 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include "../headers/HSmodule.class.hpp"

HSmodule::HSmodule( int position ) : _position(position), _name("Hostname/username module") { this->findData(); return ; }
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

//other
void		HSmodule::findData( void ) {

	char		hostname[128];
	char 		username[128];
	std::string data;

	gethostname(hostname, sizeof hostname);

	data = "Hostname : " + static_cast<std::string>(hostname) + " | ";

	getlogin_r(username, sizeof(username));

	data = data + "username : " + username;

	this->_data = data;
}

void		HSmodule::drawNcurses( int maxWidth ) const {
	int i = 26, j = 0, count = 0;
	if (this->_position == 1) {
		mvprintw(2, 1, this->getName().c_str());
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
		mvprintw(6, 1, this->getName().c_str());
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
		mvprintw(10, 1, this->getName().c_str());
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
		mvprintw(14, 1, this->getName().c_str());
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
		mvprintw(18, 1, this->getName().c_str());
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
