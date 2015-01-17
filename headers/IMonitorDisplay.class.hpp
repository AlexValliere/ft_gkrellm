/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:56:11 by alex              #+#    #+#             */
/*   Updated: 2015/01/17 16:58:19 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_CLASS_HPP
# define IMONITORDISPLAY_CLASS_HPP

class IMonitorDisplay
{
public:
	IMonitorDisplay(void);
	IMonitorDisplay(IMonitorDisplay const & object);
	~IMonitorDisplay();
	
	IMonitorDisplay&	operator=(IMonitorDisplay const & rhs);
};

#endif