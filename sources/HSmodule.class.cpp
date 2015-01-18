/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HSmodule.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:33:45 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 15:20:00 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <ncurses.h>
#include "../headers/HSmodule.class.hpp"

HSmodule::HSmodule( int position ) : _position(position), _name("Hostname/username module") { this->findData(); return ; }
HSmodule::~HSmodule( void ) { return ; }

HSmodule::HSmodule(HSmodule const & object) {
	*this = object;

	return ;
}

HSmodule&		HSmodule::operator=( HSmodule const & model ) {
	this->_position = model.getPosition();
	this->_data = model.getData();
	this->_name = model.getName();
	this->_hostname = model.getHostname();
	this->_username = model.getUsername();

	return *this;
}

std::string HSmodule::getData( void ) const			{ return this->_data; }
std::string HSmodule::getHostname( void ) const		{ return this->_hostname; }
std::string HSmodule::getName( void ) const			{ return this->_name; }
int			HSmodule::getPosition( void ) const		{ return this->_position; }
std::string HSmodule::getUsername( void ) const		{ return this->_username; }

void		HSmodule::findData( void ) {

	char		hostname[128];
	char 		username[128];
	std::string data;

	gethostname(hostname, sizeof hostname);
	this->_hostname = static_cast<std::string>(hostname);

	data = "Hostname : " + static_cast<std::string>(hostname) + " | ";

	getlogin_r(username, sizeof(username));
	this->_username = static_cast<std::string>(username);

	data = data + "username : " + username;

	this->_data = data;
}

void		HSmodule::addToGtk(GtkWidget* widget) const {
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
	text = "Username : " + this->_username + "\n";
	text += "Hostname : " + this->_hostname;
	pLabel = gtk_label_new(text.c_str());
	gtk_box_pack_start(GTK_BOX(pVBoxFrame), pLabel, TRUE, FALSE, 0);
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
