/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rmodule.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:35:05 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 18:46:02 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include "../headers/Refresh.class.hpp"
#include "../headers/Rmodule.class.hpp"
#include "../headers/usual_functions.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <unistd.h>
#include <iostream>
#include <mach/vm_param.h>
#include <sys/gmon.h>
#include <sys/socket.h>
#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>

Rmodule::Rmodule( int position ) : _position(position), _name("RAM module") { this->findData(); return ; }
Rmodule::~Rmodule( void )								{ return ; }

Rmodule::Rmodule( Rmodule const & model )				{ *this = model; return ; }

std::string Rmodule::getData( void ) const				{ return this->_data; }
std::string Rmodule::getName( void ) const				{ return this->_name; }
int			Rmodule::getPosition( void ) const			{ return this->_position; }

std::string Rmodule::getFreeMem( void ) const			{ return this->_freeMem; }
std::string Rmodule::getNbrProcess( void ) const		{ return this->_nbrProcess; }
std::string Rmodule::getTotalMem( void ) const			{ return this->_totalMem; }
std::string Rmodule::getUptime( void ) const			{ return this->_uptime; }

Rmodule&	Rmodule::operator=( Rmodule const & model ) {
	this->_data = model.getData();
	this->_name = model.getName();
	this->_position = model.getPosition();

	this->_freeMem = model.getFreeMem();
	this->_nbrProcess = model.getNbrProcess();
	this->_totalMem = model.getTotalMem();
	this->_uptime = model.getUptime();

	return *this;
}


void		Rmodule::findData( void ) {
    vm_size_t page_size;
    mach_port_t mach_port;
    mach_msg_type_number_t count;
    vm_statistics64_data_t vm_stats;
    std::string		data;

    int mib[2];
	int64_t physical_memory;
	mib[0] = CTL_HW;
	mib[1] = HW_MEMSIZE;
	size_t length = sizeof(int64_t);
	sysctl(mib, 2, &physical_memory, &length, NULL, 0);
	data = "total ram available : " + static_cast<std::string>(ft_itoa_long(physical_memory));

    mach_port = mach_host_self();
    count = sizeof(vm_stats) / sizeof(natural_t);
    if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
        KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
                                        (host_info64_t)&vm_stats, &count))
    {
        long long free_memory = (int64_t)vm_stats.free_count * (int64_t)page_size;

        long long used_memory = ((int64_t)vm_stats.active_count +
                                 (int64_t)vm_stats.inactive_count +
                                 (int64_t)vm_stats.wire_count) *  (int64_t)page_size;

        data = data + " | free memory: " + static_cast<std::string>(ft_itoa_long(free_memory)) + " | used memory : " + static_cast<std::string>(ft_itoa_long(used_memory));
    }

    this->_data = data;

	this->_freeMem = static_cast<std::string>(ft_itoa(si.freeram / megabyte)) + "MB";
	this->_nbrProcess = static_cast<std::string>(ft_itoa(si.procs));
	this->_totalMem = static_cast<std::string>(ft_itoa(si.totalram / megabyte)) + "MB";
	this->_uptime = static_cast<std::string>(ft_itoa(si.uptime / day)) + " days, " + static_cast<std::string>(ft_itoa((si.uptime % day) / hour)) + static_cast<std::string>(":") + static_cast<std::string>(ft_itoa((si.uptime % hour) / minute)) + static_cast<std::string>(":") + static_cast<std::string>(ft_itoa(si.uptime % minute));
}

void		Rmodule::addToGtk(GtkWidget* widget) const {
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
	text = "Total memory : " + this->_totalMem + "\n";
	text += "Free memory : " + this->_freeMem + "\n\n";
	text += "System uptime : " + this->_uptime + "\n";
	text += "Process count : " + this->_nbrProcess;
	Refresh::pMemLabel = gtk_label_new(text.c_str());
	gtk_box_pack_start(GTK_BOX(pVBoxFrame), Refresh::pMemLabel, TRUE, FALSE, 0);
}

void		Rmodule::refreshLabel() const {
	std::string	text;

	Refresh::ram_module.findData();

	text = "Total memory : " + this->_totalMem + "\n";
	text += "Free memory : " + this->_freeMem + "\n\n";
	text += "System uptime : " + this->_uptime + "\n";
	text += "Process count : " + this->_nbrProcess;

	gtk_label_set_text(GTK_LABEL(Refresh::pMemLabel), text.c_str());
}

void		Rmodule::drawNcurses( int maxWidth ) const {
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
