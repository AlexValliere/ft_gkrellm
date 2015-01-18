/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:56:10 by alex              #+#    #+#             */
/*   Updated: 2015/01/18 03:08:41 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_CLASS_HPP
# define IMONITORMODULE_CLASS_HPP

class IMonitorModule
{
public:
	virtual void 	findData() = 0;
	// virtual	void 	draw( void ) const = 0;
	virtual ~IMonitorModule();
};

#endif