/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 12:46:47 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 14:11:29 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* RAM */

#include <stdio.h>
#include <sys/sysinfo.h>
#include <iostream>

int				main( void ) {

	 /* Conversion constants. */
	 const long minute = 60;
	 const long hour = minute * 60;
	 const long day = hour * 24;
	 const double megabyte = 1024 * 1024;

	 /* Obtain system statistics. */
	 struct sysinfo si;
	 sysinfo (&si);


	 while (42) {
	 	

	 /* Summarize interesting values. */
	 std::cout << "system uptime : " << (si.uptime / day) << " days, " << (si.uptime % day) / hour << ":" << (si.uptime % hour) / minute << ":" << si.uptime % minute << std::endl;
	 std::cout << "total RAM : " << si.totalram / megabyte << "MB" << std::endl;
	 std::cout << "free RAM : " << si.freeram / megabyte << "MB" << std::endl;
	 std::cout << "process count : " << si.procs << std::endl;
	 }

	return (0);
}