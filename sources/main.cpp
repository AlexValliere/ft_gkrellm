/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:54:38 by alex              #+#    #+#             */
/*   Updated: 2015/01/18 02:23:38 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include "../headers/Ncurses.class.hpp"
#include "../headers/CPUmodule.class.hpp"
#include "../headers/DTmodule.class.hpp"
#include "../headers/HSmodule.class.hpp"
#include "../headers/OSmodule.class.hpp"
#include "../headers/Rmodule.class.hpp"

int main(int argc, char const *argv[])
{

	if (argc == 1) {
		/* ncurses */
		CPUmodule    test(1);
		DTmodule	 test2(2);
		HSmodule	 test3(3);
		OSmodule	 test4(4);
		Rmodule	 	 test5(5);

		test.findData();
		test2.findData();
		test3.findData();
		test4.findData();
		test5.findData();
		std::cout << test.getData() << std::endl;
		std::cout << test2.getData() << std::endl;
		std::cout << test3.getData() << std::endl;
		std::cout << test4.getData() << std::endl;
		std::cout << test5.getData() << std::endl;

		// Ncurses		ncurse;

		// ncurse.display();
	}
	else if (strcmp(argv[1], "-g") == 0) {
		/* graphique */
		std::cout << "graphique" << std::endl;
	}
	else {
		std::cout << "Usage : ft_gkrellm -g for graphique mode || no parameter for console mode" << std::endl;
	}
	return 0;
}