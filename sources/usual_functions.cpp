/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usual_functions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 23:47:29 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 14:25:12 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string.h>
#include "../headers/usual_functions.hpp"

static void		lengths(int n, size_t *len, int *weight)
{
	*len = 1;
	if (n >= 0)
	{
		*len = 0;
		n = -n;
	}
	*weight = 1;
	while (n / *weight < -9)
	{
		*weight *= 10;
		*len += 1;
	}
}

char			*ft_itoa(int n)
{
	size_t		len;
	int			weight;
	size_t		cur;
	char		*str;

	lengths(n, &len, &weight);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	cur = 0;
	if (n < 0)
	{
		str[cur] = '-';
		cur++;
	}
	if (n > 0)
		n = -n;
	while (weight >= 1)
	{
		str[cur++] = -(n / weight % 10) + 48;
		weight /= 10;
	}
	str[cur] = '\0';
	return (str);
}

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