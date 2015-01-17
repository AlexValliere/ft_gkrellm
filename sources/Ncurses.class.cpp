/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 17:20:26 by alex              #+#    #+#             */
/*   Updated: 2015/01/17 18:12:07 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <unistd.h>
#include "../headers/Ncurses.class.hpp"

Ncurses::Ncurses(void) : _refreshRate(100000)	{ return ; }
Ncurses::~Ncurses()								{ return ; }

Ncurses::Ncurses(Ncurses const & object) {
	*this = object;

	return ;
}

Ncurses&		Ncurses::operator=(Ncurses const & rhs) {
	this->_refreshRate = rhs.getRefreshRate();

	return *this;
}

unsigned int	Ncurses::getRefreshRate() const {
	return this->_refreshRate;
}

void			Ncurses::setRefreshRate(unsigned int newRefreshRate) {
	this->_refreshRate = newRefreshRate;
}

void			Ncurses::display() {
	int		maxHeight, maxWidth;
	int		input = 0;

	initscr();
	keypad(stdscr, true);
	noecho();
	nodelay(stdscr, true);
	curs_set(0);
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	wbkgd(stdscr,COLOR_PAIR(1));
	getmaxyx(stdscr, maxHeight, maxWidth);

	mvprintw(maxHeight - 1, maxWidth - 25, "press esc to exit");

	while ((input = getch()) != 27)
	{
		clear();
		mvprintw(maxHeight - 1, maxWidth - 25, "press esc to exit");

		refresh();
		usleep(this->_refreshRate);
	}

	endwin();

	return ;
}