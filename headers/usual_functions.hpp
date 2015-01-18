/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usual_functions.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qde-vial <qde-vial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 23:48:02 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 17:05:26 by qde-vial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USUAL_FUNCTIONS
# define USUAL_FUNCTIONS

#include <iostream>

char			*ft_itoa(int n);
char			*ft_itoa_long(long long n);
void	 		ft_get_value(double & t, double & w, std::string line);

#endif /* USUAL_FUNCTIONS */