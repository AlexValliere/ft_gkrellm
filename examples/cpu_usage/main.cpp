/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 12:46:47 by hades             #+#    #+#             */
/*   Updated: 2015/01/17 17:30:15 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fstream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <unistd.h>


	/* CPU USAGE */

void	 ft_get_value(double & t, double & w, std::string line) {
	char              		temp[line.size() + 1];
	std::vector<int>		tab;
	int 					i = 0;
	int 					j = 0;
	while (line[i] < 48 || line[i] > 57)
		i++;


	while (line[i]) {
		while (line[i + j] != ' ' && line[i + j]) {
			temp[j] = line[i + j];
			j++;
		}
		tab.push_back(atoi(temp));
		i = i + j + 1;
		j = 0;
	}
	if (tab[0] && tab[1] && tab[2])
		w = tab[0] + tab[1] + tab[2];

	for (unsigned int i = 0; i < tab.size(); i++)
		t = t + tab[i];
}

int				main( void ) {

	std::string 			 line;
	double			value_t_1 = 0;
	double			value_t_2 = 0;
	double			value_w_1 = 0;
	double			value_w_2 = 0;
	double			value_final_t = 0;
	double			value_final_w = 0;
	double			cpu = 0;

	std::ifstream			file("/proc/stat");
	if (file) {
		getline(file, line);
	}

	ft_get_value(value_t_1, value_w_1, line);
	sleep(5);

	std::ifstream			file2("/proc/stat");
	if (file2) {
		getline(file2, line);
	}


	ft_get_value(value_t_2, value_w_2, line);

	value_final_t = value_t_2 - value_t_1;
	value_final_w = value_w_2 - value_w_1;

	// std::cout << "value_final_t :" << value_final_t << " || value_final_w :" << value_final_w << std::endl;   

	cpu = value_final_w / value_final_t * 100;
	if (cpu < 0) {
		cpu = 0;
	}

	std::cout << "CPU usage : " << cpu << "\%" << std::endl;

	// std::cout << "value_t_1 :" << value_t_1 << " || value_w_1 :" << value_w_1 << std::endl;   
	// std::cout << "value_t_2 :" << value_t_2 << " || value_w_2 :" << value_w_2 << std::endl;   

	// for (unsigned int i = 0;i < tab.size(); i++)
		// std::cout << tab[i] << std::endl;

	// std::cout << "i : " << i << std::endl;
	// std::cout << "line[i] : " << line[i] << std::endl;
	// std::cout << line << std::endl;




	return (0);
}