/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUmodule.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:42:07 by hades             #+#    #+#             */
/*   Updated: 2015/01/17 22:59:16 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_CLASS_HPP
# define CPUMODULE_CLASS_HPP

#include <iostream>
#include "IMonitorModule.class.hpp"

class CPUmodule : public IMonitorModule
{
public:
			CPUmodule( int position );
			~CPUmodule( void );

// getter
int			getPosition( void ) const;
std::string	getData( void ) const;	
std::string	getName( void ) const;

private:
int				_position;
std::string 	_data;
std::string		_name;

			CPUmodule( void );
			CPUmodule( CPUmodule const & model );
CPUmodule 	& operator=( CPUmodule const & model );
};


#endif /* CPUMODULE_CLASS_HPP */