/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:54:38 by alex              #+#    #+#             */
/*   Updated: 2015/01/18 18:10:22 by alex             ###   ########.fr       */
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
#include "../headers/Refresh.class.hpp"
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
		HSmodule		host_and_user_names_module(1);
		OSmodule		os_module(2);
		DTmodule		datetime_module(3);
		CPUmodule		cpu_module(4);
		Rmodule			ram_module(5);

		
		Refresh::datetime_module = datetime_module;
		Refresh::host_and_user_names_module = host_and_user_names_module;
		Refresh::os_module = os_module;
		Refresh::cpu_module = cpu_module;
		Refresh::ram_module = ram_module;

		gtk_display.addModule(Refresh::host_and_user_names_module);
		gtk_display.addModule(Refresh::os_module);
		gtk_display.addModule(Refresh::datetime_module);
		gtk_display.addModule(Refresh::cpu_module);
		gtk_display.addModule(Refresh::ram_module);

		gtk_display.display();
	}
	else {
		std::cout << "Usage : ft_gkrellm -g for graphique mode || no parameter for console mode" << std::endl;
	}
	return 0;
}