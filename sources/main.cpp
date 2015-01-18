/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:54:38 by alex              #+#    #+#             */
/*   Updated: 2015/01/18 16:32:51 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include "../headers/GtkDisplay.class.hpp"
#include "../headers/CPUmodule.class.hpp"
#include "../headers/DTmodule.class.hpp"
#include "../headers/HSmodule.class.hpp"
#include "../headers/OSmodule.class.hpp"
#include "../headers/Rmodule.class.hpp"
// #include "../headers/Ncurses.class.hpp"


int main(int argc, char *argv[])
{

	if (argc == 1) {
		/* ncurses */

		// Ncurses		ncurse;

		// ncurse.display();
	}
	else if (strcmp(argv[1], "-g") == 0) {
		/* graphique */
		std::cout << "graphique" << std::endl;

		GtkDisplay		gtk_display(argc, argv);
		HSmodule		host_and_user_names_module(1);
		OSmodule		os_module(2);
		DTmodule		datetime_module(3);
		CPUmodule		cpu_module(4);
		Rmodule			ram_module(5);

		gtk_display.addModule(host_and_user_names_module);
		gtk_display.addModule(os_module);
		gtk_display.addModule(datetime_module);
		gtk_display.addModule(cpu_module);
		gtk_display.addModule(ram_module);
		gtk_display.display();
	}
	else {
		std::cout << "Usage : ft_gkrellm -g for graphique mode || no parameter for console mode" << std::endl;
	}
	return 0;
}