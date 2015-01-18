/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DTmodule.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:34:13 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 18:47:17 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include <gtk/gtk.h>
#include "../headers/DTmodule.class.hpp"
#include "../headers/Refresh.class.hpp"
#include "../headers/usual_functions.hpp"

DTmodule::DTmodule( int position ) : _position(position), _name("Date/time module") { this->findData(); return ; }
DTmodule::~DTmodule( void )								{ return ; }

DTmodule::DTmodule( DTmodule const & model )			{ *this = model; return ; }

std::string DTmodule::getData( void ) const				{ return this->_data; }
std::string DTmodule::getName( void ) const				{ return this->_name; }
int			DTmodule::getPosition( void ) const			{ return this->_position; }

std::string DTmodule::getDate( void ) const				{ return this->_date; }
std::string DTmodule::getTime( void ) const				{ return this->_time; }

DTmodule&	DTmodule::operator=( DTmodule const & model ) {
	this->_data = model.getData();
	this->_name = model.getName();
	this->_position = model.getPosition();
	this->_date = model.getDate();
	this->_time = model.getTime();

	return *this;
}


void		DTmodule::findData( void ) {
	std::string    data;
	time_t			t = time(0); // get time now
	struct			tm * now = localtime( & t );

	data = data + ft_itoa((now->tm_year + 1900)) + '-' + ft_itoa((now->tm_mon + 1)) + '-' + ft_itoa(now->tm_mday) + " // ";
	data = data + ft_itoa(now->tm_hour) + ':' + ft_itoa(now->tm_min) + ':' + ft_itoa(now->tm_sec);
	this->_data = data;

	this->_date = static_cast<std::string>( ft_itoa((now->tm_year + 1900)) ) + '-' + static_cast<std::string>( ft_itoa((now->tm_mon + 1)) ) + '-' + static_cast<std::string>( ft_itoa(now->tm_mday) );
	this->_time =  static_cast<std::string>( ft_itoa(now->tm_hour) ) + ':' + static_cast<std::string>( ft_itoa(now->tm_min) ) + ':' + static_cast<std::string>( ft_itoa(now->tm_sec) );
}

void		DTmodule::addToGtk(GtkWidget* widget) const {
	std::string	text;
	GtkWidget*	pFrame;
	GtkWidget*	pVBoxFrame;

	/* Creation du premier GtkFrame */
	pFrame = gtk_frame_new(this->_name.c_str());
	gtk_frame_set_shadow_type(GTK_FRAME(pFrame), GTK_SHADOW_ETCHED_OUT);
	gtk_box_pack_start(GTK_BOX(widget), pFrame, FALSE, FALSE, 0);

	/* Creation et insertion d une boite pour le premier GtkFrame */
	pVBoxFrame = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(pFrame), pVBoxFrame);

	/* Creation et insertion des elements contenus dans le premier GtkFrame */
	text = this->_date + " " + this->_time;
	Refresh::pDatetimeLabel = gtk_label_new(text.c_str());
	gtk_box_pack_start(GTK_BOX(pVBoxFrame), Refresh::pDatetimeLabel, TRUE, FALSE, 0);
}

void		DTmodule::refreshLabel() const {
	std::string	text;

	Refresh::datetime_module.findData();

	text = this->_date + " " + this->_time;

	gtk_label_set_text(GTK_LABEL(Refresh::pDatetimeLabel), text.c_str());
}

void		DTmodule::drawNcurses( int maxWidth ) const {
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