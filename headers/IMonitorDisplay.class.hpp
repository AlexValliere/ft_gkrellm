/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:56:11 by alex              #+#    #+#             */
/*   Updated: 2015/01/17 17:13:09 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_CLASS_HPP
# define IMONITORDISPLAY_CLASS_HPP

class IMonitorDisplay
{
public:
	virtual ~IMonitorDisplay();

	virtual void	display() = 0;
};

#endif