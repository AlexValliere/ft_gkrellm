/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSmodule.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:33:55 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 15:46:53 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sys/utsname.h>
#include <ncurses.h>
#include <gtk/gtk.h>
#include "../headers/OSmodule.class.hpp"

OSmodule::OSmodule( int position ) : _position(position), _name("OS info module") { this->findData(); return ; }
OSmodule::~OSmodule( void )								{ return ; }

OSmodule::OSmodule( OSmodule const & model )			{ *this = model; return ; }

std::string OSmodule::getData( void ) const				{ return this->_data; }
std::string OSmodule::getName( void ) const				{ return this->_name; }
int			OSmodule::getPosition( void ) const			{ return this->_position; }

std::string OSmodule::getArchitecture( void ) const		{ return this->_architecture; }
std::string OSmodule::getReleaseVersion( void ) const	{ return this->_releaseVersion; }
std::string OSmodule::getSystemName( void ) const		{ return this->_systemName; }

OSmodule&	OSmodule::operator=( OSmodule const & model ) {
	this->_data = model.getData();
	this->_name = model.getName();
	this->_position = model.getPosition();
	this->_architecture = model.getArchitecture();
	this->_releaseVersion = model.getReleaseVersion();
	this->_systemName = model.getSystemName();

	return *this;
}

void		OSmodule::findData( void ) {
	struct utsname 	buffer;
	std::string		data;

	uname(&buffer);

	data = "system name = " + static_cast<std::string>(buffer.sysname) + " | node name  = " + static_cast<std::string>(buffer.nodename) +
	 " | release = " + static_cast<std::string>(buffer.release) + " | version = " + static_cast<std::string>(buffer.version) + " | machine = " + static_cast<std::string>(buffer.machine);

	this->_data = data;

	this->_systemName = static_cast<std::string>(buffer.sysname);
	this->_releaseVersion = static_cast<std::string>(buffer.release);
	this->_architecture = static_cast<std::string>(buffer.machine);
}

void		OSmodule::addToGtk(GtkWidget* widget) const {
	std::string	text;
	GtkWidget*	pFrame;
	GtkWidget*	pLabel;
	GtkWidget*	pVBoxFrame;

	/* Creation du premier GtkFrame */
	pFrame = gtk_frame_new(this->_name.c_str());
	gtk_frame_set_shadow_type(GTK_FRAME(pFrame), GTK_SHADOW_ETCHED_OUT);
	gtk_box_pack_start(GTK_BOX(widget), pFrame, FALSE, FALSE, 0);

	/* Creation et insertion d une boite pour le premier GtkFrame */
	pVBoxFrame = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(pFrame), pVBoxFrame);

	/* Creation et insertion des elements contenus dans le premier GtkFrame */
	text = this->_systemName + " " + this->_releaseVersion + " " + this->_architecture;
	pLabel = gtk_label_new(text.c_str());
	gtk_box_pack_start(GTK_BOX(pVBoxFrame), pLabel, TRUE, FALSE, 0);
}

void		OSmodule::drawNcurses( int maxWidth ) const {
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
