/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 12:46:47 by hades             #+#    #+#             */
/*   Updated: 2015/01/17 17:31:23 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/utsname.h>

int				main( void ) {
		struct utsname buffer;

		uname(&buffer);

		std::cout << "system name = " << buffer.sysname << std::endl;
		std::cout << "node name  = " << buffer.nodename << std::endl;
		std::cout << "release = " << buffer.release << std::endl;
		std::cout << "version = " << buffer.version << std::endl;
		std::cout << "machine = " << buffer.machine << std::endl;
	return (0);
}

