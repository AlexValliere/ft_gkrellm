/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:54:38 by alex              #+#    #+#             */
/*   Updated: 2015/01/18 15:21:54 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include "../headers/GtkDisplay.class.hpp"
#include "../headers/HSmodule.class.hpp"
#include "../headers/Ncurses.class.hpp"


int main(int argc, char *argv[])
{

	if (argc == 1) {
		/* ncurses */

		Ncurses		ncurse;

		ncurse.display();
	}
	else if (strcmp(argv[1], "-g") == 0) {
		/* graphique */
		std::cout << "graphique" << std::endl;

		GtkDisplay		gtk_display(argc, argv);
		HSmodule		hs_module(1);
		OSmodule		os_module(2);

		gtk_display.addHSModule(hs_module);
		gtk_display.addOSModule(os_module);
		gtk_display.display();
	}
	else {
		std::cout << "Usage : ft_gkrellm -g for graphique mode || no parameter for console mode" << std::endl;
	}
	return 0;
}