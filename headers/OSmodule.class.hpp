/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSmodule.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:42:33 by hades             #+#    #+#             */
/*   Updated: 2015/01/17 22:04:21 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSMODULE_CLASS_HPP
# define OSMODULE_CLASS_HPP

#include <iostream>
#include "IMonitorModule.class.hpp"

class OSmodule : public IMonitorModule
{
public:
			OSmodule( void );
			~OSmodule( void );

// getter
int			getPosition( void ) const;
std::string	getData( void ) const;

private:
	int			_position;
std::string 	_data;

			OSmodule( OSmodule const & model );
OSmodule 	& operator=( OSmodule const & model );
};


#endif /* OSMODULE_CLASS_HPP */