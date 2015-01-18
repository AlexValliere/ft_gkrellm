/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 12:46:47 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 02:05:55 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* HOSTNAME */

#include <iostream>
#include <unistd.h>
#include <stdlib.h>

int				main( void ) {



	char		hostname[128];

	gethostname(hostname, sizeof hostname);

	std::cout << hostname << std::endl;
	return (0);
}

