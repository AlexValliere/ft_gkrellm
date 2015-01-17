/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:54:38 by alex              #+#    #+#             */
/*   Updated: 2015/01/17 18:12:12 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include "../headers/Ncurses.class.hpp"

int main(int argc, char const *argv[])
{
	if (argc == 1) {
		/* ncurses */
		std::cout << "ncurses" << std::endl;

		Ncurses		ncurse;

		ncurse.display();
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